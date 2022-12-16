### dPoW 0.6.5 update information

- On your 3P node, update your VRSC Coin's codebase to [7f971ed](https://github.com/VerusCoin/VerusCoin/tree/7f971ed3d4c5e1ec45737f374b9467b1a24d2679), build it and then restart it

```bash
# Build VRSC

cd ~/VerusCoin/
git pull
git checkout 7f971ed3d4c5e1ec45737f374b9467b1a24d2679
./zcutil/build.sh -j4

# (re)start VRSC
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &

# Check sync status
tail -f ~/.komodo/VRSC/debug.log
```

Make sure chain is running smoothly and notarisations are progressing.
