# dPoW 0.7.16 update information


### Stop and remove `VOTE2024`

```bash
komodo-cli -ac_name=VOTE2024 stop
rm -rf ~/.komodo/VOTE2024
```

### Update `komodod` to the latest version on main and 3p nodes.

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

**NOTE:** If your blockchain data folder contains data from an older daemon version (before we switched to the 0.7.x versioning, such as 3.x.x), you might encounter this error when starting the 0.9.0 daemon:

```bash
2024-08-21 18:49:12 ERROR: LoadBlockIndex() : failed to read value
2024-08-21 18:49:12 : Error loading block database.
error in HDD data, might just need to update to latest, if that doesn't work, then you need to resync.
```

__This should only be an issue on verteran nodes that have been running for a long time without a recent "sync from scratch"__. 

In this case, you have several options:

- Resync from scratch (slowest but most accurate, allowing your node to recalculate value pools).
- Bootstrap from [dexstats.info](https://dexstats.info/bootstrap.php) (fastest, but since the initial sync version is unknown, value pools might be incorrectly calculated). Value pools refer to the stats for transparent, sprout, sapling, and burned chain values.
- Reindex with `-reindex` (but options `resync` and `bootstrap` are recommended).

@decker has provided a [script](https://raw.githubusercontent.com/DeckerSU/komodo_scripts/master/restart_kmd_daemons.sh) to simplify the upgrade process. Just run it on a host with launched Komodo daemons within a directory containing the new version of komodod and komodo-cli, and all launched instances will be stopped and re-launched with the new version of the daemon. Very convenient!

__This script is not compatible with the docker container setup on 3P, but these were likely sync'd from scratch recently enough to not encounter this error__



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
./m_notary_{main,3rdparty} # use the appropriate script that matches your node type (main or 3p).
```

Make sure notarisations are progressing.
