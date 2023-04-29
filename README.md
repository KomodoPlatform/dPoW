This guide assumes you have already completed the steps in the following links:
- https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04
- https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#initial-server-setup
- https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#install-komodo-by-compiling-it-from-source

Recommended specs for a minimal testnet machine are 8gb of RAM, 4 core CPU, 60 GB of HDD space and a static IP.
After building komodod in the above guides - stop. You dont need LTC or any third party chains for the testnet.


### Clone dPoW and checkout the testnet branch
```
git clone https://github.com/KomodoPlatform/dPoW/
git checkout 2023-testnet
```

### Create pubkey.txt
`echo "pubkey=<pubkey>" > ~/dPoW/iguana/pubkey.txt`


### Create wp_testnet and make it executable
```
echo 'curl --url "http://127.0.0.1:7779" --data "{\"method\":\"walletpassphrase\",\"params\":[\"YOUR_SEED_OR_PRIVKEY_HERE\", 9999999]}"' > ~/dPoW/iguana/wp_testnet
chmod +x ~/dPoW/iguana/wp_testnet
```

### Open Iguana p2p port
`sudo ufw allow 17778 comment '2023 Testnet Iguana'`


### Create symbolic links for the komodod & komodo-cli
```
sudo ln -sf /home/$USER/komodo/src/komodo-cli /usr/local/bin/komodo-cli
sudo ln -sf /home/$USER/komodo/src/komodod /usr/local/bin/komodod
```

### Bootstrap KMD
```
# stop komodo
komodo-cli stop

# delete existing data
cd ~/.komodo
rm -rf blocks/ chainstate/ database/ db.log fee_estimates.dat komodo.pid komodostate .lock notarisations/ realtime signedmasks

# download bootstrap
wget https://eu.bootstrap.dexstats.info/KMD-bootstrap.tar.gz

# wait 15 minutes to download then extract
tar xvf KMD-bootstrap.tar.gz

```

### Start KMD, DOC and MARTY

Create a file named `launch_testnet_chains.sh` and add the launch parameters.
```
#!/bin/bash

source ~/dPoW/iguana/pubkey.txt

komodod -pubkey=$pubkey &
komodod -ac_name=MARTY -ac_supply=90000000000 -ac_reward=100000000 -ac_cc=3 -ac_staked=10 -addnode=65.21.77.109 -addnode=65.21.51.47 -pubkey=$pubkey &
komodod -ac_name=DOC -ac_supply=90000000000 -ac_reward=100000000 -ac_cc=3 -ac_staked=10 -addnode=65.21.77.109 -addnode=65.21.51.47 -pubkey=$pubkey &
```

Make the script executable with `chmod +x launch_testnet_chains.sh`, then launch the chains with `./launch_testnet_chains.sh`

You can check the status of these chains with
```
tail -f ~/.komodo/debug.log
tail -f ~/.komodo/DOC/debug.log
tail -f ~/.komodo/MARTY/debug.log
```


### Import your private key to all chains
```
komodo-cli importprivkey YOUR_PRIVATE_KEY "" true $(komodo-cli getblockcount) # This will import without rescanning which is faster but will not display existing balance.
komodo-cli -ac_name=DOC importprivkey YOUR_PRIVATE_KEY
komodo-cli -ac_name=MARTY importprivkey YOUR_PRIVATE_KEY
```

Send some funds to your notary node chain addresses. If you need some DOC/MARTY, ask Alright or Smk. If you need some KMD, post a DOC/MARTY meme in the Discord testnet channel with your address below and if its funny enough, charity may follow.


### Create a splitfunds script

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
    curl --url "http://127.0.0.1:7779" --data "{\"coin\":\""${chain}"\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":"${split_num}"}"
fi

for chain in "DOC" "MARTY"
do
    unspent=$(komodo-cli -ac_name=${chain} -conf=${conf_dir}/${chain}/${chain}.conf listunspent | jq '[.[] | select (.generated==false and .amount==0.0001 and .spendable==true and (.scriptPubKey == "'21${pubkey}ac'"))] | length')
    echo "${chain}: $unspent"
      if [ $unspent -lt $min_uxto ]; then
        echo "Topping up ${chain}"
        curl --url "http://127.0.0.1:7779" --data "{\"coin\":\""${chain}"\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":"${split_num}"}"
    fi
done

echo
echo "Finished!"
echo

```

Make it executable with `chmod +x split_testnet.sh`

Add a crontab entry for this script so it will ensure you have enough UTXOs when you are asleep.

Open the cron job editor with `crontab -e`
Add the following entry: `0 * * * * /home/YOURUSERNAME/split_testnet.sh > /home/YOURUSERNAME/testnet_splits.log 2>&1`

This will check/replenish your UTXOs every hour

Before beginning to notarize, your pubkey must be added to all nodes. Open a pull request to this branch adding your pubkey to the [testnet.json](https://github.com/KomodoPlatform/dPoW/blob/2023-testnet/iguana/testnet.json) file. Please ensure you include your discord username within this pull request. You will be pinged on discord when your pubkey is had been added and is ready to notarize.


### Start Iguana
```
cd ~/dPoW/iguana
./m_notary_build
./m_notary_testnet_2023
```

Good luck! Don't be shy to ask questions and learn from the Vetern Notary Node Operators in Discord! 


### Extra resources

Example `systemd` service file for KMD deamon & smartchains - https://github.com/smk762/DragonhoundTools/blob/master/server/systemd/komodo-deamon.service
Useful scripts and tools - https://github.com/webworker01/nntools


### HELP! I can't split my funds!

Sometimes, even when everything else looks ok, you might still see `"error":"couldnt create duplicates tx"`
Here's a trick which might help. Send all your funds to your own address. E.g.
`komodo-cli sendtoaddress YOUR_ADDRESS $(komodo-cli getbalance) "" "" true`

The `"" "" true` bit at the end basically means "take fee from the funds sent" so it effectively merges all your utxos into one. Once that transaction confirms, try another split.

You should also check the following:
- Does your `wp_testnet` file have the correct private key / seed associated with your pubkey?
- Is your `wp_testnet` file executable?
- Are you trying to spend unconfirmed or coinbase funds?
- Does your `pubkey.txt` file contain the correct pubkey? 
- Does your `split_testnet.sh` use the correct path to source the pubkey? 
- Is your private key imported in to all chains?
- Are all chains synced?
- Are you running the latest version of iguana?

If all else fails, it may be a corrupted wallet.dat or local chain data. Make sure you have backed up your private key, then delete the chain data and wallet.dat file. Next, resync or bootstrap the chain. Don't forget to re-import your private key!

If you are still having issues, ask for help in the Discord testnet channel.
