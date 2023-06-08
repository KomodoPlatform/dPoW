dPoW 0.7.0 update information


Please update iguana and ensure your NN infrastructure is ready for Season 7.
```
cd ~/dPoW
git checkout master
git pull
```

# Kill iguana, rebuild and start it

```
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_build
```

Then launch with `./m_notary_3rdparty` or `./m_notary_main` based on the server

Please note that iguana ports were changed to 13348 for main and 13345 3rd party networks.

After git pull restart your iguana and adjust your firewall settings accordingly, e.g. :

- `sudo ufw allow 13348/tcp comment 'iguana s7 mainnet p2p'`
- `sudo ufw allow 13345/tcp comment 'iguana s7 3rd p2p' `