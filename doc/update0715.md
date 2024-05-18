# dPoW 0.7.15 update information

## On your main node, launch VOTE2024 chain, import your private key and start staking

```bash
# Launch VOTE2024
cd ~/komodo/src/
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=VOTE2024 -ac_public=1 -ac_supply=149826699 -ac_staked=10 -addnode=65.21.52.182 -pubkey=$pubkey &


# Import your private key
./komodo-cli -ac_name=VOTE2024 importprivkey $privkey


# Start Staking
./komodo-cli -ac_name=VOTE2024 setgenerate true 0

- Be aware that this may add to your utxo count, so make sure to consolidate periodically.

# Open P2P Port
sudo ufw allow 60915/tcp comment 'VOTE2024 p2p port'


# Check sync status
tail -f ~/.komodo/VOTE2024/debug.log
```


## On your **Main node**

- Remove KIP0002, KIP0003 and KIP0004

```bash
cd ~/komodo/src
komodo-cli -ac_name=KIP0002 stop
komodo-cli -ac_name=KIP0003 stop
komodo-cli -ac_name=KIP0004 stop

# Optionally, remove data
rm -rf ~/.komodo/KIP0002
rm -rf ~/.komodo/KIP0003
rm -rf ~/.komodo/KIP0004
```


## On your **3P node**

- Remove VRSC

#### Using docker setup

```bash
cd notary_docker_3p
git pull
./update
./start
```

#### Using other setup

- Stop Verus Coin

```bash
cd ~/VerusCoin/src
vrsc-cli stop
```

## Make sure all the chains are running smoothly. Don't forget to add `VOTE2024` to your utxo splitting scripts.

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
./m_notary_3rdparty #(or via Docker: ./m_notary_3rdparty_docker)
```

Make sure notarisations are progressing.
