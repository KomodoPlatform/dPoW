### dPoW 0.5.9 update information

- On your 3P node, update your Tokel Coin's codebase to [f39a088](https://github.com/KomodoPlatform/komodo/tree/f39a0881a5d672f7c1131e5ae6d390e8cdccb037), build it and then restart it

```bash
cd ~/tokelkomodo
git pull
git checkout f39a088
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

After successful build, run the following commands to restart Tokel with the new changes:

```bash
cd ~/tokelkomodo/src
./komodo-cli -ac_name=TOKEL stop
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=TOKEL -ac_supply=100000000 -ac_eras=2 -ac_cbmaturity=1 -ac_reward=100000000,4250000000 -ac_end=80640,0 -ac_decay=0,77700000 -ac_halving=0,525600 -ac_cc=555 -ac_ccenable=236,245,246,247 -ac_adaptivepow=6 -addnode=135.125.204.169 -addnode=192.99.71.125 -addnode=144.76.140.197 -addnode=135.181.92.123 -pubkey=$pubkey &
```

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
