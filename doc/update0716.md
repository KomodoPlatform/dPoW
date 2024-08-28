# dPoW 0.7.16 update information

This update moves the existing GLEEC chain to the 3rd party node, and launches a new GLEEC chain on the main server. Both will be protected by dPoW until the start of the next notary season.


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

Repeat the update for your 3P komodo daemon (if using the docker containers repo, you can skip this step).


### Update `mm2` to the latest version.

Download the latest `mm2` release from the [releases page](https://github.com/KomodoPlatform/komodo-defi-framework/releases/tag/v2.1.0-beta), replace your existing `mm2` binary, then restart `mm2`.

If using the docker container, pull the latest and restart the container.

```bash
cd ~/notary_docker_3p
./update mm2
```

### Stop GLEEC (OLD), move data and send balance to 3p address

```bash
komodo-cli -ac_name=GLEEC sendtoaddress RUq3kkWUU5UdbVwmLeMHAST7SCyfgNZsBA $(komodo-cli -ac_name=GLEEC getbalance) "" "" true
komodo-cli -ac_name=GLEEC stop
mv ~/.komodo/GLEEC/ ~/.komodo/GLEEC_OLD/
mv ~/.komodo/GLEEC_OLD/wallet.dat ~/.komodo/GLEEC_OLD/wallet.bak
```

### Start GLEEC (new) on main server with new launch params

```bash
source ~/dPoW/iguana/pubkey.txt
komodod -pubkey=$pubkey -ac_name=GLEEC -ac_supply=1000000000 -ac_end=1 -ac_public=1 -ac_staked=50 -addnode=65.21.52.182 -addnode=135.181.80.132 &

# Import your private key
komodo-cli -ac_name=GLEEC importprivkey ${YOUR_MAIN_PRIVATE_KEY}
```

# Open GLEEC (new) P2P Port
    
```bash
sudo ufw allow 23344/tcp comment 'GLEEC p2p port'
```

### Restart GLEEC (OLD) on 3rd Party node

If you are **not** using docker container repo for 3P, launch GLEEC (old) including the `datadir` parameter:

```bash
source ~/dPoW/iguana/pubkey_3p.txt
komodod -pubkey=$pubkey -ac_name=GLEEC -ac_supply=210000000 -ac_public=1 -ac_staked=100 -addnode=95.217.161.126 -addnode=209.222.101.247 -addnode=103.195.100.32 -datadir=${HOME}/.komodo/GLEEC_OLD &
```

If you are using docker container repo for 3P:

```bash
cd ~/notary_docker_3p
./update
./start
```

Import your 3P private key into the GLEEC (OLD) chain.
    
```bash
komodo-cli -ac_name=GLEEC -conf=${HOME}/.komodo/GLEEC_OLD importprivkey ${YOUR_3P_PRIVATE_KEY} 
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
