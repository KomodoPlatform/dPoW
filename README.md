# dPoW client _iguana_

This repository is based on the original SuperNET codebase - commit [f29913e92b117399cd42e2fd05ff0d69d152c8fa](https://github.com/ca333/SuperNET/commit/f29913e92b117399cd42e2fd05ff0d69d152c8fa)

Integration | Status 
-------------|------
CI build - Ubuntu (16.04, 18.04) | [![Build Status](https://github.com/komodoplatform/dpow/workflows/CI/badge.svg?maxAge=60)](https://github.com/KomodoPlatform/dPoW/actions)
Codefactor analysis | [![Grade](https://img.shields.io/codefactor/grade/github/komodoplatform/dpow)](https://www.codefactor.io/repository/github/komodoplatform/dpow)
Version | [![Version](https://img.shields.io/github/v/release/komodoplatform/dPoW)](https://github.com/KomodoPlatform/dPoW/releases)

---


## Installation 

General [Setup instructions](https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#setup-komodo-notary-node)

### Build instructions for NN testnet operations:

- Install deps and nanomsg: See https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#initial-server-setup
- Clone & build the Komodo Deamon: See https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#setup-iguana


Start RICK/MORTY/KMD. Bootstrap or sync the chains
```
~/komodo/src/komodod &
~/komodo/src/komodod -addnode=138.201.136.145 -addnode=95.217.44.58 -ac_supply=90000000000 -ac_staked=10 -ac_name=RICK -ac_reward=100000000 -ac_cc=3 &
~/komodo/src/komodod -addnode=138.201.136.145 -addnode=95.217.44.58 -ac_supply=90000000000 -ac_staked=10 -ac_name=MORTY -ac_reward=100000000 -ac_cc=3 &
```
*Bootstraps kindly provided by Chmex at https://dexstats.info/bootstrap.php*

- Create an address for your node: `komodo-cli getnewaddress`
- Get the pubkey for this address: `komodo-cli validateaddress [YOUR_ADDRESS]`
- **Supply pubkey and IP address to smk, once a day `m_notary_testnet_2022` & `testnet.json` will be updated to include new candidates.**


Get the private key for this address: `komodo-cli dumpprivkey [YOUR_ADDRESS]`

Import this key into RICK / MORTY: 
```
komodo-cli -ac_name=RICK importprivkey [YOUR_PRIVATE_KEY] "" true 1415000
komodo-cli -ac_name=MORTY importprivkey [YOUR_PRIVATE_KEY] "" true 1415000
```


Open RICK/MORTY/KMD p2p ports
```
sudo ufw allow 7770/tcp comment 'KMD p2p port'
sudo ufw allow 16347/tcp comment 'MORTY p2p port'
sudo ufw allow 25434/tcp comment 'RICK p2p port'
sudo ufw allow 17778/tcp comment 'Iguana p2p port'
```


Clone and build Iguana
```
git clone https://github.com/KomodoPlatform/dPoW/
cd dPoW
git checkout 2022-testnet
cd iguana
./m_notary_build
```


Create pubkey.txt file: `nano pubkey.txt`
- add your pubkey e.g. `pubkey=02e650819f4d1cabeaad6bc5ec8c0722a89e63059a10f8b5e97c983c321608329b`
- save and exit

Create wp_testnet file: `nano ./wp_testnet`
- Add your seed or private key e.g. `curl --url "http://127.0.0.1:7778" --data "{\"method\":\"walletpassphrase\",\"params\":[\"YOUR_SEED_OR_PRIVATE_KEY\", 9999999]}"`
- Save and exit
- Make executable `chmod 700 wp_testnet`

Set daemon pubkey
```
source ~/dPoW/iguana/pubkey.txt
komodo-cli setpubkey $pubkey
komodo-cli -ac_nameMORTY setpubkey $pubkey
komodo-cli -ac_name=RICK setpubkey $pubkey
```
*See the example launch script below to see how to launch with pubkey*


Once you are included, and every time others get added you need to rebuild and restart iguana:
```
# Stop iguana
pkill -9 iguana
# Build iguana
./m_notary_build
# Start iguana
./m_notary_testnet_2022
```

To get some RICK / MORTY funds for notarisation, [use the faucet](http://stats.kmd.io/faucet/)
You will also need some KMD (1 is more than enough). If you don't have any join the Komodo Platform Discord channel and ask.

**If you have any problems or questions, join the [Komodo Discord](https://discord.gg/3MhJCFH3H6) and ask for help!**

## Example Chain Launch Script:
```
#!/bin/bash
source ~/dPoW/iguana/pubkey.txt

echo "Starting KMD";
~/komodo/src/komodod -pubkey=$pubkey &

echo "Starting RICK";
~/komodo/src/komodod -addnode=138.201.136.145 -addnode=95.217.44.58 -ac_supply=90000000000 -ac_staked=10 -ac_name=RICK -ac_reward=100000000 -ac_cc=3 -pubkey=$pubkey &

echo "Starting MORTY";
~/komodo/src/komodod -addnode=138.201.136.145 -addnode=95.217.44.58 -ac_supply=90000000000 -ac_staked=10 -ac_name=MORTY -ac_reward=100000000 -ac_cc=3 -pubkey=$pubkey &
```


## Example Split script (set to cron every 30 mins):
```
#!/bin/bash
source ~/dPoW/iguana/pubkey.txt

chain="KMD"
unspent=$(~/komodo/src/komodo-cli listunspent | jq '[.[] | select (.generated==false and .amount==0.0001 and .spendable==true and (.scriptPubKey == "'21${pubkey}ac'"))] | length')
echo "${chain}: $unspent"

if [ $unspent -lt 40 ]; then
    echo "Topping up ${chain}"
    curl --url "http://127.0.0.1:7778" --data "{\"coin\":\""${chain}"\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":"80"}"
fi

chain="RICK"
unspent=$(~/komodo/src/komodo-cli -ac_name=${chain} listunspent | jq '[.[] | select (.generated==false and .amount==0.0001 and .spendable==true and (.scriptPubKey == "'21${pubkey}ac'"))] | length')
echo "${chain}: $unspent"
if [ $unspent -lt 20 ]; then
echo "Topping up ${chain}"
curl --url "http://127.0.0.1:7778" --data "{\"coin\":\""${chain}"\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":"20"}"
fi

chain="MORTY"
unspent=$(~/komodo/src/komodo-cli -ac_name=${chain} listunspent | jq '[.[] | select (.generated==false and .amount==0.0001 and .spendable==true and (.scriptPubKey == "'21${pubkey}ac'"))] | length')
echo "${chain}: $unspent"
if [ $unspent -lt 20 ]; then
echo "Topping up ${chain}"
curl --url "http://127.0.0.1:7778" --data "{\"coin\":\""${chain}"\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":"20"}"
fi
```


**Please note: Automatic UTXO split is deactivated by default.**

### dPoW asset status

#### dPoW assets update requirements

**Please note:** All dPoW protected blockchain projects are required to open an issue ticket with upgrade details in this repository and at least 4 weeks prior to a mandatory update - in case of significant code changes (>2000 lines of code altered/added) open the issue ticket at least 8 weeks prior to the mandatory update. Send the official update announcement ref to `partners@komodoplatform.com`.

#### [Notary Node metrics](http://stats.kmd.io/) - http://stats.kmd.io/

[![dPOW Status](https://badges.komodo.live/svg/date_badge.svg?maxAge=60)](https://komodostats.com)
* active - last notarization less than 2.5 hours ago
* irregular - last notarization more than 2.5 and less than 24 hours ago
* inactive - last notarization more than 24 hours ago

Coin | src | Version/Tree | Status | dPoW 
--------|------|---|------|------
KMD | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
MORTY | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
RICK | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/RICK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
