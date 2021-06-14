### dPoW Season 5 update informations:

<b>Please update iguana and ensure your NN infrastructure is ready for S5.</b>

Please note that iguana ports were changed to 13337 for main and 13334 3rd party networks

After `git pull` restart your iguana and adjust your firewall settings accordingly, e.g. :

```
sudo ufw allow 13337/tcp comment 'iguana mainnet p2p'
sudo ufw allow 13334/tcp comment 'iguana 3rd p2p'
```
