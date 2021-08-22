### dPoW 0.5.5 update information

-On your 3P node, update your Verus Coin's codebase to [77424d8](https://github.com/VerusCoin/VerusCoin/tree/77424d8a4ef7f582f73abf4fb1ff77e08d8d280a), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout 77424d8
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
verusd -pubkey=$pubkey &
```

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
