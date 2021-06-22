### dPoW 0.5.3 update information

- Update your Verus Coin's codebase to [942b01b](https://github.com/VerusCoin/VerusCoin/tree/942b01b87b96239102ecf57aecff838c6d2913a0), build it and then restart it on 3P nodes.

```bash
cd ~/VerusCoin
git pull
git checkout 942b01b
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
verusd -pubkey=$pubkey &
```

- Update your dPoW repo

```bash
cd ~/dPoW/iguana
git checkout master
git pull
```

Make sure your iguana is running properly
