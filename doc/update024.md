### dPoW 0.2.4 update informations:

**The Marmarachain's codebase is ready for Season 4 Activation in 3P node**

- Please update your Marmarachain's codebase to [03dd780](https://github.com/marmarachain/Marmara-v.1.0/tree/03dd78037067ebb27af8b33f6adcdbede3813007) and build it

```bash
cd Marmara-v.1.0
git pull
git checkout 03dd780
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Launch it

```bash
source ~/dPoW/iguana/pubkey.txt
~/Marmara-v.1.0/src/komodod -ac_name=MCL -pubkey=$pubkey -ac_supply=2000000 -ac_cc=2 -addnode=37.148.210.158 -addnode=37.148.212.36 -addressindex=1 -spentindex=1 -ac_marmara=1 -ac_staked=75 -ac_reward=3000000000 -daemon
```

- Wait for the MCL chain to sync

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

- Start Notarizing MCL

```bash
~/dPoW/iguana/coins/mcl_7779
source ~/dPoW/iguana/pubkey.txt
curl --url "http://127.0.0.1:7779" --data "{\"agent\":\"iguana\",\"method\":\"dpow\",\"symbol\":\"MCL\",\"pubkey\":\"$pubkey\"}"
```
