### dPoW 0.7.3 update information

- On your 3P node, update your Verus Coin's codebase to [`2d32721`](https://github.com/VerusCoin/VerusCoin/tree/2d327210fddc245c693d00c9a025bd81f5f079eb), build it and then restart it.

- Build Verus Coin

```bash
cd ~/VerusCoin
git pull
git checkout 2d32721
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
