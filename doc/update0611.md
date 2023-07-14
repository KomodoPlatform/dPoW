### dPoW 0.6.11 update information

- On your 3P node, update your Verus Coin's codebase to  [`3f0f435`](https://github.com/VerusCoin/VerusCoin/commit/3f0f4353f12e82e107144687e9e111c31134b9d4), build it and then restart it. 

- Build Verus Coin
```bash
cd ~/VerusCoin
git pull
git checkout 3f0f435
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
```

- Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
