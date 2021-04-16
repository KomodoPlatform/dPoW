/******************************************************************************
 * Copyright © 2014-2018 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

struct dpow_entry *dpow_notaryfind(struct supernet_info *myinfo,struct dpow_block *bp,int32_t height,int32_t *senderindp,uint8_t *senderpub)
{
    int32_t i;
    *senderindp = -1;
    for (i=0; i<bp->numnotaries; i++)
    {
        if ( memcmp(bp->notaries[i].pubkey,senderpub,33) == 0 )
        {
            //printf("matches notary.%d\n",i);
            *senderindp = i;
            return(&bp->notaries[i]);
        }
    }
    return(0);
}

void dpow_utxo2entry(struct dpow_block *bp,struct dpow_entry *ep,struct dpow_utxoentry *up)
{
    int32_t i;
    for (i=0; i<bp->numnotaries; i++)
        bp->notaries[i].othermask |= up->othermasks[i];
    ep->commit = up->commit;
    ep->height = up->height;
    ep->recvmask |= up->recvmask;
    ep->bestk = up->bestk;
    ep->src.prev_hash = up->srchash;
    ep->dest.prev_hash = up->desthash;
    ep->src.prev_vout = up->srcvout;
    ep->dest.prev_vout = up->destvout;
}

void dpow_entry2utxo(struct dpow_utxoentry *up,struct dpow_block *bp,struct dpow_entry *ep)
{
    int32_t i;
    up->commit = bp->commit;
    up->hashmsg = bp->hashmsg;
    up->height = bp->height;
    up->recvmask = bp->recvmask;
    up->bestk = bp->bestk;
    for (i=0; i<bp->numnotaries; i++)
        up->othermasks[i] = bp->notaries[i].recvmask;
    for (i=0; i<33; i++)
        up->pubkey[i] = ep->pubkey[i];
    up->commit = ep->commit;
    up->height = ep->height;
    up->recvmask = ep->recvmask;
    up->bestk = ep->bestk;
    up->srchash = ep->src.prev_hash;
    up->desthash = ep->dest.prev_hash;
    up->srcvout = ep->src.prev_vout;
    up->destvout = ep->dest.prev_vout;
}

int32_t dpow_datahandler(struct supernet_info *myinfo,struct dpow_info *dp,struct dpow_block *bp,uint8_t nn_senderind,uint32_t channel,uint32_t height,uint8_t *data,int32_t datalen)
{
    int32_t i,src_or_dest,myind = -1; bits256 txid,srchash; struct iguana_info *coin; char str[65],str2[65];
    memset(srchash.bytes,0,sizeof(srchash));
    dpow_notaryfind(myinfo,bp,height,&myind,dp->minerkey33);
    if ( myind < 0 )
    {
        //printf("couldnt find myind height.%d | this means your pubkey for this node is not registered and needs to be ratified by majority vote of all notaries\n",height);
        return(-1);
    }
    for (i=0; i<32; i++)
        srchash.bytes[i] = dp->minerkey33[i+1];
    if ( channel == DPOW_TXIDCHANNEL || channel == DPOW_BTCTXIDCHANNEL )
    {
        src_or_dest = (channel == DPOW_BTCTXIDCHANNEL);
        coin = (src_or_dest != 0) ? bp->destcoin : bp->srccoin;
        //printf("bp.%p datalen.%d\n",bp,datalen);
        for (i=0; i<32; i++)
            srchash.bytes[i] = data[i];
        txid = bits256_doublesha256(0,&data[32],datalen-32);
        init_hexbytes_noT(bp->signedtx,&data[32],datalen-32);
        if ( bits256_cmp(txid,srchash) == 0 )
        {
            //printf("verify (%s) it is properly signed! set ht.%d signedtxid to %s\n",coin->symbol,height,bits256_str(str,txid));
            /*if ( channel == DPOW_BTCTXIDCHANNEL )
             {
             if ( bp->state < 1000 )
             {
             bp->desttxid = txid;
             bp->state = 1000;
             dp->destupdated = 0;
             dpow_signedtxgen(myinfo,dp,bp->srccoin,bp,bp->bestk,bp->bestmask,myind,DPOW_SIGCHANNEL,0,bp->isratify);
             //dpow_sigscheck(myinfo,dp,bp,DPOW_SIGCHANNEL,myind,0);
             }
             }
             else
             {
             if ( bp->state != 0xffffffff )
             {
             bp->srctxid = txid;
             printf("set state elapsed %d COMPLETED %s.(%s) %s.(%s)\n",(int32_t)(time(NULL) - bp->starttime),dp->symbol,bits256_str(str,bp->desttxid),dp->dest,bits256_str(str2,txid));
             bp->state = 0xffffffff;
             }
             }*/
        }
        else
        {
            init_hexbytes_noT(bp->signedtx,data,datalen);
            printf("txidchannel txid %s mismatch %s (%s)\n",bits256_str(str,txid),bits256_str(str2,srchash),bp->signedtx);
            bp->signedtx[0] = 0;
        }
    } //else printf("unhandled channel.%x\n",channel);
    return(0);
}

