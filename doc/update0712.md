## dPoW 0.7.11 update information

On your 3P node:

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

### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Once complete, monitor your node to ensure it is running correctly and notarisations are progressing. Make sure any certs for your seednode are up to date and have no permssions issues, and that your wss connection is responding. If you have any issues, please contact us on Discord.
