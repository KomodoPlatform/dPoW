### dPoW 0.6.8 update information


#### Update seednode mm2 to v1.0.1-beta

A new version of the AtomicDEX-API has just been released! Please update your seednodes to [`6bb79b3d8`](https://github.com/KomodoPlatform/atomicDEX-API/releases/tag/v1.0.1-beta).
Once updated, stop and restart your seednode(s).

```bash
cd ~/nn_mm2_seed
git pull
./stop_mm2.sh
./update_mm2.sh
./update_coins.sh
./run_mm2.sh
```

#### Add VOTE2023

On your main node, launch VOTE2023 and import your private key.

```bash
# Launch VOTE2023
cd ~/komodo/src/
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=VOTE2023 -ac_public=1 -ac_supply=139706361 -ac_staked=10 -addnode=178.159.2.6 -addnode=185.220.204.44 -pubkey=$pubkey &

# Import your private key
./komodo-cli -ac_name=VOTE2023 importprivkey $privkey

# Start Staking
./komodo-cli -ac_name=VOTE2023 setgenerate true 0

# Open P2P Port
sudo ufw allow 29806/tcp comment 'VOTE2023 p2p port'

# Check sync status
tail -f ~/.komodo/VOTE2023/debug.log
```

Make sure chain is running smoothly. 

#### Remove KIP0001

```bash
# Stop KIP0001
cd ~/komodo/src
./komodo-cli -ac_name=KIP0001 stop
```

#### Update and restart Iguana

```bash
# Update dPoW repo
cd ~/dPoW
git checkout master
git pull

# Restart Iguana
pkill -9 iguana
cd iguana
./m_notary_build
./m_notary_main
```

Make sure notarisations are progressing. **Don't forget to update your utxo splitting scripts to add `VOTE2023` and remove `KIP0001`.**