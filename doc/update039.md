### dPoW 0.3.9 update information

- Launch and sync `GLEEC` on your main node in the usual way

Useful info:

- Check the correct chain params:

```
-ac_name=GLEEC -ac_supply=21000000 -ac_public=1 -ac_staked=100 -addnode=95.217.161.126
```

- Open `tcp/33300` for incoming p2p connections:

```
sudo ufw allow 33300/tcp comment 'GLEEC p2p port'
```

- Don't forget to add split commands for 33300 to your autosplit script(s)
- Update your dPoW repo and restart iguana

```bash
cd ~/dPoW
git checkout master
git pull
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_build # build iguana
./m_notary_KMD # start notarization
```

Make sure your iguana is running properly.