int32_t dpow_checkutxo(struct supernet_info *myinfo,struct dpow_info *dp,struct dpow_block *bp,struct iguana_info *coin,bits256 *txidp,int32_t *voutp,char *coinaddr,char *srccoin)
{
    int32_t haveutxo,completed,minutxo,n; bits256 signedtxid; cJSON *addresses; char *rawtx,*sendtx;
    if ( strcmp("BTC",coin->symbol) == 0 )
    {
        minutxo = 199;
        n = 10;
    }
    else if ( strcmp("KMD",coin->symbol) == 0 )
    {
        minutxo = 512;
        n = 256;
    }
    else
    {
        minutxo = 49;
        n = 50;
    }
    if ( (haveutxo= dpow_haveutxo(myinfo,coin,txidp,voutp,coinaddr,srccoin)) <= minutxo && time(NULL) > dp->lastsplit+bp->duration && (bp->myind != 0 || dp->ratifying == 0) )
    {
        addresses = cJSON_CreateArray();
        jaddistr(addresses,coinaddr);
        if ( myinfo->nosplit == 0 && (rawtx= iguana_utxoduplicates(myinfo,coin,dp->minerkey33,DPOW_UTXOSIZE,n,&completed,&signedtxid,0,addresses)) != 0 )
        {
            if ( (sendtx= dpow_sendrawtransaction(myinfo,coin,rawtx,0)) != 0 )
            {
                printf("sendrawtransaction.(%s)\n",sendtx);
                free(sendtx);
            }
            free(rawtx);
        }
        free_json(addresses);
        dp->lastsplit = (uint32_t)time(NULL);
    }
    if ( bits256_nonz(*txidp) == 0 )
        return(-1);
    return(haveutxo);
}

//uint32_t Numallocated;

int32_t dpow_opreturn_parsesrc(bits256 *blockhashp,int32_t *heightp,bits256 *txidp,char *symbol,bits256 *MoMp,uint32_t *MoMdepthp,uint8_t *opret,int32_t opretlen,struct komodo_ccdataMoMoM
 *mdata)
{
    int32_t i,c,len,offset = 0; uint8_t op;
    symbol[0] = 0;
    memset(blockhashp->bytes,0,sizeof(*blockhashp));
    memset(heightp,0,sizeof(*heightp));
    memset(txidp->bytes,0,sizeof(*txidp));
    memset(MoMp->bytes,0,sizeof(*MoMp));
    memset(MoMdepthp,0,sizeof(*MoMdepthp));
    memset(mdata,0,sizeof(*mdata));
    if ( opret[offset++] == 0x6a )
    {
        if ( (op= opret[offset++]) < 0x4c )
            len = op;
        else if ( op == 0x4c )
            len = opret[offset++];
        else if ( op == 0x4d )
        {
            len = opret[offset++];
            len = len + ((int32_t)opret[offset++] << 8);
        } else return(-1);
        offset += iguana_rwbignum(0,&opret[offset],sizeof(*blockhashp),blockhashp->bytes);
        offset += iguana_rwnum(0,&opret[offset],sizeof(*heightp),(uint32_t *)heightp);
        offset += iguana_rwbignum(0,&opret[offset],sizeof(*txidp),txidp->bytes);
        for (i=0; i<65; i++)
        {
            if ( (c= opret[offset++]) == 0 )
            {
                symbol[i] = 0;
                break;
            }
            if ( offset > opretlen )
                break;
            symbol[i] = c;
        }
        if ( offset+sizeof(bits256)+sizeof(uint32_t) <= opretlen )
        {
            uint32_t CCid,k;
            offset += iguana_rwbignum(0,&opret[offset],sizeof(*MoMp),MoMp->bytes);
            offset += iguana_rwnum(0,&opret[offset],sizeof(*MoMdepthp),(uint32_t *)MoMdepthp);
                // MoMoM, depth, numpairs, (notarization ht, MoMoM offset)
            if ( offset+52 <= opretlen )
            {
                offset += iguana_rwnum(0,&opret[offset],sizeof(CCid),(uint8_t *)&CCid);
                offset += iguana_rwnum(0,&opret[offset],sizeof(uint32_t),(uint8_t *)&mdata->kmdstarti);
                offset += iguana_rwnum(0,&opret[offset],sizeof(uint32_t),(uint8_t *)&mdata->kmdendi);
                offset += iguana_rwbignum(0,&opret[offset],sizeof(mdata->MoMoM),(uint8_t *)&mdata->MoMoM);
                offset += iguana_rwnum(0,&opret[offset],sizeof(uint32_t),(uint8_t *)&mdata->MoMoMdepth);
                offset += iguana_rwnum(0,&opret[offset],sizeof(uint32_t),(uint8_t *)&mdata->numpairs);
                mdata->len += sizeof(mdata->MoMoM) + sizeof(uint32_t)*4;
                if ( offset+mdata->numpairs*8 == opretlen )
                {
                    mdata->pairs = (struct komodo_ccdatapair *)calloc(mdata->numpairs,sizeof(*mdata->pairs));
                    for (k=0; k<mdata->numpairs; k++)
                    {
                        offset += iguana_rwnum(0,&opret[offset],sizeof(int32_t),(uint8_t *)&mdata->pairs[k].notarization_height);
                        offset += iguana_rwnum(0,&opret[offset],sizeof(uint32_t),(uint8_t *)&mdata->pairs[k].MoMoMoffset);
                        mdata->len += sizeof(uint32_t) * 2;
                    }
                } else if ( mdata->numpairs > 0 )
                    printf("offset.%d + %d*8 != opretlen.%d\n",offset,mdata->numpairs,opretlen);
            }
        }
    }
    return(-1);
}

