### dPoW 0.3.7 update information

- Remove PGT and STBL SmartChains from dPoW security in Main server.
- Update your dPoW repo and restart iguana

```bash
cd ~/dPoW
git checkout master
git pull
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_build # build iguana
./m_notary_KMD # start notarization
```

- Stop the daemons

```bash
cd ~/komodo/src
./komodo-cli -ac_name=STBL stop
./komodo-cli -ac_name=PGT stop
```

Make sure your iguana is running properly.
