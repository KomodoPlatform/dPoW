### dPoW 0.4.3 update information

- Update your Verus Coin's codebase to [7a740d2](https://github.com/VerusCoin/VerusCoin/tree/7a740d2b02f54457e2a8b2d205387ed3895aacc9), build it and then restart it
- Update your GleecBTC Coin's codebase to [a664ae7](https://github.com/KomodoPlatform/GleecBTC-FullNode-Win-Mac-Linux/tree/a664ae721c81ae76335dd7952d4d3bd41a302444), build it and then restart it

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
git checkout a664ae7
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

#### dPoW

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
