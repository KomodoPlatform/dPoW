
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
//
//  LP_coins.c
//  marketmaker
//

char *portstrs[][3] = { { "BTC", "8332" }, { "KMD", "7771" } };

int32_t LP_is_slowcoin(char *symbol)
{
    if ( strcmp(symbol,"BTC") == 0 )
        return(2);
    else if ( strcmp(symbol,"BCH") == 0 )
        return(1);
    else if ( strcmp(symbol,"BTG") == 0 )
        return(1);
    else if ( strcmp(symbol,"SBTC") == 0 )
        return(1);
    else return(0);
}

uint16_t LP_rpcport(char *symbol)
{
    int32_t i;
    if ( symbol != 0 && symbol[0] != 0 )
    {
        for (i=0; i<sizeof(portstrs)/sizeof(*portstrs); i++)
            if ( strcmp(portstrs[i][0],symbol) == 0 )
                return(atoi(portstrs[i][1]));
    }
    return(0);
}

uint16_t LP_busport(uint16_t rpcport)
{
    if ( rpcport == 8332 )
        return(8334); // BTC
    else if ( rpcport < (1 << 15) )
        return(65535 - rpcport);
    else return(rpcport+1);
}

char *parse_conf_line(char *line,char *field)
{
    line += strlen(field);
    for (; *line!='='&&*line!=0; line++)
        break;
    if ( *line == 0 )
        return(0);
    if ( *line == '=' )
        line++;
    while ( line[strlen(line)-1] == '\r' || line[strlen(line)-1] == '\n' || line[strlen(line)-1] == ' ' )
        line[strlen(line)-1] = 0;
    //printf("LINE.(%s)\n",line);
    _stripwhite(line,0);
    return(clonestr(line));
}

uint16_t LP_userpassfp(char *symbol,char *username,char *password,FILE *fp)
{
    char *rpcuser,*rpcpassword,*str,line[8192]; uint16_t port = 0;
    rpcuser = rpcpassword = 0;
    username[0] = password[0] = 0;
    while ( fgets(line,sizeof(line),fp) != 0 )
    {
        if ( line[0] == '#' )
            continue;
        //printf("line.(%s) %p %p\n",line,strstr(line,(char *)"rpcuser"),strstr(line,(char *)"rpcpassword"));
        if ( (str= strstr(line,(char *)"rpcuser")) != 0 )
            rpcuser = parse_conf_line(str,(char *)"rpcuser");
        else if ( (str= strstr(line,(char *)"rpcpassword")) != 0 )
            rpcpassword = parse_conf_line(str,(char *)"rpcpassword");
        else if ( (str= strstr(line,(char *)"rpcport")) != 0 )
        {
            str = parse_conf_line(str,(char *)"rpcport");
            if ( str != 0 )
            {
                port = atoi(str);
                printf("found RPCPORT.%u\n",port);
                free(str);
            }
        }
    }
    if ( rpcuser != 0 && rpcpassword != 0 )
    {
        strcpy(username,rpcuser);
        strcpy(password,rpcpassword);
    }
    //printf("%s rpcuser.(%s) rpcpassword.(%s)\n",symbol,rpcuser,rpcpassword);
    if ( rpcuser != 0 )
        free(rpcuser);
    if ( rpcpassword != 0 )
        free(rpcpassword);
    return(port);
}

