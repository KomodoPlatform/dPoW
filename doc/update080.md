## dPoW 0.8.0 update information

- On your 3P node, update your Verus Coin's codebase to [`b6b8957`](https://github.com/VerusCoin/VerusCoin/tree/b6b89577ab09fb2c1c0d7cf9523ebe82572341f6), build it and then restart it.

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
vrsc_commit='b6b8957'
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
