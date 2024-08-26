# dPoW 0.7.16 update information

## On your **Main node**

### Stop and remove `VOTE2024` and `GLEEC` chains

```bash
komodo-cli -ac_name=VOTE2024 stop
komodo-cli -ac_name=GLEEC stop
rm -rf ~/.komodo/VOTE2024
rm -rf ~/.komodo/GLEEC
```

### Restart GLEEC with new launch params

```bash
source ~/dPoW/iguana/pubkey.txt
komodod -pubkey=$pubkey -ac_name=GLEEC -ac_supply=1000000000 -ac_end=1 -ac_public=1 -ac_staked=50 -addnode=65.21.52.182 -addnode=135.181.80.132 &

# Import your private key
komodo-cli -ac_name=GLEEC importprivkey "yourprivkey"

# Open GLEEC P2P Port
sudo ufw allow 23344/tcp comment 'GLEEC p2p port'
```


### Update `komodod` and `mm2` to the latest version.

```bash
cd ~/komodo/src/
git checkout master && git pull
./zcutil/build.sh -j$(nproc)
```

Once built, stop and restart KMD and all smartchains on the main server.
Repeat the update for your 3P komodo daemon.

Download the latest `mm2` release from the [releases page](https://github.com/KomodoPlatform/komodo-defi-framework/releases/tag/v2.1.0-beta), replace your existing `mm2` binary, then restart `mm2`.

If using the docker container, pull the latest and restart the container.

```bash
cd ~/notary_docker_3p
./update mm2
./update
./start
```



### Restart Iguana

```bash
# Update dPoW repo
cd ~/dPoW
git checkout master
git pull

# Restart Iguana
pkill -9 iguana
cd iguana
./m_notary_build
./m_notary_main && ./m_notary_3rdparty
```

Make sure notarisations are progressing.
