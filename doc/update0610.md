### dPoW 0.6.10 update information

- On your 3P node, update your Verus Coin's codebase to  [`576c5b2`](https://github.com/VerusCoin/VerusCoin/commit/576c5b24058e2a01a0b57cc00a1a13900ae68400), build it and then restart it. 

- Build Verus Coin
```bash
cd ~/VerusCoin
git pull
git checkout f672ccf
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
