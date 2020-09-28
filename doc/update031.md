### dPoW 0.3.1 update information

- Please update your Hush Coin's codebase to [3a276a7](https://github.com/MyHush/hush3/tree/3a276a7b61ae4195c10a8ecc58a50a13c979620b), build it and then restart it

```bash
cd ~/hush3
git pull
git checkout 3a276a7
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/hush3/src
./hush-cli stop
source ~/dPoW/iguana/pubkey.txt
./hushd -pubkey=$pubkey &
```

- Update your Verus Coin's codebase to [9a9d036](https://github.com/VerusCoin/VerusCoin/tree/9a9d036615b1a8af280421ddfead172aeee84259), build it and then restart it

```bash
cd cd ~/VerusCoin
git pull
git checkout 9a9d036
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
cd dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
