# dPoW 0.8.2 update information

### Update Litecoin Core to `v0.21.4`

The main purpose of this update is to upgrade the outdated Litecoin Core `0.16.x`, still used on notaries, to the latest version `v0.21.4`. Since a resync is required (as explained [here](https://github.com/litecoin-project/litecoin/issues/865#issuecomment-1304798606)) when updating from pre-MWEB versions, we need to prepare in advance. Specifically, build the latest `litecoind` and perform a full sync from scratch before the transition. The manual below explains how to achieve this without losing notarization counts and without stopping LTC notarizations.

#### Build latest Litecoin:

```bash
cd ~
git clone https://github.com/litecoin-project/litecoin litecoin.021
cd litecoin.021
git checkout beae01d # https://github.com/litecoin-project/litecoin/tree/v0.21.4
# apply patches from PR#990 to build dependencies with gcc-11
wget https://github.com/litecoin-project/litecoin/pull/990.diff
git apply -v 990.diff
# build as described here https://komodoplatform.com/en/docs/notary/
make -C ${PWD}/depends v=1 NO_PROTON=1 NO_QT=1 HOST=$(depends/config.guess) -j$(nproc --all)
./autogen.sh
CXXFLAGS="-g0 -O2" CONFIG_SITE="$PWD/depends/$(depends/config.guess)/share/config.site" ./configure --disable-tests --disable-bench --without-miniupnpc -enable-experimental-asm --with-gui=no --disable-bip70
make V=1 -j$(nproc --all)
```

#### Sync latest Litecoin from scratch:

```bash
mkdir -p ~/.litecoin.021
echo -e "txindex=1\nrpcport=9334\nserver=1\nlisten=0" > ~/.litecoin.021/litecoin.conf
./src/litecoind -datadir=$HOME/.litecoin.021 -daemon
tail -F ~/.litecoin.021//debug.log # sync monitoring, when it synced till 100%, stop it
./src/litecoin-cli -datadir=$HOME/.litecoin.021 stop
rm ~/.litecoin.021/litecoin.conf
```

#### Swap data folders and sources folders:

```bash
cd ~
~/litecoin/src/litecoin-cli stop && sleep 5 # stop your old daemon
cp ~/.litecoin/litecoin.conf ~/.litecoin.021 # copy .conf and wallet.dat in new folder
cp ~/.litecoin/wallet.dat ~/.litecoin.021
mv ~/.litecoin ~/.litecoin.016 # swap folders
mv ~/litecoin ~/litecoin.016
mv ~/.litecoin.021 ~/.litecoin
mv ~/litecoin.021 ~/litecoin
```

#### Start the new litecoin daemon

Start `litecoind` as usual. If you use scripts to start all daemons, modify them to include the `-daemon` argument to prevent console spam, and remove the `-pubkey` argument, as `litecoind` does not recognize it and will quit shortly instead of launching. Your daemon launch command should look like this: 

```bash
~/litecoin/src/litecoind -daemon
```

### Restart Iguana

```bash
# Update dPoW repo
cd ~/dPoW
git checkout master
git pull

# Restart Iguana
pkill -9 iguana
cd iguana
./m_notary_build
./m_notary_main
```

Make sure notarisations are progressing.


