### dPoW 0.6.5 update information

- On your 3P node, update your VRSC Coin's codebase to [1b02282](https://github.com/VerusCoin/VerusCoin/commit/1b022820ac1f4a539c0eed60584cac29715c34f1), build it and then restart it

```bash
# Build VRSC

cd ~/VerusCoin/
git pull
git checkout 1b022820ac1f4a539c0eed60584cac29715c34f1
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
