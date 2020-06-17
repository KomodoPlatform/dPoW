**The Hush coin's codebase is ready for Season 4 Activation**

- Please update your Hush codebase to [7f7876d](https://github.com/MyHush/hush3/tree/7f7876d2084daebc89b1914c870fa407c4fbef4e)
- Build it

```bash
cd ~/hush3
./zcutil/build.sh
```

- Launch it (replace `$pubkey` with your pubkey)

```bash
~/hush3/src/komodod -pubkey=$pubkey -ac_name=HUSH3 -ac_sapling=1 -ac_reward=0,1125000000,562500000 -ac_halving=129,340000,840000 -ac_end=128,340000,5422111 -ac_eras=3 -ac_blocktime=150 -ac_cc=2 -ac_ccenable=228,234,235,236,241 -ac_founders=1 -ac_supply=6178674 -ac_perc=11111111 -clientname=GoldenSandtrout -addnode=188.165.212.101 -addnode=136.243.227.142 -addnode=5.9.224.250 -ac_cclib=hush3 -ac_script=76a9145eb10cf64f2bab1b457f1f25e658526155928fac88ac &
```

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

- Restart dPoW

```bash
pkill -15 iguana
cd dPoW
./m_notary_3rdparty
```