void LP_statefname(char *fname,char *symbol,char *assetname,char *str,char *name,char *confpath)
{
    if ( confpath != 0 && confpath[0] != 0 )
    {
		#if defined(NATIVE_WINDOWS)
		// need to do something with "confpath":"`${process.env.HOME}`/.muecore/mue.conf" under Windows
		char *ht = "`${process.env.USERHOME}`", *ht_start, *p_ht;
		char ht_symbol[2];
		
		ht_start = strstr(confpath, ht);

		if (ht_start) {
			ht_start = ht_start + strlen(ht);
			sprintf(fname, "%s\\", LP_getdatadir());
			p_ht = ht_start;
			if (p_ht[0] == '/' && p_ht[1] == '.') {
				p_ht += 2;
				//printf("%s\n", p_ht);
				while (p_ht[0] != '\0') {
					if (p_ht[0] == '/') strcat(fname, "\\"); else
					{
						ht_symbol[0] = p_ht[0]; ht_symbol[1] = '\0';
						strcat(fname, ht_symbol);
					}
					p_ht++;
				}
				//printf("%s\n", fname);
			}
		} else strcpy(fname, confpath);
		#else
		strcpy(fname,confpath);
		#endif	
        return;
    }
    sprintf(fname,"%s",LP_getdatadir());
#ifdef _WIN32
    strcat(fname,"\\");
#else
    strcat(fname,"/");
#endif
    if ( strcmp(symbol,"BTC") == 0 )
    {
#if defined(__APPLE__) || defined(NATIVE_WINDOWS)
        strcat(fname,"Bitcoin");
#else
        strcat(fname,".bitcoin");
#endif
    }
    else if ( name != 0 )
    {
        char name2[64];
#if defined(__APPLE__) || defined(NATIVE_WINDOWS)
        int32_t len;
        strcpy(name2,name);
        name2[0] = toupper(name2[0]);
        len = (int32_t)strlen(name2);
        if ( strcmp(&name2[len-4],"coin") == 0 )
            name2[len - 4] = 'C';
#else
        name2[0] = '.';
        strcpy(name2+1,name);
#endif
       strcat(fname,name2);
    }
    else
    {
#if defined(__APPLE__) || defined(NATIVE_WINDOWS)
        strcat(fname,"Komodo");
#else
        strcat(fname,".komodo");
#endif
        if ( strcmp(symbol,"KMD") != 0 )
        {
#ifdef _WIN32
            strcat(fname,"\\");
#else
            strcat(fname,"/");
#endif
            strcat(fname,assetname);
        }
    }
#ifdef _WIN32
    strcat(fname,"\\");
#else
    strcat(fname,"/");
#endif
    strcat(fname,str);
}

uint16_t LP_userpass(char *userpass,char *symbol,char *assetname,char *confroot,char *name,char *confpath,uint16_t origport)
{
    FILE *fp; char fname[512],username[512],password[512],confname[512]; uint16_t port = 0;
    userpass[0] = 0;
    sprintf(confname,"%s.conf",confroot);
    if ( 0 )
        printf("%s (%s) %s confname.(%s) confroot.(%s)\n",symbol,assetname,name,confname,confroot);
#if defined(__APPLE__) || defined(NATIVE_WINDOWS)
    int32_t len;
    confname[0] = toupper(confname[0]);
    len = (int32_t)strlen(confname);
    if ( strcmp(&confname[len-4],"coin") == 0 )
        confname[len - 4] = 'C';
#endif
    LP_statefname(fname,symbol,assetname,confname,name,confpath);
    if ( (fp= fopen(fname,"rb")) != 0 )
    {
        if ( (port= LP_userpassfp(symbol,username,password,fp)) == 0 )
            port = origport;
        sprintf(userpass,"%s:%s",username,password);
        fclose(fp);
        if ( 0 )
            printf("LP_statefname.(%s) <- %s %s %s (%s) (%s)\n",fname,name,symbol,assetname,userpass,confpath);
        return(port);
    } else printf("cant open.(%s)\n",fname);
    return(origport);
}

