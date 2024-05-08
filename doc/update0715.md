# dPoW 0.7.15 update information

## On your main node, launch VOTE2024 chain, import your private key and start staking

```bash
# Launch KIP0001
cd ~/komodo/src/
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=VOTE2024 -ac_public=1 -ac_supply=149826699 -ac_staked=10 -addnode=65.21.52.182 &


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

## On your **3P node**

- update your Verus Coin's codebase to [`1d62f81`](https://github.com/VerusCoin/VerusCoin/commit/1d62f81ea1dbef637017cde9de66e3b64cce8051), build it and then restart it


#### Using docker setup

```bash
cd notary_docker_3p
git pull
./update
./start
```

#### Using other setup

- Build Verus Coin

```bash
vrsc_commit='1d62f81'
cd ~/VerusCoin
git pull
git checkout ${vrsc_commit}
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
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
