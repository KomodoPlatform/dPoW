### dPoW 0.6.12 update information

- On your 3P node, update your Verus Coin's codebase to  [`4beede9`](https://github.com/VerusCoin/VerusCoin/tree/4beede91ab5562d866a90cc5b2d203acbe2bd22c), build it and then restart it.

- Build Verus Coin

```bash
cd ~/VerusCoin
git pull
git checkout 4beede9
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
