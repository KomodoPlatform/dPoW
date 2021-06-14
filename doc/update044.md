### dPoW 0.4.4 update information

- Update your MCL Coin's codebase to [2412d5f](https://github.com/marmarachain/marmara/tree/2412d5f5434a6b31f86da934d53df1729956654b), build it and then restart it
- Update your AYA Coin's codebase to [<>](https://github.com/KomodoPlatform/AYAv2/tree/<>), build it and then restart it

#### MCL

```bash
cd ~/Marmara-v.1.0
git pull
git checkout 2412d5f
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/Marmara-v.1.0/src/
./komodo-cli -ac_name=MCL stop
source ~/dPoW/iguana/pubkey.txt
./komodod -pubkey=$pubkey &
```

#### AYA

```bash
cd ~/AYAv2/
# git reset --hard # (if necessary)
git pull
git checkout <>
./build.sh
```

Build script (build.sh) available from [https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#aryacoin-aya](https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#aryacoin-aya)

- Restart it

```bash
cd ~/AYAv2/src
./aryacoin-cli stop
source ~/dPoW/iguana/pubkey.txt
./aryacoind -pubkey=$pubkey &
```

#### dPoW

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
