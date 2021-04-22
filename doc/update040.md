### dPoW 0.4.0 update instructions

(1) Build and Sync LTC 0.16 (https://github.com/litecoin-project/litecoin/tree/0.16)

clone LTC
```shell
git clone https://github.com/litecoin-project/litecoin --branch 0.16 --single-branch
cd litecoin
```

build LTC daemon according to https://github.com/litecoin-project/litecoin/blob/0.16/doc/build-unix.md

Start and sync LTC daemon

(2) Rebuild Komodod based on https://github.com/KomodoPlatform/komodo/tree/dev

clone KMD dev branch
```shell
git clone https://github.com/KomodoPlatform/komodo --branch dev --single-branch
cd komodo
```

build Komodo daemon according to https://github.com/KomodoPlatform/komodo/tree/dev#build-komodo - make sure you are using `dev` branch

(3) rebuild dPoW client iguana based on https://github.com/KomodoPlatform/dPoW/tree/LTC-dev

```shell
git clone https://github.com/KomodoPlatform/dPoW --branch LTC-dev --single-branch
cd dPoW
```

(3) Stop iguana, komodod and bitcoind

(4) Split LTC UTXOs

(5) Start komodod with arg `-notary=".litecoin/litecoin.conf"`

(6) Restart iguana with `./m_notary_LTC`

