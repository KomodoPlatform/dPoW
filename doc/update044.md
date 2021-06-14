### dPoW 0.4.4 update information

- Update your MCL Coin's codebase to [2412d5f](https://github.com/marmarachain/marmara/tree/2412d5f5434a6b31f86da934d53df1729956654b), build it and then restart it

#### MCL

```bash
cd ~/Marmara-v.1.0
git pull
git checkout 2412d5f
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/Marmara-v.1.0/src/
./komodo-cli -ac_name=MCL stop
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=MCL -ac_supply=2000000 -ac_cc=2 -addnode=37.148.210.158 -addnode=37.148.212.36 -addressindex=1 -spentindex=1 -ac_marmara=1 -ac_staked=75 -ac_reward=3000000000 -pubkey=$pubkey &
```

#### dPoW

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
