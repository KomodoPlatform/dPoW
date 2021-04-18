# How to partcipate

Make a Pull Request with your IP Address added to `iguana/m_notary_testnet2021` and your public key and name added to `iguana/testnet.json`. Please specify your discord name in the pull request. You will be added to a discord role used for notifying operators.

# Install and start the notary

#### * Clone this repo, use `2021-testnet` branch
#### * Install dependencies
```shell
sudo apt install build-essential pkg-config libc6-dev m4 \
        g++-multilib autoconf libtool ncurses-dev unzip git python \
        zlib1g-dev wget bsdmainutils automake libboost-all-dev \
        libssl-dev libprotobuf-dev protobuf-compiler \
        libqrencode-dev libdb++-dev ntp ntpdate vim software-properties-common \
        curl libevent-dev libcurl4-gnutls-dev libsodium-dev cmake clang jq
```
#### * Install nanomsg from https://github.com/nanomsg/nanomsg
#### * Clone and build Komodo from https://github.com/komodoplatform/komodo --branch beta
#### * Create ~/.komodo/komodo.conf
```
rpcuser=<secure username>
rpcpassword=<secure password>
txindex=1
server=1
daemon=1
rpcworkqueue=256
```
#### * set permissions
```
chmod 600 ~/.komodo/komodo.conf
```

#### * Clone and build Litecoin
```
git clone https://github.com/litecoin-project/litecoin --branch 0.16
cd litecoin
git checkout 0.16
./autogen
./configure --without-gui --with-incompatible-bdb
make -j4
```
optional, add a bash shortcut to litecoin-cli and litecoind
```
make install
```

# create ~/.litecoin and litecoin.conf 
```
mkdir ~/.litecoin
```
create `~/.litecoin/litecoin.conf` with:
```
rpcuser=<secure username>
rpcpassword=<secure password>
txindex=1
```
```
chmod 600 ~/.litecoin/litecoin.conf
```

#### * Start KMD daemon
```shell
komodod
```
#### * Export keys
```shell
# Get your address (to backup)
komodo-cli getaccountaddress ""
<your address>
# Retrieve your public key (to backup)
komodo-cli validateaddress <your address>
{
  "isvalid": true,
  "address": "<your address>",
  "scriptPubKey": "<you don't need to use your scriptPubKey, do not use>",
  "segid": 63,
  "ismine": true,
  "iswatchonly": false,
  "isscript": false,
  "pubkey": "<your public key>",
  "iscompressed": true,
  "account": ""
}
# Get private key (to backup and keep secret)
komodo-cli dumpprivkey <your address>
<your private key>
```
Please do not share your private key, keep it secret.
#### * Edit files and make the PR
Edit `iguana/m_notary_testnet2021` and `iguana/testnet.json` to add an entry with <your public key> and your public IP address. Edit files into your fork of this github repository then make a Pull Request to this repository.

What is my public IP ?
```shell
curl https://ipinfo.io/ip
```
or
```shell
dig +short myip.opendns.com @resolver1.opendns.com
```
#### * Stop KMD daemon
```shell
komodo-cli stop
```
#### * Start KMD daemon with `-pubkey=<your public key>`
#### * Start RICK and MORTY `-pubkey=<your public key>`. The parameters can be found in `komodo/src/assetchains.old`
#### * Start LTC daemon 

#### * (Optional but recommended for better performance) Open ports required for p2p. These values can get found as `"p2pport"` using the `getinfo` rpc method. 

| Coin          | Port          |
| ------------- |-------------: |
| KMD           | 7770          |
| LTC           | 9333          |
| RICK          | 25434         |
| MORTY         | 16347         |
| Iguana        | 17778         |

*NOTE: Iguana Port 17778 MUST be open

#### * Fund public key address on litecoin, komodo and each asset chain.
*If you need RICK or MORTY, use the faucets at https://www.atomicexplorer.com/#/faucet/ or http://stats.kmd.io/faucet/  or ask in #notarynode channel.*
There is plenty of volume on Atomicdex's KMD/LTC pair. 

#### * Import your private key to all 3 komodod nodes.
```shell
komodo-cli -ac_name=<coin name> importprivkey <your private key>
```
#### * Import your private key to LTC node. See https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#generate-two-pubkey-address-wif-s
```shell
litecoin-cli importprivkey <your LTC private key>
```
#### * Create `~/dPoW/iguana/pubkey.txt`
```
pubkey=<your public key>
```
#### * Create `~/dPoW/iguana/wp_testnet` and change its permissions
```
curl --url "http://127.0.0.1:7776" --data "{\"method\":\"walletpassphrase\",\"params\":[\"<YOUR WIF OR PASSPHRASE>\", 9999999]}"
```
```shell
chmod 700 wp_testnet
```

#### Compile iguana
```shell
cd ~/dPoW/iguana
./m_notary_build
```

#### * Wait until the PR is merged.
Please feel free to join the Komodo discord where you can ask some help into the #notarynode channel https://discord.gg/UdwpxrG

#### * Start/restart notorization with Iguana
*This script must be run from within the `dPoW/iguana` directory.*
```shell
cd ~/dPoW/iguana
./m_notary_testnet2021
```
#### * Resources
This repository contains many useful scripts but you should read and understand before executing blindly. You'll find useful scripts at the following repositories but you should read the readme, adapt the config and read the code of the scripts you want to execute.
https://github.com/KMDLabs/StakedNotary/
https://github.com/KomodoPlatform/komodotools
https://github.com/webworker01/nntools
https://github.com/MrMLynch/nnutils

https://blog.komodoplatform.com/delayed-proof-of-work-explained-9a74250dbb86
