### dPoW 0.3.5 update information

- Update your Verus Coin's codebase to [3fde9bf](https://github.com/VerusCoin/VerusCoin/tree/3fde9bfd727c5081e0308a98d47925379945cac1), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout 3fde9bf
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
