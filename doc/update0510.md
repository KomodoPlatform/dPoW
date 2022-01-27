### dPoW 0.5.10 update information

- On your 3P node, update your MCL Coin's codebase to [b288dfd](https://github.com/marmarachain/marmara/tree/b288dfd66e2761e40af717362f75e4d5319c4f7f), build it and then restart it

```bash
cd ~/marmara
git pull
git checkout b288dfd
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

After successful build, run the following commands to restart Tokel with the new changes:

```bash
cd ~/marmara/src
./komodo-cli -ac_name=MCL stop
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=MCL -ac_supply=2000000 -ac_cc=2 -addnode=5.189.149.242 -addnode=161.97.146.150 -addnode=149.202.158.145 -addressindex=1 -spentindex=1 -ac_marmara=1 -ac_staked=75 -ac_reward=3000000000 -daemon -pubkey=$pubkey &
```

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
