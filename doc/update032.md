### dPoW 0.3.2 update instructions

- Stop HUSH daemon and dPoW operations
- Clone and Build GleecBTC in your 3p node. Checkout to the commit `b4ffcc9`

#### Step 1: Clone GleecBTC source

```bash
cd ~
git clone https://github.com/KomodoPlatform/GleecBTC-FullNode-Win-Mac-Linux
cd ~/GleecBTC-FullNode-Win-Mac-Linux
git checkout b4ffcc9
```

#### Build

- Create a file named `build.sh` in the `~/GleecBTC-FullNode-Win-Mac-Linux` directory and copy the contents of the following code block into it

```bash
#!/bin/bash
# GleecBTC build script for Ubuntu & Debian 9 v.3 (c) Decker (and webworker)
berkeleydb () {
    GleecBTC_ROOT=$(pwd)
    GleecBTC_PREFIX="${GleecBTC_ROOT}/db4"
    mkdir -p $GleecBTC_PREFIX
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
    ../dist/configure -enable-cxx -disable-shared -with-pic -prefix=$GleecBTC_PREFIX
    make install
    cd $GleecBTC_ROOT
}
buildGleecBTC () {
    git pull
    ./autogen.sh
    ./configure LDFLAGS="-L${GleecBTC_PREFIX}/lib/" CPPFLAGS="-I${GleecBTC_PREFIX}/include/" --with-gui=no --disable-tests --disable-bench --without-miniupnpc --enable-experimental-asm --enable-static --disable-shared --with-incompatible-bdb
    make -j$(nproc)
}
berkeleydb
buildGleecBTC
echo "Done building GleecBTC!"
sudo ln -sf /home/$USER/GleecBTC-FullNode-Win-Mac-Linux/src/gleecbtc-cli /usr/local/bin/gleecbtc-cli
sudo ln -sf /home/$USER/GleecBTC-FullNode-Win-Mac-Linux/src/gleecbtcd /usr/local/bin/gleecbtcd
```

#### Step 3: Make the script executable and run it

```bash
chmod +x build.sh
./build.sh
```

- Supply your `sudo` password when asked, so that the daemon and cli can be symlinked to your `/usr/local/bin` directory

#### Step 4: Create GleecBTC data dir, gleecbtc.conf file and restrict access to it

```bash
cd ~
mkdir .gleecbtc
nano ~/.gleecbtc/gleecbtc.conf
```

Insert the following contents inside the gleecbtc.conf file and save it. (change the rpcuser and rpcpassword values)

```bash
server=1
daemon=1
txindex=1
rpcuser=user
rpcpassword=password
bind=127.0.0.1
rpcbind=127.0.0.1
rpcallowip=127.0.0.1
```

Restrict access to the gleecbtc.conf file

```bash
chmod 600 ~/.gleecbtc/gleecbtc.conf
```

#### Step 5: Start the daemon, let it sync and monitor the debug.log

- Run the following command to start the daemon

```bash
gleecbtcd &
```

- monitor the sync process by tailing the debug.log file in another terminal window

```bash
tail -f ~/.gleecbtc/debug.log
```

#### Step 6: Import the privkey for GleecBTC corresponding to your 3p server

Generate your GleecBTC wif by following the guide at [https://docs.komodoplatform.com/notary/generate-privkeys-third-party-coins-from-passphrase.html](https://docs.komodoplatform.com/notary/generate-privkeys-third-party-coins-from-passphrase.html). If you need to convert a KMD wif to GleecBTC wif, use https://gist.github.com/gcharang/39027275e433693b98b81adef812478c

GleecBTC's rpc calls are similar to BTC's after version `v0.18`. So familiar commands like `getinfo` don't work, and `validateaddress` doesn't output `ismine` info. To check if your address was imported, use `getaddressinfo` and check the `ismine` key in the response.

Wait for the sync and rescan(if any) to finish

#### Step 7: Start the daemon with -pubkey

- Stop the gleecbtc daemon and start it with the `-pubkey` parameter

```bash
source ~/komodo/src/pubkey.txt
gleecbtcd -pubkey=$pubkey
```

#### Step 8: Open p2p port, split coins

- Allow the p2p port of gleecbtc through ufw

```bash
sudo ufw allow 6703/tcp
```

- Split the available balance into utxos needed by iguana for notarization

#### Step 9: Update the dPoW folder and restart iguana

- Update

```bash
cd ~/dPoW
git pull
```

- Kill iguana and start it

```bash
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_3rdparty
```
