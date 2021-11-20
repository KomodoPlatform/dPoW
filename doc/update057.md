### dPoW 0.5.7 update information

-On your 3P node, update your Verus Coin's codebase to [4c7a0a6](https://github.com/VerusCoin/VerusCoin/tree/4c7a0a68dd87a17da483086cddeeb436f1d23698), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout 4c7a0a6
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
```

-On your 3P node, update your TOKEL Coin's codebase to [4302bb3](https://github.com/KomodoPlatform/komodo/tree/4302bb3cf803f5835d875630f7795d744a0f8253), build it and then restart it

```bash
cd ~/tokelkomodo
git pull
git checkout 4302bb3
./zcutil/build.sh
```

- Restart it

```bash
cd ~/tokelkomodo/src
./komodo-cli -ac_name=TOKEL stop
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=TOKEL -ac_supply=100000000 -ac_eras=2 -ac_cbmaturity=1 -ac_reward=100000000,4250000000 -ac_end=80640,0 -ac_decay=0,77700000 -ac_halving=0,525600 -ac_cc=555 -ac_ccenable=236,245,246,247 -ac_adaptivepow=6 -addnode=135.125.204.169 -addnode=192.99.71.125 -addnode=144.76.140.197 -addnode=135.181.92.123 -pubkey=$pubkey &
```

-On your 3P node, update your CHIPS Coin's codebase to [a2a33eb](https://github.com/chips-blockchain/chips/tree/a2a33ebcda8b2d5746b9622b34ecd99ec1505f31), build it and then restart it

```bash
cd ~/chips
git pull
git checkout a2a33eb
```

Build it based on instructions here: [https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#chips](https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#chips)

- Restart it

```bash
cd ~/chips/src
./chips-cli stop
source ~/dPoW/iguana/pubkey.txt
./chipsd -pubkey=$pubkey &
```

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
