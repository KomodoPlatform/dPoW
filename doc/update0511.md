### dPoW 0.5.11 update information

- On your 3P node, delete the GleecBTC coin and stop dPoW operations for it
- On your 3P node, sync the MIL coin and start dPoW operations for it
- On your main node, sync the CLC coin and start dPoW operations for it

#### On 3P node

##### Stop the `GleecBTC` chain on your 3P node

```bash
cd ~/GleecBTC-FullNode-Win-Mac-Linux/src
./gleecbtc-cli stop
```

- Wait for it to stop properly and delete its data directory if you need the extra space

```bash
rm -rf ~/.gleecbtc
```

- Remove GleecBTC from your autosplit script(s) and remove its p2p port (`6703/tcp`) from the allow list in your firewall

##### Clone and Install MIL coin

```bash
cd ~
git clone https://github.com/KomodoPlatform/mil-1
cd ~/mil-1
git checkout aacdaee
```

- Create a file named `build-nn.sh` in the `~/mil-1` directory and copy the contents of the following code block into it

```bash
#!/bin/bash
# MIL build script for Ubuntu & Debian 9 v.3 (c) Decker (and webworker)
berkeleydb () {
    MIL_ROOT=$(pwd)
    MIL_PREFIX="${MIL_ROOT}/db4"
    mkdir -p $MIL_PREFIX
    wget -N 'http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz'
    echo '12edc0df75bf9abd7f82f821795bcee50f42cb2e5f76a6a281b85732798364ef db-4.8.30.NC.tar.gz' | sha256sum -c
    tar -xzvf db-4.8.30.NC.tar.gz
    cat <<-EOL >atomic-builtin-test.cpp
        #include <stdint.h>
        #include "atomic.h"

        int main() {
        db_atomic_t *p; atomic_value_t oldval; atomic_value_t newval;
        __atomic_compare_exchange(p, oldval, newval);
        return 0;
        }
EOL
    if g++ atomic-builtin-test.cpp -I./db-4.8.30.NC/dbinc -DHAVE_ATOMIC_SUPPORT -DHAVE_ATOMIC_X86_GCC_ASSEMBLY -o atomic-builtin-test 2>/dev/null; then
        echo "No changes to bdb source are needed ..."
        rm atomic-builtin-test 2>/dev/null
    else
        echo "Updating atomic.h file ..."
        sed -i 's/__atomic_compare_exchange/__atomic_compare_exchange_db/g' db-4.8.30.NC/dbinc/atomic.h
    fi
    cd db-4.8.30.NC/build_unix/
    ../dist/configure -enable-cxx -disable-shared -with-pic -prefix=$MIL_PREFIX
    make install
    cd $MIL_ROOT
}
buildMIL () {
    git pull
    ./autogen.sh
    ./configure LDFLAGS="-L${MIL_PREFIX}/lib/" CPPFLAGS="-I${MIL_PREFIX}/include/" --with-gui=no --disable-tests --disable-bench --without-miniupnpc --enable-experimental-asm --enable-static --disable-shared --with-incompatible-bdb
    make -j$(nproc)
}
berkeleydb
buildMIL
echo "Done building MIL!"
sudo ln -sf /home/$USER/mil-1/src/mil-cli /usr/local/bin/mil-cli
sudo ln -sf /home/$USER/mil-1/src/mild /usr/local/bin/mild
```

- Make the script executable and run it

```bash
chmod +x build-nn.sh
./build-nn.sh
```

- Supply your `sudo` password when asked, so that the daemon and cli can be symlinked to your `/usr/local/bin` directory

- Create mil data dir, mil.conf file and restrict access to it

```bash
cd ~
mkdir .mil
nano ~/.mil/mil.conf
```

Insert the following contents inside the mil.conf file and save it. (change the rpcuser and rpcpassword values)

```bash
server=1
daemon=1
txindex=1
rpcuser=user
rpcpassword=password
rpcbind=127.0.0.1
rpcallowip=127.0.0.1
```

Restrict access to the mil.conf file

```bash
chmod 600 ~/.mil/mil.conf
```

- Start the daemon, let it sync and monitor the debug.log

Run the following command to start the daemon

```bash
cd ~/mil-1/src
./mild &
```

monitor the sync process by tailing the debug.log file in another terminal window

```bash
tail -f ~/.mil/debug.log
```

- Import the privkey for MIL corresponding to your 3P server

MIL's address and privkey(wif) formats are different from KMD. You can import your 3P MIL node's wif into the MIL daemon using the `importprivkey` command.

To get wif for MIL, see https://github.com/DeckerSU/komodo_scripts/blob/master/genkomodo.txt and https://github.com/DeckerSU/komodo_scripts/blob/master/genkomodo.php

MIL's rpc calls are similar to BTC's after version `v0.16`. So instead of `getinfo`, use other rpc like `getblockchaininfo`, `getnetworkinfo`, `getwalletinfo`, `getmininginfo` for the appropriate fields.

Wait for the sync and rescan(if any) to finish

- Start the daemon with -pubkey

Stop the MIL daemon and start it with the `-pubkey` parameter

```bash
source ~/komodo/src/pubkey.txt
cd ~/mil-1/src
./mil-cli stop
./mild -pubkey=$pubkey
```

- Open p2p port, split coins

Allow the p2p port of sfusd through ufw

```bash
sudo ufw allow 41888/tcp
```

- Split the available balance into utxos needed by iguana (size: 0.0001) for notarization

- Update your dPoW repo, rebuild and restart iguana

```bash
cd ~/dPoW
git checkout master
git pull
cd ~/dPoW/iguana
./m_notary_build
pkill -15 iguana
./m_notary_3rdparty # start notarization
```

- Make sure your iguana is running properly

#### On Main node

##### Launch the `CLC` chain on your main node

```bash
cd ~/komodo/src
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=CLC -ac_supply=99000000 -ac_reward=50000000 -ac_perc=100000000 -ac_founders=1 -ac_cc=45 -ac_public=1 -ac_snapshot=1440 -ac_pubkey=02df9bda7bfe2bcaa938b29a399fb0ba58cfb6cc3ddc0001062a600f60a8237ad9 -addnode=node.cryptocollider.com -ac_adaptivepow=6 -pubkey=$pubkey &
```

- Import your KMD/Smart Chain privkey for main node to the CLC chain

```bash
cd ~/komodo/src
./komodo-cli -ac_name=CLC importprivkey ***
```

- Open `tcp/20931` for incoming p2p connections:

```bash
sudo ufw allow 20931/tcp comment 'CLC p2p port'
```

- Add CLC to your autosplit script(s)
- Update your dPoW repo, rebuild and restart iguana

```bash
cd ~/dPoW
git checkout master
git pull
cd ~/dPoW/iguana
./m_notary_build
pkill -15 iguana
./m_notary_KMD # start notarization
```

- Make sure your iguana is running properly
- Split CLC UTXO's once iguana is running
