### dPoW 0.4.1 update instructions

- Stop dPoW operation for the PBC chain and start dPoW for the SMARTUSD (also called SFUSD) chain.
- Install and sync `SFUSD` on your 3P node. Clone repo https://github.com/pbcllc/sfusd-core and checkout to the commit `7c4f40b1759a5d0d67539462c255473c0a01b3c1`
- Follow installation instructions as outlined in [sfusd-core/build-unix.md](https://github.com/pbcllc/sfusd-core/blob/master/doc/build-unix.md)
- Sync SFUSD daemon 
- Update iguana to 0.4.1 and restart dPoW operations on your 3P NN

#### Instructions:

#### Step 0: Stop the PBC daemon.

```
powerblockcoin-cli stop
```

Optional: Delete the PBC data directory

```
rm -rf ~/.powerblockcoin/
```

####  Clone and Build `sfusd-core` in your 3p node. Checkout to the commit `7c4f40b`

##### Step 1: Clone sfusd-core source

```bash
cd ~
git clone https://github.com/pbcllc/sfusd-core
cd ~/sfusd-core
git checkout 7c4f40b
```

#### Step 2: Build

- Create a file named `build.sh` in the `~/sfusd-core` directory and copy the contents of the following code block into it

```bash
#!/bin/bash
# SFUSD build script for Ubuntu & Debian 9 v.3 (c) Decker (and webworker)
berkeleydb () {
    SFUSD_ROOT=$(pwd)
    SFUSD_PREFIX="${SFUSD_ROOT}/db4"
    mkdir -p $SFUSD_PREFIX
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
    ../dist/configure -enable-cxx -disable-shared -with-pic -prefix=$SFUSD_PREFIX
    make install
    cd $SFUSD_ROOT
}
buildSFUSD () {
    git pull
    ./autogen.sh
    ./configure LDFLAGS="-L${SFUSD_PREFIX}/lib/" CPPFLAGS="-I${SFUSD_PREFIX}/include/" --with-gui=no --disable-tests --disable-bench --without-miniupnpc --enable-experimental-asm --enable-static --disable-shared --with-incompatible-bdb
    make -j$(nproc)
}
berkeleydb
buildSFUSD
echo "Done building SFUSD!"
sudo ln -sf /home/$USER/sfusd-core/src/smartusd-cli /usr/local/bin/smartusd-cli
sudo ln -sf /home/$USER/sfusd-core/src/smartusdd /usr/local/bin/smartusdd
```

#### Step 3: Make the script executable and run it

```bash
chmod +x build.sh
./build.sh
```

- Supply your `sudo` password when asked, so that the daemon and cli can be symlinked to your `/usr/local/bin` directory

#### Step 4: Create smartusd data dir, smartusd.conf file and restrict access to it

```bash
cd ~
mkdir .smartusd
nano ~/.smartusd/smartusd.conf
```

Insert the following contents inside the smartusd.conf file and save it. (change the rpcuser and rpcpassword values)

```bash
server=1
daemon=1
txindex=1
rpcuser=user
rpcpassword=password
rpcbind=127.0.0.1
rpcallowip=127.0.0.1
```

Restrict access to the sfusd.conf file

```bash
chmod 600 ~/.smartusd/smartusd.conf
```

#### Step 5: Start the daemon, let it sync and monitor the debug.log

- Run the following command to start the daemon

```bash
cd ~/sfusd-core/src
./smartusdd &
```

- monitor the sync process by tailing the debug.log file in another terminal window

```bash
tail -f ~/.smartusd/debug.log
```

#### Step 6: Import the privkey for sfusd corresponding to your 3p server

sfusd's address format is different from KMD. But, the wif format is the same as KMD. You can import your 3p KMD node's wif into the sfusd daemon directly using the `importprivkey` command.

sfusd's rpc calls are similar to BTC's after version `v0.16`. So instead of `getinfo`, use other rpc like `getblockchaininfo`, `getnetworkinfo`, `getwalletinfo`, `getmininginfo` for the appropriate fields.

Wait for the sync and rescan(if any) to finish

#### Step 7: Start the daemon with -pubkey

- Stop the sfusd daemon and start it with the `-pubkey` parameter

```bash
source ~/komodo/src/pubkey.txt
cd ~/sfusd-core/src
./smartusd-cli stop
./smartusdd -pubkey=$pubkey
```

#### Step 8: Open p2p port, split coins

- Allow the p2p port of sfusd through ufw

```bash
sudo ufw allow 47777/tcp
```

- Split the available balance into utxos needed by iguana (size: 0.0001) for notarization

#### Step 9: Update the dPoW folder and restart iguana

- Update

```bash
cd ~/dPoW
git pull
```

- Kill iguana, rebuild and start it

```bash
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_build
./m_notary_3rdparty
```





