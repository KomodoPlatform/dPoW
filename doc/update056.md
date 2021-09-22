### dPoW 0.5.6 update information

- On your Main node and 3P node, update your Komodo Coin's codebase to [7df102f](https://github.com/KomodoPlatform/komodo/tree/7df102f42fa3c1672d5a7b57733378fd36a172da), build it and then restart the Komodo coin's daemon.

- On your Main node, restart all Smartchain daemons. If you still have OOT, COQUICASH, AXO or BTCH running on your main node, you may shut them down.

#### Instructions for 3P node

```bash
cd ~/komodo
git pull
git checkout 7df102f
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/komodo/src
./komodo-cli stop
source ~/dPoW/iguana/pubkey.txt
./komodod -pubkey=$pubkey &
```

- Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.

#### Instructions for Main node

- Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

- Update komodod

```bash
cd ~/komodo
git pull
git checkout 7df102f
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart KMD chain and all other Smart Chains

```bash
cd ~/komodo/src
./komodo-cli stop
pkill -15 komodod
# wait some time and check debug logs of all coins in ~/dPoW/iguana/assetchains.old to make sure they are shutdown before proceeding to the next step 
source ~/dPoW/iguana/pubkey.txt
./komodod -pubkey=$pubkey &
cd ~/dPoW/iguana
./assetchains.old
```

Make sure your iguana is running properly.
