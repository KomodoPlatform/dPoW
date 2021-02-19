### dPoW 0.3.6 update information

- Update your Verus Coin's codebase to [d3cffbe](https://github.com/VerusCoin/VerusCoin/tree/d3cffbe4e088166f980afdcf14ed5fbed72b542b), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout d3cffbe
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
- Shut down RFOX daemon. RFOX was removed from dPoW assets.

Make sure your iguana is running properly.
