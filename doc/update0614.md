### dPoW 0.6.14 update information

- On your 3P node, update your Verus Coin's codebase to [`185d1a5`](https://github.com/VerusCoin/VerusCoin/tree/185d1a54b8d890c95fd2ce5dd622f099a99aae6e), build it and then restart it.

- Build Verus Coin

```bash
cd ~/VerusCoin
git pull
git checkout 185d1a5
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
