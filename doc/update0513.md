### dPoW 0.5.13 update information

- On your main node, sync the `VOTE2022` coin and start dPoW operations for it

#### On Main node

##### Launch the `VOTE2022` chain on your main node

```bash
cd ~/komodo/src
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_public=1 -ac_name=VOTE2022 -ac_supply=141331546 -ac_staked=10 -addnode=77.74.197.115 -pubkey=$pubkey &
```

- Import your KMD/Smart Chain privkey for main node to the `VOTE2022` chain

```bash
cd ~/komodo/src
./komodo-cli -ac_name=VOTE2022 importprivkey ***
```

- Open `tcp/33897` for incoming p2p connections:

```bash
sudo ufw allow 33897/tcp comment 'VOTE2022 p2p port'
```

- Add `VOTE2022` to your autosplit script(s)
- Update your dPoW repo, rebuild and restart iguana

```bash
cd ~/dPoW
git checkout master
git pull
cd ~/dPoW/iguana
./m_notary_build
pkill -15 iguana
./m_notary_LTC # start notarization
```

- Make sure your iguana is running properly
- Split `VOTE2022` UTXO's once iguana is running
- An explorer for the chain: [https://vote.kmdexplorer.io/](https://vote.kmdexplorer.io/)
- Each notary address has received 77.77777777 VOTE2022 tokens. Stake them using the following command: `./komodo-cli -ac_name=VOTE2022 setgenerate true 0`