cJSON *LP_coinjson(struct iguana_info *coin,int32_t showwif)
{
    struct electrum_info *ep; bits256 zero; int32_t notarized; uint64_t balance; char wifstr[128],ipaddr[72]; uint8_t tmptype; bits256 checkkey; cJSON *item = cJSON_CreateObject();
    jaddstr(item,"coin",coin->symbol);
    if ( showwif != 0 )
    {
        bitcoin_priv2wif(coin->symbol,coin->wiftaddr,wifstr,G.LP_privkey,coin->wiftype);
        bitcoin_wif2priv(coin->symbol,coin->wiftaddr,&tmptype,&checkkey,wifstr);
        if ( bits256_cmp(G.LP_privkey,checkkey) == 0 )
            jaddstr(item,"wif",wifstr);
        else jaddstr(item,"wif","error creating wif");
    }
    jadd(item,"installed",coin->userpass[0] == 0 ? jfalse() : jtrue());
    if ( coin->userpass[0] != 0 )
    {
        jaddnum(item,"height",LP_getheight(&notarized,coin));
        if ( notarized > 0 )
            jaddnum(item,"notarized",notarized);
        if ( coin->electrum != 0 )
            balance = LP_unspents_load(coin->symbol,coin->smartaddr);
        else balance = LP_RTsmartbalance(coin);
        jaddnum(item,"balance",dstr(balance));
        jaddnum(item,"KMDvalue",dstr(LP_KMDvalue(coin,balance)));
    }
#ifndef NOTETOMIC
    else if (coin->etomic[0] != 0) {
        int error = 0;
        if (coin->inactive == 0) {
            balance = LP_etomic_get_balance(coin, coin->smartaddr, &error);
        } else {
            balance = 0;
        }
        jaddnum(item,"height",-1);
        jaddnum(item,"balance",dstr(balance));
    }
#endif
    else
    {
        jaddnum(item,"height",-1);
        jaddnum(item,"balance",0);
    }
    if ( coin->inactive != 0 )
    {
        jaddstr(item,"status","inactive");
    }
    else jaddstr(item,"status","active");
    if ( coin->isPoS != 0 )
        jaddstr(item,"type","PoS");
    if ( (ep= coin->electrum) != 0 )
    {
        sprintf(ipaddr,"%s:%u",ep->ipaddr,ep->port);
        jaddstr(item,"electrum",ipaddr);
    }
    jaddstr(item,"smartaddress",coin->smartaddr);
    jaddstr(item,"rpc",coin->serverport);
    jaddnum(item,"pubtype",coin->pubtype);
    jaddnum(item,"p2shtype",coin->p2shtype);
    jaddnum(item,"wiftype",coin->wiftype);
    jaddnum(item,"txfee",strcmp(coin->symbol,"BTC") != 0 ? coin->txfee : LP_txfeecalc(coin,0,0));
    if ( strcmp(coin->symbol,"KMD") == 0 )
    {
        memset(zero.bytes,0,sizeof(zero));
        if ( strcmp(coin->smartaddr,coin->instantdex_address) != 0 )
        {
            LP_instantdex_depositadd(coin->smartaddr,zero);
            strcpy(coin->instantdex_address,coin->smartaddr);
        }
        jaddnum(item,"zcredits",dstr(LP_myzcredits()));
        jadd(item,"zdebits",LP_myzdebits());
    }
    return(item);
}

struct iguana_info *LP_conflicts_find(struct iguana_info *refcoin)
{
    struct iguana_info *coin=0,*tmp; int32_t n;
    if ( refcoin != 0 && (n= (int32_t)strlen(refcoin->serverport)) > 3 && strcmp(":80",&refcoin->serverport[n-3]) != 0 )
    {
        HASH_ITER(hh,LP_coins,coin,tmp)
        {
            if ( coin->inactive != 0 || coin->electrum != 0 || coin == refcoin )
                continue;
            if ( strcmp(coin->serverport,refcoin->serverport) == 0 )
                break;
        }
    }
    return(coin);
}

cJSON *LP_coinsjson(int32_t showwif)
{
    struct iguana_info *coin,*tmp; cJSON *array = cJSON_CreateArray();
    HASH_ITER(hh,LP_coins,coin,tmp)
    {
        jaddi(array,LP_coinjson(coin,showwif));
    }
    return(array);
}

char *LP_getcoin(char *symbol)
{
    int32_t numenabled,numdisabled; struct iguana_info *coin,*tmp; cJSON *item=0,*retjson;
    retjson = cJSON_CreateObject();
    if ( symbol != 0 && symbol[0] != 0 )
    {
        numenabled = numdisabled = 0;
        HASH_ITER(hh,LP_coins,coin,tmp)
        {
            if ( strcmp(symbol,coin->symbol) == 0 )
                item = LP_coinjson(coin,LP_showwif);
            if ( coin->inactive == 0 )
                numenabled++;
            else numdisabled++;
        }
        jaddstr(retjson,"result","success");
        jaddnum(retjson,"enabled",numenabled);
        jaddnum(retjson,"disabled",numdisabled);
        if ( item == 0 )
            item = cJSON_CreateObject();
        jadd(retjson,"coin",item);
    }
    return(jprint(retjson,1));
}

