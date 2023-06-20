### dPoW 0.6.13 update information

- On your 3P node, update your Verus Coin's codebase to [`caa1107`](https://github.com/VerusCoin/VerusCoin/tree/caa1107fea7bda7ac27af559b8676ddf1dfb3f55), build it and then restart it.

- Build Verus Coin

```bash
cd ~/VerusCoin
git pull
git checkout caa1107
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
