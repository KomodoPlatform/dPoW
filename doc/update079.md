## dPoW 0.7.9 update information

- On your 3P node, update your Verus Coin's codebase to [`81e7a80`](https://github.com/VerusCoin/VerusCoin/tree/81e7a80271e230a132afb44967ea26f781439995), build it and then restart it.
- On your main and 3P nodes, update your komodod to [`41265fb`](https://github.com/KomodoPlatform/komodo/tree/41265fb26d51e4f629b3dadcc92aa19e6867a76e), build it and then restart it

### Update VSRC & KMD

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
vrsc_commit='54e0cf2'
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

- Build Komodod (main and 3p)

```bash
kmd_commit='41265fb'
cd ~/komodo
git pull
git checkout ${kmd_commit}
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart komodo (main)

```bash
cd ~/komodo/src
./komodo-cli stop
source ~/dPoW/iguana/pubkey.txt
./komodod  -gen -genproclimit=1 -minrelaytxfee=0.000035 -opretmintxfee=0.004 -notary=.litecoin/litecoin.conf -pubkey=$pubkey &
```

- Restart komodo (3p)

```bash
cd ~/komodo/src
./komodo-cli stop
source ~/dPoW/iguana/pubkey.txt
./komodod -minrelaytxfee=0.000035 -opretmintxfee=0.004 -notary -pubkey=$pubkey &
```

#### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Once complete, monitor your node to ensure it is running correctly and notarisations are progressing.