struct iguana_info *LP_coinsearch(char *symbol)
{
    struct iguana_info *coin = 0;
    if ( symbol != 0 && symbol[0] != 0 )
    {
        portable_mutex_lock(&LP_coinmutex);
        HASH_FIND(hh,LP_coins,symbol,strlen(symbol),coin);
        portable_mutex_unlock(&LP_coinmutex);
    }
    return(coin);
}

struct iguana_info *LP_coinadd(struct iguana_info *cdata)
{
    struct iguana_info *coin = calloc(1,sizeof(*coin));
    *coin = *cdata;
    portable_mutex_init(&coin->txmutex);
    portable_mutex_init(&coin->addrmutex);
    portable_mutex_init(&coin->addressutxo_mutex);
    portable_mutex_init(&coin->tx_history_mutex);
    portable_mutex_lock(&LP_coinmutex);
    HASH_ADD_KEYPTR(hh,LP_coins,coin->symbol,strlen(coin->symbol),coin);
    portable_mutex_unlock(&LP_coinmutex);
    strcpy(coin->validateaddress,"validateaddress");
    strcpy(coin->getinfostr,"getinfo");
    strcpy(coin->estimatefeestr,"estimatefee");
    return(coin);
}

void *curl_easy_init();
uint16_t LP_coininit(struct iguana_info *coin,char *symbol,char *name,char *assetname,int32_t isPoS,uint16_t port,uint8_t pubtype,uint8_t p2shtype,uint8_t wiftype,uint64_t txfee,double estimatedrate,int32_t longestchain,uint8_t wiftaddr,uint8_t taddr,uint16_t busport,char *confpath,uint8_t decimals,uint32_t txversion)
{
    static void *ctx;
    char *name2; uint16_t origport = port;
    memset(coin,0,sizeof(*coin));
    safecopy(coin->symbol,symbol,sizeof(coin->symbol));
    coin->updaterate = (uint32_t)time(NULL);
    coin->isPoS = isPoS;
    coin->taddr = taddr;
    coin->wiftaddr = wiftaddr;
    coin->longestchain = longestchain;
    if ( (coin->txfee= txfee) > 0 && txfee < LP_MIN_TXFEE )
        coin->txfee = LP_MIN_TXFEE;
    coin->pubtype = pubtype;
    coin->p2shtype = p2shtype;
    coin->wiftype = wiftype;
    coin->inactive = (uint32_t)time(NULL);
    //coin->bussock = LP_coinbus(busport);
    if ( ctx == 0 )
        ctx = bitcoin_ctx();
    coin->ctx = ctx;
    if ( assetname != 0 && strcmp(name,assetname) == 0 )
    {
        //printf("%s is assetchain\n",symbol);
        // if ( strcmp(name,"BEER") != 0 && strcmp("PIZZA",name) != 0 )
            coin->isassetchain = 1;
    }
    if ( strcmp(symbol,"KMD") == 0 || (assetname != 0 && assetname[0] != 0) )
        name2 = 0;
    else name2 = name;
    if ( strcmp(symbol,"XVG") == 0 || strcmp(symbol,"CLOAK") == 0 || strcmp(symbol,"PPC") == 0 || strcmp(symbol,"BCC") == 0 || strcmp(symbol,"ORB") == 0 )
    {
        coin->noimportprivkey_flag = 1;
        printf("truncate importprivkey for %s\n",symbol);
    }
#ifndef FROM_JS
    port = LP_userpass(coin->userpass,symbol,assetname,name,name2,confpath,port);
#endif
    sprintf(coin->serverport,"127.0.0.1:%u",port);
    if ( port != origport )
        printf("set curl path for %s to %s\n",symbol,coin->serverport);
    if ( strcmp(symbol,"KMD") == 0 || strcmp(symbol,"BEER") == 0 || strcmp(symbol,"PIZZA") == 0 || coin->isassetchain != 0 || taddr != 0 )
        coin->zcash = LP_IS_ZCASHPROTOCOL;
    else if ( strcmp(symbol,"BCH") == 0 )
    {
        coin->zcash = LP_IS_BITCOINCASH;
        //printf("set coin.%s <- LP_IS_BITCOINCASH %d\n",symbol,coin->zcash);
    }
    else if ( strcmp(symbol,"BTG") == 0 )
    {
        coin->zcash = LP_IS_BITCOINGOLD;
        printf("set coin.%s <- LP_IS_BITCOINGOLD %d\n",symbol,coin->zcash);
    }
    else if ( strcmp(symbol,"CMM") == 0 )
    {
        coin->zcash = LP_IS_BITCOINCASH;
        //printf("set coin.%s <- LP_IS_BITCOINCASH %d\n",symbol,coin->zcash);
    }
    coin->curl_handle = curl_easy_init();
    portable_mutex_init(&coin->curl_mutex);
    coin->decimals = decimals;
    if ( strcmp(symbol,"PART") == 0 ) {
        coin->txversion = 160;
    } else if ( coin->isassetchain != 0 && strcmp(symbol,"OOT") != 0 && strcmp(symbol,"ZILLA") != 0 ) {
        coin->txversion = 4;
    } else if ( strcmp(name,"BEER") == 0 || strcmp("PIZZA",name) == 0 || strcmp("KMD",name) == 0 ) {
        coin->txversion = 4;
    } else {
        coin->txversion = txversion;
    }
    return(port);
}