bits256 dpow_calcMoM(uint32_t *MoMdepthp,struct supernet_info *myinfo,struct iguana_info *coin,int32_t height)
{
    bits256 MoM; cJSON *MoMjson,*infojson; int32_t prevMoMheight;
    *MoMdepthp = 0;
    memset(MoM.bytes,0,sizeof(MoM));
    if ( dpow_smallopreturn(coin->symbol) != 0 ) // 80 byte OP_RETURN limit
        return(MoM);
    if ( (infojson= dpow_getinfo(myinfo,coin)) != 0 )
    {
        if ( (prevMoMheight= jint(infojson,"prevMoMheight")) >= 0 )
        {
            if ( prevMoMheight == 0 )
                prevMoMheight = 1;
            *MoMdepthp = (height - prevMoMheight);
            //printf("%s ht.%d prevMoM.%d -> depth %d\n",coin->symbol,height,prevMoMheight,*MoMdepthp);
            if ( *MoMdepthp > 1440*30 )
                *MoMdepthp = 1440*30;
            if ( *MoMdepthp > 0 && (MoMjson= issue_calcMoM(coin,height,*MoMdepthp)) != 0 )
            {
                MoM = jbits256(MoMjson,"MoM");
                free_json(MoMjson);
            }
        }
        free_json(infojson);
    }
    if ( bits256_nonz(MoM) == 0 )
        *MoMdepthp = 0;
    return(MoM);
}

