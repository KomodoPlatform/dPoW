# dPoW 0.8.5 update information

This update introduces an automatic checkpoint system in komodod to replace dPoW (Delayed Proof of Work) which is being sunset on January 4-5, 2026.
Related Komodod pull request: https://github.com/GLEECBTC/komodo-daemon/pull/672
Related Komodod release: https://github.com/GLEECBTC/komodo-daemon/releases/tag/v0.9.2


### Stop, Update and restart KMD, TKL and all assetchains

```bash
# Rebuild KMD
komodo-cli stop # repeat for KMD 3P and all assetchains
cd ~/komodo
git pull
git checkout e0f463a 
./zcutil/build.sh -j$(expr $(nproc) - 1)
source ~/dPoW/pubkey.txt
komodod -pubkey=${pubkey} & # repeat for KMD 3P and all assetchains

# Rebuild TKL
komodo-cli -ac_name=TOKEL stop
cd ~/tokel
git pull
git checkout 96234b4
./zcutil/build.sh -j$(expr $(nproc) - 1)
source ~/dPoW/pubkey.txt
tokeld -pubkey=${pubkey} &
```


#### If using docker:
```bash
# Main server
cd ~/notary_docker_main
git checkout main && git pull
./start # This wil stop, recreate compose file, then rebuild and restart

# 3P server
cd ~/notary_docker_3p
git checkout main && git pull
./start # This wil stop, recreate compose file, then rebuild and restart
```

Once all coin RPCs are ready and responding:

### Restart Iguana

```bash
# Update dPoW repo
cd ~/dPoW
git checkout master
git pull

# Restart Iguana
pkill -9 iguana
sleep 2
mkdir -p ~/logs
cd ~/dPoW/iguana
./m_notary_3rdparty_docker > ~/logs/iguana_3p.log &
./m_notary_main > ~/logs/iguana_main.log &
tail -f ~/logs/iguana_*.log

```

If using [dragon_node](https://github.com/smk762/dragon_node), it has also been updated.

Monitor logs afterwards to confirm notarisations are progressing.

