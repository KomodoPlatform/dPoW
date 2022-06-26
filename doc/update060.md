dPoW 0.6.0 update information


Please update iguana and ensure your NN infrastructure is ready for Season 6.
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

Please note that iguana ports were changed to 13347 for main and 13344 3rd party networks.

After git pull restart your iguana and adjust your firewall settings accordingly, e.g. :

- `sudo ufw allow 13347/tcp comment 'iguana s6 mainnet p2p'`
- `sudo ufw allow 13344/tcp comment 'iguana s6 3rd p2p' `

## Notes for Veterans running VRSC / CHIPS / MIL overtime

- Open port `sudo ufw allow 14441/tcp comment 'iguana s6 vrsc p2p'`
- Copy wp file `cp wp_7779 wp_7171`
- Edit the port number in wp_7171 to 7171
- Launch `./m_notary_verusholdover`
