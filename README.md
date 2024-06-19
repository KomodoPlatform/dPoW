## dPoW Notary Node Testnet 2024

The public testnet will run from June 19th until the 2024 notary election is complete. Anyone is permitted to participate, even if you are not planning to run a mainnet node.
For participants who are running as candidates in the 2024 Notary Node elections, this is a great opportunity to test your setup and ensure everything is working as expected. It also provides voters with an opportunity to evaluate candidate participants to see how well they manage a node and how they interact with the community. You are encouraged to share tools and advice with other participants, and to ask questions if you are unsure about anything. 

Follow the instructions below to get started. If you have any questions, please ask in the [#2024-testnet channel on Discord](https://komodoplatform.com/discord). Once you have everything set up, ping @smk, @gcharang, or @decker in the #2024-testnet channel on Discord to add your pubkeys to the network. New participants / pubkeys will be added to the network every 24 hours, so to maximise your score, you should have everything ready to go before the 24th of June (when public scoring will begin).


### Requirements
- A server with the following minimum specifications:
  - 8GB RAM
  - 4 core CPU
  - 120GB free HDD space
  - A static IP address
- A pubkey to register your node
- Some basic linux experience, or a curious mind and the ability to follow instructions

Initial setup will take around 2 hours, though much of this will be waiting for downloads and installations. Once you have everything set up, you can expect to spend around 30 minutes per day maintaining your node.
You should also be prepared to spend some time troubleshooting if things don't go as planned, helping other participants, and monitoring the [#2024-testnet discord channel](https://komodoplatform.com/discord) for updates, events and advice.


### Rewards

During the testnet, your node's performace will be tracked, with a score applied for each notarisation. The score table will updated live and shared with the voting public. This is a great opportunity to show your skills and dedication to the community, and to earn some bragging rights (especially for new candidates which might be otherwise unknown). 

There is also the chance to win some KMD! The top 3 participants will receive 100 KMD each, along with some additional "spot prizes" for participants who demonstrate initiative, collaboration and dilligence. During the official testnet period, there will also be some "surprise" events which will provide additional opportunities to earn rewards.


## How to participate

### Step 1: Build the HF Net Komodo Daemon, and request a keypair

- Refer to https://github.com/KomodoPlatform/komodo/blob/master/README.md for instructions on how to build the Komodo daemon from source. Make sure you are on the `patch-s8-prepare-hf-test` branch.
```
# Install dependencies:
sudo apt update
sudo apt-get install build-essential pkg-config libc6-dev m4 g++-multilib autoconf libtool ncurses-dev unzip git python3 python3-zmq zlib1g-dev wget libcurl4-gnutls-dev bsdmainutils automake curl libsodium-dev

# Clone the testnet branch of the `komodo` repository
cd ~
git clone https://github.com/KomodoPlatform/komodo --branch patch-s8-prepare-hf-test --single-branch

# Build komodod
cd ~/komodo
./zcutil/fetch-params.sh
./zcutil/build.sh -j$(expr $(nproc) - 1)

# Download and extract the bootstrap archive
cd ~/.komodo
wget https://seed2.komodo.earth/boots/hfnet_blk_3940000.tar.gz
tar xvf hfnet_blk_3940000.tar.gz
rm hfnet_blk_3940000.tar.gz
```

- Set up the `~/.komodo/komodo.conf` file with the following contents:
```
addnode=65.21.52.182
addnode=54.39.17.102
addnode=168.119.236.240
addnode=168.119.236.243
addnode=95.217.21.14
server=1
daemon=1
txindex=1
port=7770
rpcbind=127.0.0.1
rpcuser=ENTER_YOUR_OWN_RPC_USERNAME_HERE
rpcpassword=ENTER_YOUR_OWN_RPC_PASSWORD_HERE
rpcport=7771
rpcworkqueue=256
```
**Note: As this is a testnet version of komodod, you will need to make sure the komodo.conf file uses only the above addnode IP addresses.**

```
# launch komodod:
cd ~/komodo/src
./komodod -addnode=65.21.52.182 -addnode=54.39.17.102 -addnode=168.119.236.240 -addnode=168.119.236.243 -addnode=95.217.21.14 &
```

- Once you have built the daemon and got it running, contact @smk, @gcharang, or @decker in the [#2024-testnet channel on Discord](https://komodoplatform.com/discord) to request a keypair.
- [Import your assigned private key](https://komodoplatform.com/en/docs/smart-chains/api/wallet/#importprivkey) into the KMD daemon.
- Use the [validateaddress](https://komodoplatform.com/en/docs/smart-chains/api/util/#validateaddress) method to confirm the import was successful, and the address / pubkey matches what was expected. This pubkey will be used to register your node on the network.

### Step 2: Install dPoW

- Clone dPoW and checkout the `2024-testnet` branch
```
cd ~
git clone https://github.com/KomodoPlatform/dPoW/ --branch 2024-testnet --single-branch
```
- Create a `pubkey.txt` file in the `~/dPoW/iguana` directory, with your pubkey in the format `pubkey=<your pubkey>`
- Create a `wp_testnet` file in the `~/dPoW/iguana` directory, with the following content:
```
curl --url "http://127.0.0.1:7762" --data "{\"method\":\"walletpassphrase\",\"params\":[\"YOUR_SEED_OR_PRIVKEY_HERE\", 9999999]}"
```
- Make it executable with `chmod +x ~/dPoW/iguana/wp_testnet`
- Open the Iguana P2P port with `sudo ufw allow 17762 comment '2024 Testnet Iguana'`


### Step 3: Setup docker and launch the other chains
During the testnet, we will notarise the DOC and MARTY test chains. We'll run these in [docker](https://www.docker.com/) containers - Follow the instructions below to install `docker` and `docker compose`.

 - [Docker](https://docs.docker.com/engine/install/ubuntu/) / [w/ convenience script](https://docs.docker.com/engine/install/ubuntu/#install-using-the-convenience-script)
 - [Docker Compose](https://docs.docker.com/compose/install/linux/#install-using-the-repository)
 - Docker linux post install steps: https://docs.docker.com/engine/install/linux-postinstall/ , Configure Docker to start on boot with systemd
 
_You can also run these chains natively if you prefer, but you will need to build the komodod binary from source again (using the `master` branch)._

Now we can build and launch DOC & MARTY chains with the following commands:
```
cd ~/dPoW/docker
./setup.sh                     # Setup misc configs
docker compose build           # Build the docker images
docker compose up -d           # Launch the chains in the background 
docker compose logs -f -n 33   # Check the logs to confirm the chains are operational
```

Once these chains are running, you will need to [import the private key](https://komodoplatform.com/en/docs/smart-chains/api/wallet/#importprivkey) you were assigned into the wallets for these chains. 

```
doc-cli importprivkey YOUR_PRIVATE_KEY
marty-cli importprivkey YOUR_PRIVATE_KEY
```

To speed up the sync process, bootstraps for DOC and MARTY are kindly supplied by CHMEX via https://eu.bootstrap.dexstats.info/DOC-bootstrap.tar.gz and https://eu.bootstrap.dexstats.info/MARTY-bootstrap.tar.gz
To use the bootstrap, first stop DOC/MARTY with `doc-cli stop && marty-cli stop && docker compose stop` then download the bootstrap archive files and extract them into the `~/.komodo/DOC` and `~/.komodo/MARTY` directories.
Once extracted, you can start the chains again with `docker compose up -d` and monitor the logs with `docker compose logs -f -n 33` to check the sync progress.


### Step 4: Fund your nodes!

- For DOC and MARTY, you can use the faucet button in the [Komodo Wallet](https://app.komodoplatform.com/#/dex) app. **DO NOT import your notary private keys into any other wallet apps. It should only ever be on your notary node server.** You can use the faucet while logged into a different wallet, and then simply send the funds to your notary node address.

- For KMD, ask in the [#2024-testnet channel on Discord.](https://komodoplatform.com/discord) As we are running `komodod` on a testnet branch, mainnet KMD will not work. 


### Step 5: Build and start Iguana

- Build iguana for notary operations
```
cd ~/dPoW/iguana
make
```

Make sure your chains are fully synced before you start notarising. You can check the status of your chains by using the [getinfo](https://komodoplatform.com/en/docs/smart-chains/api/control/#getinfo) method in the wallet API.
Once everything is ready, start testnet notarizations with `./m_notary_testnet_2024`

For Komodo, as we are using a newer build of the daemon you can also try out a the [new rpc methods](https://github.com/DeckerSU/notaries-rpc-tools) for notary nodes!

- Use `komodo-cli nn_getwalletinfo` to get a summary of your notary wallet:
```
{
  "currentSeason": 9,
  "nn_index": 1,
  "nn_name": "nodename_1",
  "pubkey": "027cc2dbc4652ec08589a557e1a01973a94186b587b140732de4589b36f95c7ac9",
  "pubkey_address": "RHvMGxDces1zvLiD9hDgjV5mUjUK7kNs7z",
  "ismine": true,
  "transactions_count": 10,
  "available_coins_count": 61,
  "notaryvins_utxos_count": 59,
  "others_utxos_count": 2
}
```
- use `komodo-cli nn_split` to split utxos:
```
{
  "tx": "18c3171362dd81a62b8e2ba568994569d7b878af098ffa6bdf7cc6df12e4ab99",
  "input_utxos_value": 0.98900000,
  "input_utxos_count": 1,
  "out_notaryvins_count": 10,
  "out_utxos_value": 0.98790000,
  "out_utxos_count": 1,
  "estimated_tx_size": 348,
  "real_tx_size": 651
}
```
You will need to make sure you have split utxos in each chain to be able to notarize. Check below under the `Bonus tips` section for a script to help you manage your utxos.

_Note: As we are running a testnet, you wont see the returned txid on the mainnet KMD block explorer. Keep an eye out in the #2024-testnet channel for a link to the testnet block explorer once it is up and running_.



### Step 6: Confirm your pubkey registration

- Make sure you have have launched the daemons with the [`pubkey` runtime parameter](https://komodoplatform.com/en/docs/smart-chains/setup/common-runtime-parameters/#pubkey), with your registered pubkey. This is required for notarisation to work. You can also add this to your `komodo.conf` file if you prefer to make sure it is included at each launch. If the chain is already running you can also use the [setpubkey](https://komodoplatform.com/en/docs/smart-chains/api/wallet/#setpubkey) method to set the pubkey.
- Once you have your daemon running, post it in the [#2024-testnet channel on Discord](https://komodoplatform.com/discord). Your assigned pubkey will be added to the [testnet.json](https://github.com/KomodoPlatform/dPoW/blob/2023-testnet/iguana/testnet.json) file, along with your discord username.
- Newly registered pubkeys will be added to the testnet network every 24 hours, and the update announced in the [#2024-testnet channel on Discord](https://komodoplatform.com/discord). Once your pubkey is merged into the testnet.json file, you can start notarising!

**Good luck! Don't be shy to ask questions and learn from the Vetern Notary Node Operators in Discord!**


## Bonus Tips

#### Create symbolic links for the komodod & komodo-cli
```
sudo ln -sf /home/$USER/komodo/src/komodo-cli /usr/local/bin/komodo-cli
sudo ln -sf /home/$USER/komodo/src/komodod /usr/local/bin/komodod
```

#### check the status of coin deamons
```
tail -f ~/.komodo/debug.log
tail -f ~/.komodo/DOC/debug.log
tail -f ~/.komodo/MARTY/debug.log
```

#### Import private key without rescanning
This will import without rescanning which is faster but will not display existing balance.
`komodo-cli importprivkey YOUR_PRIVATE_KEY "" true $(komodo-cli getblockcount)`

#### Check your balances
- `komodo-cli getbalance`
- `komodo-cli -ac_name=DOC getbalance` (or `doc-cli getbalance` if running in docker) 
- `komodo-cli -ac_name=MARTY getbalance` (or `marty-cli getbalance` if running in docker) 

If any of these returns a zero balance, make sure the chain is fully synced and that you have imported your private key correctly. If in doubt, ask for help in the [#2024-testnet channel on Discord](https://komodoplatform.com/discord).


#### Bootstrap chain data

- Make sure you stop the chain first with `komodo-cli stop` or `komodo-cli -ac_name=CHAINNAME stop`
- Delete existing chain data in `~/.komodo` or `~/.komodo/CHAINNAME`
```
rm -rf blocks/ chainstate/ database/ db.log fee_estimates.dat komodo.pid komodostate .lock notarisations/ realtime signedmasks
```
- Download bootstrap file with `wget <URL TO BOOTSTRAP>`
- Once the download is complete, extract the file with `tar -xvf <BOOTSTRAP FILE>`


#### Wallet whitelist filter
- To mitigate potential spam attacks, you can implement a whitelist filter which only allows funds incoming from certain addresses. This can be done by adding the following to your `komodo.conf` or `CHAINNAME.conf` files:
```
whitelistaddress=R9gWj7fzSxZtJZCSDMQz5G5J7x4rg6UmiQ # Test coin faucet address (leave this as is)
whitelistaddress=YOUR_NODE_KMD_ADDRESS # Your registered KMD address (MUST be included, or else split utxos will not be available for notarisation)
```
Add any extra addresses like your [Komodo Wallet](https://app.komodoplatform.com/) address which you might be sending funds from. If funds are recieved from a non-whitelisted address, they will be ignored (though they may still be visible on the block explorer). There are ways to recover these hidden funds which will be revealed to participants during the testnet.


#### Create a splitfunds script

Create split script called `split_testnet.sh`. Use the following template as an example. 

```
#!/bin/bash

SHELL=/bin/sh PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin

conf_dir="/home/YOUR_USERNAME/.komodo/"
source /home/YOUR_USERNAME/dPoW/iguana/pubkey.txt
min_uxto=20
split_num=50

echo
echo $(date)
echo "Using pubkey $pubkey for splits (${split_num} per chain)..."
echo

chain="KMD"
unspent=$(komodo-cli -conf=${conf_dir}/komodo.conf listunspent | jq '[.[] | select (.generated==false and .amount==0.0001 and .spendable==true and (.scriptPubKey == "'21${pubkey}ac'"))] | length')
echo "${chain}: $unspent"
  if [ $unspent -lt $min_uxto ]; then
    echo "Topping up ${chain}"
    komodo-cli nn_split $split_num
fi

for chain in "DOC" "MARTY"
do
    unspent=$(komodo-cli -ac_name=${chain} -conf=${conf_dir}/${chain}/${chain}.conf listunspent | jq '[.[] | select (.generated==false and .amount==0.0001 and .spendable==true and (.scriptPubKey == "'21${pubkey}ac'"))] | length')
    echo "${chain}: $unspent"
      if [ $unspent -lt $min_uxto ]; then
        echo "Topping up ${chain}"
        komodo-cli -ac_name=${chain} nn_split $split_num
    fi
done

echo
echo "Finished!"
echo
```

Make it executable with `chmod +x split_testnet.sh`

Add a crontab entry for this script so it will ensure you have enough UTXOs when you are asleep.

Open the cron job editor with `crontab -e`
Add the following entry: `0 * * * * /home/YOUR_USERNAME/split_testnet.sh > /home/YOUR_USERNAME/testnet_splits.log 2>&1`

This will check/replenish your UTXOs every hour

#### Extra resources

- Example `systemd` service file for KMD deamon & smartchains - https://github.com/smk762/DragonhoundTools/blob/master/server/systemd/komodo-deamon.service
- Webworker's scripts and tools https://github.com/webworker01/nntools
- Older tools (possibly outdated) https://github.com/KomodoPlatform/komodotools

There are various scripts current and past notaries have created to help manage their nodes. Some of these are hidden in the Discord archives, some are in the repos above. Pay attention, and ask the right questions to find the tools you need to help you manage your node.

**Got more? Share them in the Discord #2024-testnet channel!**


## Troubleshooting

### HELP! I can't split my funds!

Sometimes, even when everything else looks ok, you might still see `"error":"couldnt create duplicates tx"`
Here's a trick which might help. Send all your funds to your own address. E.g.
`komodo-cli sendtoaddress YOUR_ADDRESS $(komodo-cli getbalance) "" "" true`

The `"" "" true` bit at the end basically means "take fee from the funds sent" so it effectively merges all your utxos into one. Once that transaction confirms, try another split. _There are also scripts available which can help you automate this process via raw transaction hex generation which will include utxos which may have been blocked by the wallet whitelist filter._

You should also check the following:
- Does your `wp_testnet` file have the correct private key / seed associated with your pubkey?
- Is your `wp_testnet` file executable?
- Does your `wp_testnet` file have the correct RPC port?
- Are you trying to spend unconfirmed or coinbase funds?
- Does your `pubkey.txt` file contain the correct pubkey? 
- Does your `split_testnet.sh` SCRIPT use the correct path to source the pubkey? 
- Is your private key imported in to all chains?
- Are all chains synced?
- Are you running the latest version of iguana?

If all else fails, it may be a corrupted wallet.dat or local chain data. Make sure you have backed up your private key, then delete the chain data and wallet.dat file. Next, resync or bootstrap the chain. Don't forget to re-import your private key!

**If you are still having issues, ask for help in the Discord #2024-testnet channel.**
