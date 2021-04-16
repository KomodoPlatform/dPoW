### dPoW 0.2.5 update information:

**The Verus Coin's codebase has to be updated for continued stable operation**

- Please update your Verus Coin's codebase to [ab82cc9](https://github.com/VerusCoin/VerusCoin/tree/ab82cc9aad27db997d8dd9d30ebd973a78c22abc) and build it
- If your VRSC node had a crash, please use the updated `verusd` to restart it. Even if it didn't have a crash, update to the recommended version and restart it

```bash
cd VerusCoin
git pull
git checkout ab82cc9
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Launch it

```bash
source ~/dPoW/iguana/pubkey.txt
~/VerusCoin/src/verusd -pubkey=$pubkey &
```

- Wait for the VRSC chain to sync

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly and has not crashed. Restart iguana if it has crashed.
