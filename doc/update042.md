### dPoW 0.4.2 update instructions

- Stop SMARTUSD (also called SFUSD) daemon and clear data folder, except your wallet.dat and .conf file.
- Update, rebuild and sync from scratch `SFUSD` on your 3P node. Clone repo https://github.com/pbcllc/sfusd-core and checkout to the commit `d96497cbcec0dcf185cc149f1b3988a5964e5112`
- Follow installation instructions (below is a script to use) or as outlined in [sfusd-core/build-unix.md](https://github.com/pbcllc/sfusd-core/blob/master/doc/build-unix.md)
- Sync SFUSD daemon 
- Update iguana to 0.4.2 and restart dPoW operations on your 3P NN

#### Instructions:

#### Step 0: Delete everything in $HOME/.smartusd folder, except your .conf and wallet.dat

```
cd $HOME/sfusd-core
./src/smartusd-cli stop
```

Mandatory: Delete everything inside SmartUSD data directory, except your .conf and wallet.dat

```
cd $HOME/.smartusd
rm -rf chainstate
rm -rf blocks
rm -rf database
rm debug.log peers.dat smartusdd.pid notarizations fee_estimates.dat mempool.dat banlist.dat .walletlock db.log .lock
```

####  Update and Re-build `sfusd-core` in your 3p node. Checkout to the commit `d96497c`

##### Step 1: Update sfusd-core source

```bash
cd $HOME/sfusd-core
git checkout master
git pull
git checkout d96497c
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

#### Step 4: Start the daemon, let it sync and monitor the debug.log

- Run the following command to start the daemon

```bash
cd ~/sfusd-core/src
./smartusdd &
```

- monitor the sync process by tailing the debug.log file in another terminal window

```bash
tail -f ~/.smartusd/debug.log
```

#### Step 5: Start the daemon with -pubkey

- Stop the sfusd daemon and start it with the `-pubkey` parameter

```bash
source ~/komodo/src/pubkey.txt
cd ~/sfusd-core/src
./smartusd-cli stop
./smartusdd -pubkey=$pubkey
```

#### Step 6: Update the dPoW folder and restart iguana

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
