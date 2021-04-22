## dPoW 0.4.0 update instructions

#### (1) Build and Sync LTC 0.16 (https://github.com/litecoin-project/litecoin/tree/0.16)

clone LTC
```shell
git clone https://github.com/litecoin-project/litecoin --branch 0.16 --single-branch
cd litecoin
```
Create `build.sh` script with the following contents and give it executable permission
```
#!/bin/bash
# LTC build script for Ubuntu & Debian 9 v.3 (c) Decker (and webworker)
berkeleydb () {
    LTC_ROOT=$(pwd)
    LTC_PREFIX="${LTC_ROOT}/db4"
    mkdir -p $LTC_PREFIX
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
    ../dist/configure -enable-cxx -disable-shared -with-pic -prefix=$LTC_PREFIX
    make install
    cd $LTC_ROOT
}
buildLTC () {
    git pull
    ./autogen.sh
    ./configure LDFLAGS="-L${LTC_PREFIX}/lib/" CPPFLAGS="-I${LTC_PREFIX}/include/" --with-gui=no --disable-tests --disable-bench --without-miniupnpc --enable-experimental-asm --enable-static --disable-shared --with-incompatible-bdb
    make -j$(nproc)
}
berkeleydb
buildLTC
echo "Done building LTC!"
```
Execute `./build.sh` to compile Litecoin binaries.

##### create ~/.litecoin and litecoin.conf 
```
mkdir ~/.litecoin
```
create `~/.litecoin/litecoin.conf` with:
```
rpcuser=<secure username>
rpcpassword=<secure password>
rpcport=9332
txindex=1
```
```
chmod 600 ~/.litecoin/litecoin.conf
```

Start and sync LTC daemon

#### (2) Rebuild Komodod based on https://github.com/KomodoPlatform/komodo/tree/master

clone KMD
```shell
git clone https://github.com/KomodoPlatform/komodo --branch master --single-branch
cd komodo
```

build Komodo daemon according to https://github.com/KomodoPlatform/komodo/tree/master#build-komodo - make sure you are using `master` branch

#### (3) rebuild dPoW client iguana based on https://github.com/KomodoPlatform/dPoW/tree/master

```shell
git clone https://github.com/KomodoPlatform/dPoW --branch master --single-branch
cd dPoW/iguana
./m_notary_build
```

Recreate pubkey.txt in komodo/src and dPoW/iguana if using fresh clones

Create `wp_7776` according to https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#create-wp-7776 

#### (4) Stop iguana, komodod and bitcoind

#### (5) Open port 17777

#### (6) Start komodod with arg `-notary=".litecoin/litecoin.conf"`

#### (7) Restart iguana with `./m_notary_LTC`

#### (8) Split LTC UTXOs with your normal `acsplit` script or any other you use with `0.0001`.
