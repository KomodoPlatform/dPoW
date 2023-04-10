### dPoW 0.6.7 update information

-On your 3P node, update your Verus Coin's codebase to [`ad8fb8d`](https://github.com/VerusCoin/VerusCoin/tree/ad8fb8d3093784ca8be2985718253fb3a60dc505), build it and then restart it

```bash
cd ~/VerusCoin
git checkout ad8fb8d
git pull
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
