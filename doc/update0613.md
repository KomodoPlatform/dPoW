### dPoW 0.6.13 update information

- On your 3P node, update your Verus Coin's codebase to [`04a675e`](https://github.com/VerusCoin/VerusCoin/tree/04a675e1bbd8c91e1d27ada962d9c9b208476c4e), build it and then restart it.

- Build Verus Coin

```bash
cd ~/VerusCoin
git pull
git checkout 04a675e
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
