### dPoW 0.7.1 update information

- On your 3P node, update your Verus Coin's codebase to [`66e16e7`](https://github.com/VerusCoin/VerusCoin/tree/66e16e79c8c3f60279952b2b36a8b06d4d7a81de), build it and then restart it.

#### If using smk's docker setup

```bash
cd notary_docker_3p
git pull
./update vrsc #supply sudo password when asked
./start vrsc
```

#### If custom setup

- Build Verus Coin

```bash
cd ~/VerusCoin
git pull
git checkout 66e16e7
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
