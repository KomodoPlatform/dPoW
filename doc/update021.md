### dPoW 0.2.1 update informations:

<b>Please update iguana to 0.2.1 and ensure your NN infrastructure is ready for S4.</b>

Please note that iguana ports were changed to 17773 for main and 17774 3rd party networks

After `git pull` restart your iguana and adjust your firewall settings accordingly, e.g. :

```
sudo ufw allow 17773/tcp comment 'iguana mainnet p2p'
sudo ufw allow 17774/tcp comment 'iguana 3rd p2p'
```
