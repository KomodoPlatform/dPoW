## dPoW 0.7.10 update information

- On your 3P node, update your Verus Coin's codebase to [`f9abd80`](https://github.com/VerusCoin/VerusCoin/tree/f9abd801e22232d69e1ae4bf486e99264910e639), build it and then restart it.
- On your 3P node, update your Tokel codebase to [`28939c1`](https://github.com/VerusCoin/VerusCoin/tree/f9abd801e22232d69e1ae4bf486e99264910e639), build it and then restart it.

### Update VSRC & TKL

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

- Build Tokel

```bash
tkl_commit='28939c1'
cd ~/tokel
git pull
git checkout ${tkl_commit}
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/tokel/src
./tokeld stop
source ~/dPoW/iguana/pubkey.txt
./tokeld -pubkey=$pubkey &
```


#### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Once complete, monitor your node to ensure it is running correctly and notarisations are progressing.

