### dPoW 0.7.14 update information

On your main node, launch KIP0002, KIP0003, KIP0004 chains, import your private key and start staking

```bash
# Launch KIP0001
cd ~/komodo/src/
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=KIP0002 -ac_public=1 -ac_supply=149687271 -ac_staked=10 -addnode=65.21.52.182 -pubkey=$pubkey &
./komodod -ac_name=KIP0003 -ac_public=1 -ac_supply=149687271 -ac_staked=10 -addnode=65.21.52.182 -pubkey=$pubkey &
./komodod -ac_name=KIP0004 -ac_public=1 -ac_supply=149687271 -ac_staked=10 -addnode=65.21.52.182 -pubkey=$pubkey &


# Import your private key
./komodo-cli -ac_name=KIP0002 importprivkey $privkey
./komodo-cli -ac_name=KIP0003 importprivkey $privkey
./komodo-cli -ac_name=KIP0004 importprivkey $privkey


# Start Staking
./komodo-cli -ac_name=KIP0002 setgenerate true 0
./komodo-cli -ac_name=KIP0003 setgenerate true 0
./komodo-cli -ac_name=KIP0004 setgenerate true 0


# Open P2P Port
sudo ufw allow 63160/tcp comment 'KIP0002 p2p port'
sudo ufw allow 48530/tcp comment 'KIP0003 p2p port'
sudo ufw allow 58225/tcp comment 'KIP0004 p2p port'


# Check sync status
tail -f ~/.komodo/KIP0002/debug.log
tail -f ~/.komodo/KIP0003/debug.log
tail -f ~/.komodo/KIP0004/debug.log
```

Make sure all the chains are running smoothly. Don't forget to add `KIP0002`,`KIP0003`,`KIP0004` to your utxo splitting scripts.

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