int32_t LP_isdisabled(char *base,char *rel)
{
    struct iguana_info *coin;
    if ( base != 0 && (coin= LP_coinsearch(base)) != 0 && coin->inactive != 0 )
        return(1);
    else if ( rel != 0 && (coin= LP_coinsearch(rel)) != 0 && coin->inactive != 0 )
        return(1);
    else return(0);
}

struct iguana_info *LP_coinfind(char *symbol)
{
    struct iguana_info *coin,cdata; int32_t txversion=0,isinactive,isPoS,longestchain = 1; uint16_t port,busport; uint64_t txfee; double estimatedrate; uint8_t pubtype,p2shtype,wiftype; char *name,*assetname;
    if ( symbol == 0 || symbol[0] == 0 )
        return(0);
    if ( (coin= LP_coinsearch(symbol)) != 0 )
        return(coin);
    if ( (port= LP_rpcport(symbol)) == 0 )
        return(0);
    if ( (busport= LP_busport(port)) == 0 )
        return(0);
    isPoS = 0;
    txfee = LP_MIN_TXFEE;
    estimatedrate = 20;
    pubtype = 60;
    p2shtype = 85;
    wiftype = 188;
    assetname = "";
    if ( strcmp(symbol,"BTC") == 0 )
    {
        txfee = 0;
        estimatedrate = 300;
        pubtype = 0;
        p2shtype = 5;
        wiftype = 128;
        name = "bitcoin";
    }
    else if ( strcmp(symbol,"KMD") == 0 )
    {
        name = "komodo";
        txversion = 4;
    }
    else return(0);
    port = LP_coininit(&cdata,symbol,name,assetname,isPoS,port,pubtype,p2shtype,wiftype,txfee,estimatedrate,longestchain,0,0,busport,0,0,txversion);
    if ( port == 0 )
        isinactive = 1;
    else isinactive = 0;
    if ( (coin= LP_coinadd(&cdata)) != 0 )
    {
        coin->inactive = isinactive * (uint32_t)time(NULL);
        /*if ( strcmp(symbol,"KMD") == 0 )
            coin->inactive = 0;
        else*/ if ( strcmp(symbol,"BTC") == 0 )
        {
            coin->inactive = (uint32_t)time(NULL) * !IAMLP;
            printf("BTC inactive.%u\n",coin->inactive);
        }
    }
    return(coin);
}

