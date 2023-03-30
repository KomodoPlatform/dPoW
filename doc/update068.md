### dPoW 0.6.8 update information

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

Make sure chain is running smoothly. Don't forget to add `VOTE2023` to your utxo splitting scripts.

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

Make sure notarisations are progressing.