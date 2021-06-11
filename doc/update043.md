### dPoW 0.4.3 update information

- Update your Verus Coin's codebase to [7a740d2](https://github.com/VerusCoin/VerusCoin/tree/7a740d2b02f54457e2a8b2d205387ed3895aacc9), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout 7a740d2
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
