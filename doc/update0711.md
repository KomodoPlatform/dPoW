## dPoW 0.7.11 update information

On your 3P node:

- update your Verus Coin's codebase to [`8a060c6`](https://github.com/VerusCoin/VerusCoin/tree/8a060c63b5b1d8295b754080e0f07966b09776d3), build it and then restart it.

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
vrsc_commit='f9abd80'
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


#### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Once complete, monitor your node to ensure it is running correctly and notarisations are progressing.
