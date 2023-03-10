### dPoW 0.6.7 update information

-On your 3P node, update your Verus Coin's codebase to [`c7bb569`](https://github.com/VerusCoin/VerusCoin/tree/c7bb569d664c1ed1a5e680df1acac1b64cad5597), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout c7bb569
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
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
