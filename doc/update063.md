

#### For Season 5 Ops still running VRSC on last season's keys

```bash
cd ~/VerusCoin
git pull
git checkout 25ed684
./zcutil/build.sh -j$(expr $(nproc) - 1)

cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
```

Make sure chain is running smoothly and notarisations are progressing.