void dpow_statemachinestart(void *ptr)
{
    void **ptrs = ptr;
    struct supernet_info *myinfo; struct dpow_info *dp; struct dpow_checkpoint checkpoint;
    int32_t i,j,ht,extralen,destprevvout0,srcprevvout0,src_or_dest,numratified=0,kmdheight,myind = -1,blockindex=0; uint8_t extras[10000],pubkeys[64][33]; cJSON *ratified=0,*item; struct iguana_info *src,*dest; char *jsonstr,*handle,*hexstr,str[65],str2[65],srcaddr[64],destaddr[64]; bits256 zero,MoM,merkleroot,srchash,destprevtxid0,srcprevtxid0; struct dpow_block *bp; struct dpow_entry *ep = 0; uint32_t MoMdepth,duration,minsigs,starttime,srctime;
    char *destlockunspent=0,*srclockunspent=0,*destunlockunspent=0,*srcunlockunspent=0;
    memset(&zero,0,sizeof(zero));
    static portable_mutex_t dpowT_mutex; 
    portable_mutex_init(&dpowT_mutex);
    MoM = zero;
    srcprevtxid0 = destprevtxid0 = zero;
    srcprevvout0 = destprevvout0 = -1;
    myinfo = ptrs[0];
    dp = ptrs[1];

    char smname[16];
    memset(smname, 0, sizeof(smname));
    snprintf(smname, sizeof(smname)-1, "dpowsm_%s",dp->symbol);
    RenameThread(smname);

    minsigs = (uint32_t)(long)ptrs[2];
    duration = (uint32_t)(long)ptrs[3];
    jsonstr = ptrs[4];
    kmdheight = -1;
    memcpy(&checkpoint,&ptrs[5],sizeof(checkpoint));
    src = iguana_coinfind(dp->symbol);
    dest = iguana_coinfind(dp->dest);
    dpow_getchaintip(myinfo,&merkleroot,&srchash,&srctime,dp->desttx,&dp->numdesttx,dest);
    dpow_getchaintip(myinfo,&merkleroot,&srchash,&srctime,dp->srctx,&dp->numsrctx,src);
    if ( src == 0 || dest == 0 )
    {
        fprintf(stderr, "[---] null coin ptr? (%s %p or %s %p)\n",dp->symbol,src,dp->dest,dest);
        free(ptr);
        return;
    }
    MoMdepth = 0;
    memset(&MoM,0,sizeof(MoM));
    if ( strcmp(src->symbol,"KMD") == 0 )
        kmdheight = checkpoint.blockhash.height;
    else if ( strcmp(dest->symbol,"KMD") == 0 )
    {
        MoM = dpow_calcMoM(&MoMdepth,myinfo,src,checkpoint.blockhash.height);
        kmdheight = dest->longestchain;
    }

    bp = 0; blockindex = -1;

    if (dp)
    {
        int32_t busy_blocks = 0;

        // below is replacement for dpow_heightfind and dpow_blockfind calls, bcz having one loop over dp->maxblocks
        // is better than iterating twice, also we probably need to protect bp search by mutex, to avoid possible
        // rewrite of dp->blocks[i] in other threads at the moment of search

        portable_mutex_lock(&dpowT_mutex);
        for (int32_t i = 0; i < dp->maxblocks; i++)
        {
            if ( dp->blocks[i] != 0 ) {
                busy_blocks++;
                if (checkpoint.blockhash.height == dp->blocks[i]->height) {
                    bp = dp->blocks[i]; // dpow_heightfind
                }
            } else {
                if (blockindex < 0) {
                        blockindex = i; // dpow_blockfind
                    }
            }
        }
        portable_mutex_unlock(&dpowT_mutex);

        fprintf(stderr, "[---] State: sym.%s, dest.%s, blocks.%d/%d (size.%zu)\n", dp->symbol, dp->dest, busy_blocks, dp->maxblocks, sizeof(*bp));
    }

    //if ( (bp= dpow_heightfind(myinfo,dp, checkpoint.blockhash.height)) == 0 )
    if ( bp == 0 )
    {
        //if ( (blockindex= dpow_blockfind(myinfo,dp)) < 0 )
        if ( blockindex < 0 )
        {
            fprintf(stderr, "[---] blockindex == -1\n");
            free(ptr);
            return;
        }

        portable_mutex_lock(&dpowT_mutex);
        bp = calloc(1,sizeof(*bp));
        dp->blocks[blockindex] = bp;
        portable_mutex_unlock(&dpowT_mutex);
        printf("blockindex.%i allocate bp for %s ht.%d -> %s\n",blockindex,src->symbol,checkpoint.blockhash.height,dest->symbol);
        bp->MoM = MoM;
        bp->MoMdepth = MoMdepth;
        bp->CCid = dp->fullCCid & 0xffff;
        bp->minsigs = minsigs;
        bp->duration = duration;
        bp->srccoin = src;
        bp->destcoin = dest;
        bp->myind = -1;
        for (i=0; i<sizeof(bp->notaries)/sizeof(*bp->notaries); i++)
            bp->notaries[i].bestk = -1;
        bp->opret_symbol = dp->symbol;
        if ( jsonstr != 0 && (ratified= cJSON_Parse(jsonstr)) != 0 )
        {
            bp->isratify = 1;
            if ( (numratified= cJSON_GetArraySize(ratified)) > 0 )
            {
                if ( numratified > 64 )
                {
                    fprintf(stderr,"cant ratify more than 64 notaries ratified has %d\n",numratified);
                    portable_mutex_lock(&dpowT_mutex);
                    dp->blocks[blockindex] = 0;
                    bp->state = 0xffffffff;
                    free(bp);
                    portable_mutex_unlock(&dpowT_mutex);
                    free(ptr);
                    return;
                }
                for (i=0; i<numratified; i++)
                {
                    item = jitem(ratified,i);
                    hexstr = handle = 0;
                    if ( (hexstr= jstr(item,"pubkey")) != 0 && is_hexstr(hexstr,0) == 66 )
                    {
                        decode_hex(bp->ratified_pubkeys[i],33,hexstr);
                        for (j=0; j<i; j++)
                            if ( memcmp(bp->ratified_pubkeys[j],bp->ratified_pubkeys[i],33) == 0 )
                            {
                                printf("ratification.%d is the same as %d, reject this donkey\n",j,i);
                                exit(-1);
                            }
                        if ( (handle= jstr(item,"handle")) != 0 )
                            safecopy(bp->handles[i],handle,sizeof(bp->handles[i]));
                        if ( i == 0 )
                        {
                            destprevtxid0 = jbits256(item,"destprevtxid0");
                            destprevvout0 = jint(item,"destprevvout0");
                            srcprevtxid0 = jbits256(item,"srcprevtxid0");
                            srcprevvout0 = jint(item,"srcprevvout0");
                            if ( bits256_nonz(destprevtxid0) != 0 && bits256_nonz(srcprevtxid0) != 0 )
                                bp->require0 = 1;
                        }
                    }
                    else
                    {
                        printf("break loop hexstr.%p handle.%p\n",hexstr,handle);
                        break;
                    }
                }
                if ( i == numratified )
                {
                    bp->numratified = numratified;
                    bp->ratified = ratified;
                    printf("numratified.%d %s\n",numratified,jprint(ratified,0));
                } else printf("i.%d numratified.%d\n",i,numratified);
            }
            free_json(ratified);
        }
        bp->pendingbestk = bp->bestk = -1;
        //dp->blocks[checkpoint.blockhash.height] = bp;
        dp->currentbp = bp;
        bp->beacon = rand256(0);
        vcalc_sha256(0,bp->commit.bytes,bp->beacon.bytes,sizeof(bp->beacon));
    }
    if ( bp->isratify != 0 && dp->ratifying != 0 )
    {
        printf("new ratification starting dp->ratifying.%d\n",dp->ratifying);
        dp->ratifying++;
        while ( dp->ratifying > 1 )
            sleep(3);
        printf("other ratifications stopped\n");
    }
    if ( dp->ratifying != 0 && bp->isratify == 0 )
    {
        printf("skip notarization ht.%d when ratifying\n",bp->height);
        portable_mutex_lock(&dpowT_mutex);
        dp->blocks[blockindex] = 0;
        bp->state = 0xffffffff;
        free(bp);
        portable_mutex_unlock(&dpowT_mutex);
        free(ptr);
        return;
    }
    dp->ratifying += bp->isratify;

	if (strcmp(src->chain->symbol, "ZECTEST") == 0)
		bitcoin_address_ex(src->chain->symbol, srcaddr, 0x1c, src->chain->pubtype, dp->minerkey33, 33);
	else
		bitcoin_address(srcaddr, src->chain->pubtype, dp->minerkey33, 33);

	bitcoin_address(destaddr,dest->chain->pubtype,dp->minerkey33,33);
    if ( kmdheight >= 0 )
    {
        ht = kmdheight;///strcmp("KMD",src->symbol) == 0 ? kmdheight : bp->height;
        if ( strcmp("KMD",dest->symbol) == 0 )
        {
            bp->numnotaries = komodo_notaries(dest->symbol,pubkeys,ht);
        }
        else
        {
            if ( ht == 0 )
                ht = strcmp("KMD",src->symbol) == 0 ? src->longestchain : dest->longestchain;
            bp->numnotaries = komodo_notaries(src->symbol,pubkeys,ht);
        }
        for (i=0; i<bp->numnotaries; i++)
        {
            //int32_t j; for (j=0; j<33; j++)
            //    printf("%02x",pubkeys[i][j]);
            //printf(" <= pubkey[%d]\n",i);
            memcpy(bp->notaries[i].pubkey,pubkeys[i],33);
            if ( strcmp("KMD",src->symbol) == 0 )
                memcpy(myinfo->notaries[i],pubkeys[i],33);
            if ( memcmp(bp->notaries[i].pubkey,dp->minerkey33,33) == 0 )
            {
                myind = i;
                ep = &bp->notaries[myind];
                //for (j=0; j<33; j++)
                //    printf("%02x",dp->minerkey33[j]);
                //printf(" MYIND.%d <<<<<<<<<<<<<<<<<<<<<<\n",myind);
            }
        }
        if ( strcmp("KMD",src->symbol) == 0 )
            myinfo->numnotaries = bp->numnotaries;
        if ( myind < 0 || ep == 0 )
        {
            printf("minerkey33-> ");
            for (i=0; i<33; i++)
                printf("%02x",dp->minerkey33[i]);
            printf(" statemachinestart this node %s %s is not official notary numnotaries.%d kmdht.%d bpht.%d\n",srcaddr,destaddr,bp->numnotaries,kmdheight,bp->height);
            dp->ratifying -= bp->isratify;
            portable_mutex_lock(&dpowT_mutex);
            dp->blocks[blockindex] = 0;
            bp->state = 0xffffffff;
            free(bp);
            portable_mutex_unlock(&dpowT_mutex);
            free(ptr);
            return;
        }
        //printf("myind.%d\n",myind);
    }
    else
    {
        printf("statemachinestart no kmdheight.%d\n",kmdheight);
        dp->ratifying -= bp->isratify;
        portable_mutex_lock(&dpowT_mutex);
        dp->blocks[blockindex] = 0;
        bp->state = 0xffffffff;
        free(bp);
        portable_mutex_unlock(&dpowT_mutex);
        free(ptr);
        return;
    }
    bp->myind = myind;
    printf("[%d] notarize %s->%s %s ht.%d minsigs.%d duration.%d start.%u MoM[%d] %s CCid.%u\n",bp->myind,dp->symbol,dp->dest,bits256_str(str,checkpoint.blockhash.hash),checkpoint.blockhash.height,minsigs,duration,checkpoint.timestamp,bp->MoMdepth,bits256_str(str2,bp->MoM),bp->CCid);
    if ( bp->isratify != 0 && memcmp(bp->notaries[0].pubkey,bp->ratified_pubkeys[0],33) != 0 )
    {
        for (i=0; i<33; i++)
            printf("%02x",bp->notaries[0].pubkey[i]);
        printf(" current vs ");
        for (i=0; i<33; i++)
            printf("%02x",bp->ratified_pubkeys[0][i]);
        printf(" new, cant change notary0\n");
        dp->ratifying -= bp->isratify;
        portable_mutex_lock(&dpowT_mutex);
        dp->blocks[blockindex] = 0;
        bp->state = 0xffffffff;
        free(bp);
        portable_mutex_unlock(&dpowT_mutex);
        free(ptr);
        return;
    }
    //printf(" myind.%d myaddr.(%s %s)\n",myind,srcaddr,destaddr);
    if ( myind == 0 && bits256_nonz(destprevtxid0) != 0 && bits256_nonz(srcprevtxid0) != 0 && destprevvout0 >= 0 && srcprevvout0 >= 0 )
    {
        ep->dest.prev_hash = destprevtxid0;
        ep->dest.prev_vout = destprevvout0;
        ep->src.prev_hash = srcprevtxid0;
        ep->src.prev_vout = srcprevvout0;
        bp->notaries[myind].ratifysrcutxo = srcprevtxid0;
        bp->notaries[myind].ratifysrcvout = srcprevvout0;
        bp->notaries[myind].ratifydestutxo = destprevtxid0;
        bp->notaries[myind].ratifydestvout = destprevvout0;
        printf("Use override utxo %s/v%d %s/v%d\n",bits256_str(str,destprevtxid0),destprevvout0,bits256_str(str2,srcprevtxid0),srcprevvout0);
    }
    else
    {
        if ( dpow_haveutxo(myinfo,bp->destcoin,&ep->dest.prev_hash,&ep->dest.prev_vout,destaddr,src->symbol) > 0 )
        {
            if ( (strcmp("KMD",dest->symbol) == 0 ) && (ep->dest.prev_vout != -1) )
            {
                // lock the dest utxo if destination coin is KMD.
                if (dpow_lockunspent(myinfo,bp->destcoin,destaddr,bits256_str(str2,ep->dest.prev_hash),ep->dest.prev_vout) != 0)
                    printf(">>>> LOCKED %s UTXO.(%s) vout.(%d)\n",dest->symbol,bits256_str(str2,ep->dest.prev_hash),ep->dest.prev_vout);
                else
                    printf("<<<< FAILED TO LOCK %s UTXO.(%s) vout.(%d)\n",dest->symbol,bits256_str(str2,ep->dest.prev_hash),ep->dest.prev_vout);
             }
        }
        if ( dpow_haveutxo(myinfo,bp->srccoin,&ep->src.prev_hash,&ep->src.prev_vout,srcaddr,"") > 0 )
        {
            if ( ( strcmp("KMD",src->symbol) == 0 ) && (ep->src.prev_vout != -1) )
            {
                // lock the src coin selected utxo if the source coin is KMD.
                if (dpow_lockunspent(myinfo,bp->srccoin,srcaddr,bits256_str(str2,ep->src.prev_hash),ep->src.prev_vout) != 0)
                    printf(">>>> LOCKED %s UTXO.(%s) vout.(%d)\n",src->symbol,bits256_str(str2,ep->src.prev_hash),ep->src.prev_vout);
                else
                    printf("<<<< FAILED TO LOCK %s UTXO.(%s) vout.(%d)\n",src->symbol,bits256_str(str2,ep->src.prev_hash),ep->src.prev_vout);
            }
        }
        if ( bp->isratify != 0 )
        {
            bp->notaries[myind].ratifysrcutxo = ep->src.prev_hash;
            bp->notaries[myind].ratifysrcvout = ep->src.prev_vout;
            bp->notaries[myind].ratifydestutxo = ep->dest.prev_hash;
            bp->notaries[myind].ratifydestvout = ep->dest.prev_vout;
        }
        else
        {
            bp->mysrcutxo = ep->src.prev_hash;
            bp->mydestutxo = ep->dest.prev_hash;
        }
    }
    /*if ( strcmp(dp->symbol,"CHIPS") == 0 && myind == 0 )
    {
        char str[65];
        printf(">>>>>>> CHIPS myind.%d %s/v%d\n",myind,bits256_str(str,bp->notaries[myind].src.prev_hash),bp->notaries[myind].src.prev_vout);
        bp->desttxid = bp->notaries[myind].src.prev_hash;
        dpow_signedtxgen(myinfo,dp,src,bp,bp->myind,1LL<<bp->myind,bp->myind,DPOW_SIGCHANNEL,0,0);
    }*/

    bp->recvmask |= (1LL << myind);
    bp->notaries[myind].othermask |= (1LL << myind);
    dp->checkpoint = checkpoint;
    bp->height = checkpoint.blockhash.height;
    bp->timestamp = checkpoint.timestamp;
    bp->hashmsg = checkpoint.blockhash.hash;
    bp->myind = myind;
    while ( bp->isratify == 0 && dp->destupdated == 0 )
    {
        if ( dp->checkpoint.blockhash.height > checkpoint.blockhash.height ) //(checkpoint.blockhash.height % 100) != 0 &&
        {
            //printf("abort %s ht.%d due to new checkpoint.%d\n",dp->symbol,checkpoint.blockhash.height,dp->checkpoint.blockhash.height);
            dp->ratifying -= bp->isratify;
            goto end;
        }
        sleep(1);
    }
    starttime = (uint32_t)time(NULL);
    if ( bp->isratify == 0 )
    {
        bp->starttime = starttime;
        if ( strcmp(bp->destcoin->symbol,"KMD") == 0 )
            src_or_dest = 0;
        else src_or_dest = 1;
        extralen = dpow_paxpending(myinfo,extras,sizeof(extras),&bp->paxwdcrc,bp->MoM,bp->MoMdepth,bp->CCid,src_or_dest,bp);
        bp->notaries[bp->myind].paxwdcrc = bp->paxwdcrc;
    }
    printf("PAXWDCRC.%x myind.%d isratify.%d DPOW.%s statemachine checkpoint.%d %s start.%u+dur.%d vs %ld MoM[%d] %s\n",bp->paxwdcrc,bp->myind,bp->isratify,src->symbol,checkpoint.blockhash.height,bits256_str(str,checkpoint.blockhash.hash),starttime,bp->duration,time(NULL),bp->MoMdepth,bits256_str(str2,bp->MoM));
    for (i=0; i<sizeof(srchash); i++)
        srchash.bytes[i] = dp->minerkey33[i+1];
    //printf("start utxosync start.%u %u\n",starttime,(uint32_t)time(NULL));
    //dpow_utxosync(myinfo,dp,bp,0,myind,srchash);
    //printf("done utxosync start.%u %u\n",starttime,(uint32_t)time(NULL));
    while ( time(NULL) < starttime+bp->duration && src != 0 && dest != 0 && bp->state != 0xffffffff )
    {
        if ( bp->isratify == 0 )
        {
            if ( myinfo->DPOWS[0]->ratifying != 0 )
            {
                printf("break due to already ratifying\n");
                break;
            }
            if ( strcmp(bp->destcoin->symbol,"KMD") == 0 )
                src_or_dest = 0;
            else src_or_dest = 1;
            extralen = dpow_paxpending(myinfo,extras,sizeof(extras),&bp->paxwdcrc,bp->MoM,bp->MoMdepth,bp->CCid,src_or_dest,bp);
            // This is no longer be needed... It can stop notarizations dead if they have not happened for 1440 blocks. 
            //if ( extralen == -1 )
            //    break;
            bp->notaries[bp->myind].paxwdcrc = bp->paxwdcrc;
        }
        if ( dp->checkpoint.blockhash.height > checkpoint.blockhash.height ) //(checkpoint.blockhash.height % 100) != 0 &&
        {
            if ( bp->isratify == 0 )
            {
                //printf("abort %s ht.%d due to new checkpoint.%d\n",dp->symbol,checkpoint.blockhash.height,dp->checkpoint.blockhash.height);
                break;
            }
        }
        if ( dp->ratifying > 1 )
        {
            printf("new ratification started. abort ht.%d\n",bp->height);
            break;
        }
        if ( bp->isratify == 0 )
        {
            bits256 checkhash;
            checkhash = dpow_getblockhash(myinfo,bp->srccoin,bp->height);
            if ( bits256_cmp(checkhash,bp->hashmsg) != 0 )
            {
                printf("%s ht.%d %s got reorged to %s, abort notarization\n",bp->srccoin->symbol,bp->height,bits256_str(str,bp->hashmsg),bits256_str(str2,checkhash));
                break;
            }
        }
        if ( bp->state != 0xffffffff )
        {
            dpow_send(myinfo,dp,bp,srchash,bp->hashmsg,0,bp->height,(void *)"ping",0);
            dpow_nanomsg_update(myinfo);
        }
        else
        {
            dp->lastnotarized = checkpoint.blockhash.hash;
            printf("notarized %s %s\n",dp->symbol,bits256_str(str,checkpoint.blockhash.hash));
        }
        if ( 0 && dp->cancelratify != 0 && bp->isratify != 0 )
        {
            printf("abort pending ratify\n");
            break;
        }
        sleep(30);
    }
    printf("END isratify.%d:%d bestk.%d %llx sigs.%llx state.%x machine ht.%d completed state.%x %s.%s %s.%s recvmask.%llx paxwdcrc.%x %p %p\n",bp->isratify,dp->ratifying,bp->bestk,(long long)bp->bestmask,(long long)(bp->bestk>=0?bp->destsigsmasks[bp->bestk]:0),bp->state,bp->height,bp->state,dp->dest,bits256_str(str,bp->desttxid),dp->symbol,bits256_str(str2,bp->srctxid),(long long)bp->recvmask,bp->paxwdcrc,src,dest);
    dp->lastrecvmask = bp->recvmask;
    dp->ratifying -= bp->isratify;
#if STAKEDTEST
    // We need to wait for notarized confirm here. If the notarization is reorged for any reason we need to rebroadcast it,
    // because the mempool is stupid after the sapling update, or Alright might be playing silly games.
    int8_t dest_confs = 0, src_confs = 0, destnotarized = 0, srcnotarized = 0, firstloop = 0;
    char desttx[32768] = {0}, srctx[32768] = {0};
    while ( destnotarized == 0 || srcnotarized == 0 )
    {
        // If the round was sucessful and both notarization transactions were created successfully we will make sure they are in the chain.
        if ( bits256_cmp(bp->desttxid,zero) == 0 )
            break;
        if ( bits256_cmp(bp->srctxid,zero) == 0 )
            break;
        int8_t send_dest = 0, send_src = 0; char rettx[32768] = {0};
        if ( firstloop == 0 )
        {
            sleep((rand() % (120 - 60)) + 60); 
            firstloop = 1;
        }
        // random sleep here so all nodes are checking/rebroadcasting at diffrent times. 
        sleep((rand() % (77 - 33)) + 33);
        
        // get the confirms for desttxid 
        if ( destnotarized == 0 )
        {
            if ( (dest_confs= dpow_txconfirms(myinfo, bp->destcoin, bp->desttxid, rettx)) != -1 )
            {
                if ( desttx[0] == 0 && rettx[0] != 0 )
                {
                    // save the transaction once we fetch it once, as its possible we wil not be able to always see it.
                    memcpy(desttx, rettx, strlen(rettx)+1);
                }
                if ( dest_confs > 2 )
                {
                    // tx is notarized. or it has 100+ raw confirms. Its now final and cannot be lost, no longer need to check.
                    fprintf(stderr, "[dest.%s] txid.%s is notarized. confirms.%d srcnotarized.%i\n",dp->dest, bits256_str(str,bp->desttxid), dest_confs, srcnotarized);
                    destnotarized = 1;
                }
                else if ( dest_confs == 0 )
                {
                    // not confirmed, rebroadcast it.
                    fprintf(stderr, "[%s] txid.%s is not confirmed rebroadcasting....\n",dp->dest, bits256_str(str,bp->desttxid));
                    if ( desttx[0] != 0 )
                        send_dest = 1;
                }
            } 
            else if ( desttx[0] != 0 ) // we have the tranxation hex saved, and the tx is not in the local mempool or a block, so resend it.
            {
                fprintf(stderr, "[%s] Cant find tx.%s rebroadcasting...\n", dp->dest, bits256_str(str,bp->desttxid));
                send_dest = 1;
            } else fprintf(stderr, "[%s] get raw transaction error\n", dp->dest);
            if ( send_src == 1 )
            {
                char *tmpstr = dpow_sendrawtransaction(myinfo, bp->destcoin, desttx);
                free(tmpstr);
            }    
        }
        
        // get the confirms for srctxid
        memset(rettx,0,sizeof(rettx)); // zero out rettx!
        if ( srcnotarized == 0 )
        {
            if ( (src_confs= dpow_txconfirms(myinfo, bp->srccoin, bp->srctxid, rettx)) != -1 )
            {
                if ( srctx[0] == 0 && rettx[0] != 0 )
                {
                    memcpy(srctx, rettx, strlen(rettx)+1);
                }
                if ( src_confs > 2 )
                {
                    fprintf(stderr, "[src.%s] txid.%s is notarized. confirms.%i destnotarized.%i\n", dp->symbol, bits256_str(str,bp->srctxid), src_confs, destnotarized);
                    srcnotarized = 1;
                }
                else if ( src_confs == 0 )
                {
                    fprintf(stderr, "[%s] txid.%s is not confirmed rebroadcasting....\n", dp->symbol, bits256_str(str,bp->srctxid));
                    if ( srctx[0] != 0 )
                        send_src = 1;
                }
            }
            else if ( srctx[0] != 0 )
            {
                fprintf(stderr, "[%s] Cant find tx.%s rebroadcasting...\n", dp->symbol, bits256_str(str,bp->srctxid));
                send_src = 1;
            } else fprintf(stderr, "[%s] get raw transaction error\n", dp->symbol);
            if ( send_src == 1 )
            {
                char *tmpstr = dpow_sendrawtransaction(myinfo, bp->srccoin, srctx);
                free(tmpstr);
            }
        }
    }
#endif
end:
    // unlock the dest utxo on KMD.
    if ( ep != 0 && strcmp("KMD",dest->symbol) == 0  && ep->dest.prev_vout != -1 )
    {
      if ( dpow_unlockunspent(myinfo,bp->destcoin,destaddr,bits256_str(str2,ep->dest.prev_hash),ep->dest.prev_vout) != 0 )
        printf(">>>> UNLOCKED %s UTXO.(%s) vout.(%d)\n",dest->symbol,bits256_str(str2,ep->dest.prev_hash),ep->dest.prev_vout);
    }
    // unlock the src selected utxo on KMD.
    if ( ep != 0 && strcmp("KMD",src->symbol) == 0  && ep->src.prev_vout != -1 )
    {
      if ( dpow_unlockunspent(myinfo,bp->srccoin,srcaddr,bits256_str(str2,ep->src.prev_hash),ep->src.prev_vout) != 0)
        printf(">>>> UNLOCKED %s UTXO.(%s) vout.(%d)\n",src->symbol,bits256_str(str2,ep->src.prev_hash),ep->src.prev_vout);
    }
    portable_mutex_lock(&dpowT_mutex);
    dp->blocks[blockindex] = 0;
    bp->state = 0xffffffff;
    free(bp);
    portable_mutex_unlock(&dpowT_mutex);
    free(ptr);
}
