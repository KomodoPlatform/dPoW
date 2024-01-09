## dPoW 0.7.11 update information

On your 3P node:

- update your Verus Coin's codebase to [`8a060c6`](https://github.com/VerusCoin/VerusCoin/tree/8a060c63b5b1d8295b754080e0f07966b09776d3), build it and then restart it.

### Update VSRC and Komodo DeFi Framework

#### Using docker setup

```bash
cd notary_docker_3p
git pull
./update
./start
```

#### Using other setup

- Build Verus Coin

```bash
vrsc_commit='8a060c6'
cd ~/VerusCoin
git pull
git checkout ${vrsc_commit}
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
```

- Manually update your mm2 to the [latest release](https://github.com/KomodoPlatform/komodo-defi-framework/releases/tag/v2.0.0-beta)
- Edit your MM2.json file to change the netid from `7777` to `8762`
- Open the following ports on your firewall: `42845` (tcp), `42855` (wss)

### Update 


#### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Once complete, monitor your node to ensure it is running correctly and notarisations are progressing. Make sure any certs for your seednode are up to date and have no permssions issues, and that your wss connection is responding. If you have any issues, please contact us on Discord.
