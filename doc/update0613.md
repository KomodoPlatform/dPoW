### dPoW 0.6.13 update information


- On your 3P node, update your Verus Coin's codebase to [`8446534`](https://github.com/VerusCoin/Verus-Desktop/tree/8446534533b6dc96b20814562970443ad0c9209d), build it and then restart it.

- Build Verus Coin

```bash
cd ~/VerusCoin
git pull
git checkout 8446534
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
