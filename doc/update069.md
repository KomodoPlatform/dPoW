### dPoW 0.6.9 update information

-On your 3P node, update your Verus Coin's codebase to [`f672ccf`](https://github.com/VerusCoin/VerusCoin/tree/f672ccfbc3e77205bc5715c6370d06ad4894399c), build it and then restart it

```bash
cd ~/VerusCoin
git pull
git checkout f672ccf
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
```

#### Remove VOTE2023

```bash
# Stop VOTE2023
cd ~/komodo/src
./komodo-cli -ac_name=VOTE2023 stop

# Close p2p port
sudo ufw delete allow 29806/tcp comment 'VOTE2023 p2p port'
```

- Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Make sure your iguana is running properly.
