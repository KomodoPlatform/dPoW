### dPoW 0.6.5 update information

- On your 3P node, update your VRSC Coin's codebase to [1b02282](https://github.com/VerusCoin/VerusCoin/commit/1b022820ac1f4a539c0eed60584cac29715c34f1), build it and then restart it.

```bash
# Build VRSC

cd ~/VerusCoin/
git pull
git checkout 1b022820ac1f4a539c0eed60584cac29715c34f1
./zcutil/build.sh -j4

# (re)start VRSC
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &

# Check sync status
tail -f ~/.komodo/VRSC/debug.log
```

Make sure chain is running smoothly and notarisations are progressing.

- Remove SFUSD.
```bash
# Update dPoW repo
cd ~/dPoW
git checkout master
git pull

# Restart Iguana
pkill -9 iguana
cd iguana
./m_notary_build
./m_notary_3rdparty

# Return remaining SFUSD funds
cd ~/sfusd-core/src
./smartusd-cli sendtoaddress SVpijx2FxX67ny8LAtC4ogrvpSWzwkda5x $(./smartusd-cli getbalance) "" "" true

# Stop SFUSD
./smartusd-cli stop
```