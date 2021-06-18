### dPoW 0.5.1 update information

- Update your Verus Coin's codebase to [2fcb26a](https://github.com/VerusCoin/VerusCoin/commit/2fcb26ab2c232b052fc147e38ddbc6d2bdcf4dad), build it and then restart it

```bash
cd ~/VerusCoin/src
verus stop
git pull
git checkout 2fcb26a
../zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
./verus stop
source ~/dPoW/iguana/pubkey.txt
verusd -pubkey=$pubkey &
```

- Update your dPoW repo

```bash
cd ~/dPoW/iguana
git checkout master
git pull
./m_notary_build
./m_notary_3rdparty
```

Make sure your iguana is running properly.

Note: You will either need to clear blocks and chainstate in ~/.komodo/VRSC and resync, or invalidate block 1568000. 
Ask for help in Discord if you have problems.


- Shut down OOT, COQUICASH, AXO & BTCH daemons on Main server. These chains have been removed from dPoW assets.

```bash
komodo-cli -ac_name=AXO stop
komodo-cli -ac_name=BTCH stop
komodo-cli -ac_name=COQUICASH stop
komodo-cli -ac_name=OOT stop
```
