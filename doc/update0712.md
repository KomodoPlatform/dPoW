### dPoW 0.7.12 update information

On your **3P node**:

- update your Verus Coin's codebase to [`1121528`](https://github.com/VerusCoin/VerusCoin/commit/11215289254c490b2ed146612e1504376d0964eb), build it and then restart it.

### Update VSRC

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
vrsc_commit='1121528'
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


### Remove THC

- Shut down the THC daemon on the **main server**. This coin has been removed from the dPoW assets.

```bash
komodo-cli -ac_name=THC stop
```

- Please remember to delete the remaining data folder located in `~/.komodo/THC` and close the THC p2p port (`36789`) in the firewall.

### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Please restart dPoW operations and ensure that your iguana is running smoothly.
