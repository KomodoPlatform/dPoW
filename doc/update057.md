### dPoW 0.5.7 update information

-On your 3P node, update your Verus Coin's codebase to [4c7a0a6](https://github.com/VerusCoin/VerusCoin/tree/4c7a0a68dd87a17da483086cddeeb436f1d23698), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout 4c7a0a6
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
