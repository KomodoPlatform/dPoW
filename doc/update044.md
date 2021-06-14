### dPoW 0.4.4 update information

- Update your MCL Coin's codebase to [2412d5f](https://github.com/marmarachain/marmara/tree/2412d5f5434a6b31f86da934d53df1729956654b), build it and then restart it
- Please update iguana and ensure your NN infrastructure is ready for S5 (Both main and 3P).

#### MCL

```bash
cd ~/marmara
git pull
git checkout 2412d5f
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/marmara/src/
./komodo-cli -ac_name=MCL stop
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=MCL -ac_supply=2000000 -ac_cc=2 -addnode=37.148.210.158 -addnode=37.148.212.36 -addressindex=1 -spentindex=1 -ac_marmara=1 -ac_staked=75 -ac_reward=3000000000 -pubkey=$pubkey &
```


#### dPoW (Both main and 3P)

<b>Please update iguana and ensure your NN infrastructure is ready for S5.</b>


```bash
cd ~/dPoW
git pull

# Kill iguana, rebuild and start it

pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_build
```

Then launch with `./m_notary_3rdparty` or `./m_notary_LTC` based on the server


Please note that iguana ports were changed to 13337 for main and 13334 3rd party networks

After `git pull` restart your iguana and adjust your firewall settings accordingly, e.g. :

```bash
sudo ufw allow 13337/tcp comment 'iguana mainnet p2p'
sudo ufw allow 13334/tcp comment 'iguana 3rd p2p'
```
