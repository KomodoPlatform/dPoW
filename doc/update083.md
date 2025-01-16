# dPoW 0.8.3 update information

### Launch `BCZERO`, `RAPH`, `MDX` chains, import your private key and start staking

```bash
# Launch chains
cd ~/komodo/src/
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=BCZERO -ac_supply=9999999999 -ac_end=1 -ac_public=1 -ac_staked=50 -addnode=65.21.52.182 -pubkey=$pubkey &
./komodod -ac_name=RAPH -ac_supply=999999999 -ac_end=1 -ac_public=1 -ac_staked=50 -addnode=65.21.52.182 -pubkey=$pubkey &
./komodod -ac_name=MDX -ac_supply=999999999 -ac_end=1 -ac_public=1 -ac_staked=50 -addnode=65.21.52.182 -pubkey=$pubkey &
```

# Import your private key
```bash
./komodo-cli -ac_name=BCZERO importprivkey $privkey
./komodo-cli -ac_name=RAPH importprivkey $privkey
./komodo-cli -ac_name=MDX importprivkey $privkey
```

# Start Staking
```bash
./komodo-cli -ac_name=BCZERO setgenerate true 0
./komodo-cli -ac_name=RAPH setgenerate true 0
./komodo-cli -ac_name=MDX setgenerate true 0
```

# Open P2P Port
```bash
sudo ufw allow 45833/tcp comment 'BCZERO p2p port'
sudo ufw allow 30260/tcp comment 'RAPH p2p port'
sudo ufw allow 18481/tcp comment 'MDX p2p port'
```

### Restart Iguana

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
./m_notary_3rdparty_docker # or ./m_notary_3rdparty if not using docker
```

Make sure notarisations are progressing.


