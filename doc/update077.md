### dPoW 0.7.7 update information

- On your 3P node, update your Verus Coin's codebase to [``](https://github.com/VerusCoin/VerusCoin/tree/), build it and then restart it.

#### If using smk's docker setup

```bash
cd notary_docker_3p
git pull
./update vrsc # supply sudo password when asked
./start vrsc
./update mm2 # supply sudo password when asked
./start mm2
```

#### If custom setup

- Build Verus Coin

```bash
vrsc_commit=''
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

- Update your seednode

```bash
cd ~/nn_mm2_seed
git pull
./update_mm2.sh
./update_conf.py
./run_mm2.sh && tail -f mm2.log
```


#### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Make sure your 3P iguana is running properly and notarising.
Confirm your MM2 node is running, your certificates are up to date, and your node is finding peers on netID 8762.
```bash
sudo apt install snapd
sudo snap install certbot --classic
sudo certbot certonly -d ${DOMAIN}
# or, if certs exist already
sudo certbot renew
```
