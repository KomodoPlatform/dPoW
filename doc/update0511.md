### dPoW 0.5.11 update information

- On your main node, delete the GLEEC coin and stop dPoW operations for it
- On your main node, sync the CLC coin and start dPoW operations for it

#### Stop the `GLEEC` chain on your main node

```bash
cd ~/komodo/src
./komodo-cli -ac_name=GLEEC stop
```

- Wait for it to stop properly and delete its data directory if you need the extra space

```bash
rm -rf ~/.komodo/GLEEC
```

- Remove GLEEC from to your autosplit script(s) and remove its p2p port (`tcp/23225`) from the allow list in your firewall

#### Launch the `CLC` chain on your main node with the new parameters

```bash
cd ~/komodo/src
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=CLC -ac_supply=99000000 -ac_reward=50000000 -ac_perc=100000000 -ac_founders=1 -ac_cc=45 -ac_public=1 -ac_snapshot=1440 -ac_pubkey=02df9bda7bfe2bcaa938b29a399fb0ba58cfb6cc3ddc0001062a600f60a8237ad9 -addnode=node.cryptocollider.com -ac_adaptivepow=6 -pubkey=$pubkey &
```

- Import your KMD/Smart Chain privkey for main node to the CLC chain

```bash
cd ~/komodo/src
./komodo-cli -ac_name=CLC importprivkey ***
```

- Open `tcp/20931` for incoming p2p connections:

```bash
sudo ufw allow 20931/tcp comment 'CLC p2p port'
```

- Add CLC to your autosplit script(s)

- Update your dPoW repo, rebuild and restart iguana

```bash
cd ~/dPoW
git checkout master
git pull
cd ~/dPoW/iguana
./m_notary_build
pkill -15 iguana
./m_notary_KMD # start notarization
```

- Make sure your iguana is running properly
- Split CLC UTXO's once Iguana is running