// "coins":[{"coin":"<assetchain>", "rpcport":pppp}, {"coin":"LTC", "name":"litecoin", "rpcport":9332, "pubtype":48, "p2shtype":5, "wiftype":176, "txfee":100000 }]

struct iguana_info *LP_coincreate(cJSON *item)
{
    struct iguana_info cdata,*coin=0; int32_t isPoS,longestchain = 1; uint16_t port; uint64_t txfee; double estimatedrate; uint8_t pubtype,p2shtype,wiftype; char *name=0,*symbol,*assetname=0;
    if ( (symbol= jstr(item,"coin")) != 0 && symbol[0] != 0 && strlen(symbol) < 16 && LP_coinfind(symbol) == 0 && (port= juint(item,"rpcport")) != 0 )
    {
        isPoS = jint(item,"isPoS");
        txfee = j64bits(item,"txfee");
        if ( (estimatedrate= jdouble(item,"estimatedrate")) == 0. )
            estimatedrate = 20;
        pubtype = juint(item,"pubtype");
        if ( (p2shtype= juint(item,"p2shtype")) == 0 )
            p2shtype = 85;
        if ( (wiftype= juint(item,"wiftype")) == 0 )
            wiftype = 188;
        if ( (assetname= jstr(item,"asset")) != 0 )
        {
            name = assetname;
            pubtype = 60;
        }
        else if ( (name= jstr(item,"name")) == 0 )
            name = symbol;

        uint8_t decimals = juint(item,"decimals");
        uint32_t txversion = juint(item, "txversion");
        if (txversion == 0) {
            txversion = 1;
        }

        LP_coininit(&cdata,symbol,name,assetname==0?"":assetname,isPoS,port,pubtype,p2shtype,wiftype,txfee,estimatedrate,longestchain,juint(item,"wiftaddr"),juint(item,"taddr"),LP_busport(port),jstr(item,"confpath"),decimals,txversion);

        coin = LP_coinadd(&cdata);
        coin->inactive = (uint32_t)time(NULL);

        // here we assume that any assetchain except OOT and ZILLA are sapling active with txversion=4,
        // TODO: get "blocks" and "sapling" from daemon's "getinfo" rpc to make proper check

        if ( coin->isassetchain != 0 && strcmp(symbol,"OOT") != 0 && strcmp(symbol,"ZILLA") != 0 )
            coin->txversion = 4;

        if (coin !=0) printf("[ Debug ] LP_coincreate: symbol.%s name.%s assetname.%s port.%d isassetchain.%d txversion.%d\n", symbol, name, assetname, port, coin->isassetchain, coin->txversion);

    } else if ( symbol != 0 && jobj(item,"rpcport") == 0 )
        printf("SKIP %s, missing rpcport field in coins array\n",symbol);
    if ( coin != 0 && item != 0 )
    {
        if ( strcmp("KMD",coin->symbol) != 0 )
        {
            if ( jobj(item,"active") != 0 )
                coin->inactive = !jint(item,"active");
            else
            {
                if ( IAMLP == 0 || assetname != name )
                    coin->inactive = (uint32_t)time(NULL);
                else coin->inactive = 0;
            }
        } else coin->inactive = 0;
    }
    if ( 0 && coin != 0 && coin->inactive != 0 )
        printf("LPnode.%d %s inactive.%u %p vs %p\n",IAMLP,coin->symbol,coin->inactive,assetname,name);
    return(0);
}

void LP_otheraddress(char *destcoin,char *otheraddr,char *srccoin,char *coinaddr)
{
    uint8_t addrtype,rmd160[20]; struct iguana_info *src,*dest;
    if ( (src= LP_coinfind(srccoin)) != 0 && (dest= LP_coinfind(destcoin)) != 0 )
    {
        bitcoin_addr2rmd160(srccoin,src->taddr,&addrtype,rmd160,coinaddr);
        bitcoin_address(destcoin,otheraddr,dest->taddr,dest->pubtype,rmd160,20);
    } else printf("couldnt find %s or %s\n",srccoin,destcoin);
}
