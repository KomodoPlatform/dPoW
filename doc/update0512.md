### dPoW 0.5.12 update information

-On your 3P node, update your Verus Coin's codebase to [81dac44](https://github.com/VerusCoin/VerusCoin/tree/81dac44081e469a08e013de2e400edf73cdd94e2), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout 81dac44
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
