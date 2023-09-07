### dPoW 0.7.6 update information

- On your 3P node, update your Verus Coin's codebase to [`25f82df`](https://github.com/VerusCoin/VerusCoin/tree/25f82df12aee24c64681ca69ddd21ae19528fe25), build it and then restart it.

#### If using smk's docker setup

```bash
cd notary_docker_3p
git pull
./update vrsc # supply sudo password when asked
./start vrsc
```

#### If custom setup

- Build Verus Coin

```bash
cd ~/VerusCoin
git pull
git checkout 25f82df
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

Make sure your 3P iguana is running properly.
