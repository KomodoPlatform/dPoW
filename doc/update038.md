### dPoW 0.3.8 update information

- Launch and sync `VOTE2021` on your main node in the usual way

Useful info:

- Check the correct chain params:
```
-ac_public=1 -ac_name=VOTE2021 -ac_supply=129848152 -addnode=77.74.197.115
```
- Open `tcp/55637` for incoming p2p connections:
```
sudo ufw allow 55637/tcp comment 'VOTE2021 p2p port'
```
- Don't forget to add split commands for VOTE2021 to your autosplit script(s)
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
