### dPoW 0.3.8 update information

- Launch and sync `VOTE2021` and `GLEEC` on your main node in the usual way

Useful info:

- Start the chains with the params below (remembering to start with your NN pubkey):

```
./komodod -ac_name=VOTE2021 -ac_public=1 -ac_supply=129848152 -addnode=77.74.197.115 -pubkey=$pubkey &
./komodod -ac_name=GLEEC -ac_supply=21000000 -ac_public=1 -ac_staked=100 -addnode=95.217.161.126 -pubkey=$pubkey &
```

- Import your privkey into both chains

```
./komodo-cli -ac_name=VOTE2021 importprivkey ***
./komodo-cli -ac_name=GLEEC importprivkey ***
```

- Open `tcp/55637` and `tcp/33300` and  for incoming p2p connections:

```
sudo ufw allow 55637/tcp comment 'VOTE2021 p2p port'
sudo ufw allow 33300/tcp comment 'GLEEC p2p port'
```

- Add VOTE2021 and GLEEC to your autosplit script(s)

assetchains.json additions below:
```  
  {
    "ac_name": "GLEEC",
    "ac_supply": "21000000",
    "ac_public": "1",
    "ac_staked": "100",
    "addnode":["95.217.161.126"]
  },
  {
    "ac_name": "VOTE2021",
    "ac_supply": "129848152",
    "ac_public": "1",
    "addnode": ["77.74.197.115"]
  },
```
    
- Update your dPoW repo, rebuild and restart iguana

```bash
cd ~/dPoW
git checkout master
git pull
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_build # build iguana
./m_notary_KMD # start notarization
```

Make sure your iguana is running properly.

- Split VOTE2021 & GLEEC UTXO's once Iguana is running
