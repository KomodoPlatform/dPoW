### dPoW 0.4.3 update information

- Update your Verus Coin's codebase to [7a740d2](https://github.com/VerusCoin/VerusCoin/tree/7a740d2b02f54457e2a8b2d205387ed3895aacc9), build it and then restart it
- Update your GleecBTC Coin's codebase to [3c486d4](https://github.com/KomodoPlatform/GleecBTC-FullNode-Win-Mac-Linux/tree/3c486d448dece7fc9a174b7a2eb36e651c1f3529), build it and then restart it
- Update your EMC2 Coin's codebase to [a716ae8](https://github.com/emc2foundation/einsteinium/tree/a716ae80995e51b9a9d0bd5977a3463bbda4a17e), build it and then restart it

#### VRSC

```bash
cd ~/VerusCoin
git pull
git checkout 7a740d2
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
```

#### GleecBTC

```bash
cd ~/GleecBTC-FullNode-Win-Mac-Linux
# git reset --hard # (if necessary)
git pull
git checkout 3c486d4
./build.sh
```

Build script (build.sh) available from [update032](./update032.md)

- Restart it

```bash
cd ~/GleecBTC-FullNode-Win-Mac-Linux/src
./gleecbtc-cli stop
source ~/dPoW/iguana/pubkey.txt
./gleecbtcd -pubkey=$pubkey &
```

#### EMC2

```bash
cd ~/einsteinium
git pull
git checkout a716ae8
./build.sh
```

Build script (build.sh) available from [https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#einsteinium-emc2](https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#einsteinium-emc2)

- Restart it

```bash
cd ~/einsteinium/src
./einsteinium-cli stop
source ~/dPoW/iguana/pubkey.txt
./einsteiniumd -pubkey=$pubkey &
```

#### dPoW

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
