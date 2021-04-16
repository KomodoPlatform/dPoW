### dPoW 0.3.9 update information

Stop the GLEEC coin

```
./komodo-cli -ac_name=GLEEC stop
```

Wait for it to stop properly and delete its data directory

```
rm -rf ~/.komodo/GLEEC
```

- Launch the `GLEEC` chain on your main node with the new parameters

```
./komodod -ac_name=GLEEC -ac_supply=210000000 -ac_public=1 -ac_staked=100 -addnode=95.217.161.126 -pubkey=$pubkey &
```

- Import your privkey

```
./komodo-cli -ac_name=GLEEC importprivkey ***
```

- Open `tcp/23225` for incoming p2p connections:

```
sudo ufw allow 23225/tcp comment 'GLEEC p2p port'
```

- Add GLEEC to your autosplit script(s)

assetchains.json additions below:

```
  {
    "ac_name": "GLEEC",
    "ac_supply": "210000000",
    "ac_public": "1",
    "ac_staked": "100",
    "addnode":["95.217.161.126"]
  }
```

- Update your dPoW repo, restart iguana

```bash
cd ~/dPoW
git checkout master
git pull
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_KMD # start notarization
```

Make sure your iguana is running properly.

- Split GLEEC UTXO's once Iguana is running
