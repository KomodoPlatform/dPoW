### dPoW 0.6.10 update information

- On your 3P node, update your Verus Coin's codebase to  [`42e83aa`](https://github.com/VerusCoin/VerusCoin/commit/42e83aa08aa44d30bf9620d6da9ef0f68b85d530), build it and then restart it. 

- Build Verus Coin
```bash
cd ~/VerusCoin
git pull
git checkout 42e83aa
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
