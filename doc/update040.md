## dPoW 0.4.0 update instructions

#### (1) Build and Sync LTC 0.16 (https://github.com/litecoin-project/litecoin/tree/0.16)

clone LTC
```shell
git clone https://github.com/litecoin-project/litecoin --branch 0.16 --single-branch
cd litecoin
```

build LTC daemon according to https://github.com/litecoin-project/litecoin/blob/0.16/doc/build-unix.md

##### create ~/.litecoin and litecoin.conf 
```
mkdir ~/.litecoin
```
create `~/.litecoin/litecoin.conf` with:
```
rpcuser=<secure username>
rpcpassword=<secure password>
txindex=1
```
```
chmod 600 ~/.litecoin/litecoin.conf
```

Start and sync LTC daemon

#### (2) Rebuild Komodod based on https://github.com/KomodoPlatform/komodo/tree/dev

clone KMD dev branch
```shell
git clone https://github.com/KomodoPlatform/komodo --branch dev --single-branch
cd komodo
```

build Komodo daemon according to https://github.com/KomodoPlatform/komodo/tree/dev#build-komodo - make sure you are using `dev` branch

#### (3) rebuild dPoW client iguana based on https://github.com/KomodoPlatform/dPoW/tree/LTC-dev

```shell
git clone https://github.com/KomodoPlatform/dPoW --branch LTC-dev --single-branch
cd dPoW
```

Recreate pubkey.txt in komodo/src and dPoW/iguana if using fresh clones
Create `wp_7776` according to https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#create-wp-7776 

#### (4) Stop iguana, komodod and bitcoind

#### (5) Split LTC UTXOs

#### (6) Start komodod with arg `-notary=".litecoin/litecoin.conf"`

#### (7) Restart iguana with `./m_notary_LTC`

