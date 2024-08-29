# dPoW 0.7.16 update information


### Stop and remove `VOTE2024`

```bash
komodo-cli -ac_name=VOTE2024 stop
rm -rf ~/.komodo/VOTE2024
```

### Update `komodod` to the latest version.

```bash
cd ~/komodo/src/
git checkout master && git pull
./zcutil/build.sh -j$(nproc)
```
Once built, stop and restart KMD and all smartchains on the main server.

Repeat the update for your 3P komodo daemon. If you are using docker container repo for 3P:

```bash
cd ~/notary_docker_3p
./update
./start
```


### Update `mm2` to the latest version.

Download the latest `mm2` release from the [releases page](https://github.com/KomodoPlatform/komodo-defi-framework/releases/tag/v2.1.0-beta), replace your existing `mm2` binary, then restart `mm2`.

If using the docker container, pull the latest and restart the container.

```bash
cd ~/notary_docker_3p
./update mm2
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
./m_notary_main
./m_notary_3rdparty
```

Make sure notarisations are progressing.
