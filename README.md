# dPoW client _iguana_

This repository is based on the original SuperNET codebase - commit [f29913e92b117399cd42e2fd05ff0d69d152c8fa](https://github.com/ca333/SuperNET/commit/f29913e92b117399cd42e2fd05ff0d69d152c8fa)

Integration | Status 
-------------|------
CI build - Ubuntu (16.04, 18.04) | [![Build Status](https://github.com/komodoplatform/dpow/workflows/CI/badge.svg)](https://github.com/KomodoPlatform/dPoW/actions)
Codefactor analysis | [![Grade](https://img.shields.io/codefactor/grade/github/komodoplatform/dpow)](https://www.codefactor.io/repository/github/komodoplatform/dpow)

---


## Installation 

General [Setup instructions](https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#setup-komodo-notary-node)

### Build instructions for NN operations:


`cd iguana`

#### Build iguana for notary operations
`./m_notary_build`

#### Start main-net notarizations:
`./m_notary_KMD`

#### Start 3rd party notarizations:
`./m_notary_3rdparty`


###### To build and launch main-net notarizations in one step run `./m_notary`

#

**Please note: Automatic UTXO split is deactivated by default.**

### dPoW asset status

Coin | src | Version | Status | dPoW 
--------|------|---|------|------
KMD | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/KMD_badge.svg) | dPoW-Mainnet
BTC | [bitcoin](https://github.com/bitcoin/bitcoin) | 0.16 | ![dPOW Status](http://159.69.45.70/svg/KMD_badge.svg) | dPoW-Mainnet
AXO | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/AXO_badge.svg) | dPoW-mainnet
BET | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/BET_badge.svg) | dPoW-mainnet
BNTN | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/BNTN_badge.svg) | dPoW-mainnet
BOTS | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/BOTS_badge.svg) | dPoW-mainnet
BTCH | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/BTCH_badge.svg) | dPoW-mainnet
CCL | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/CCL_badge.svg) | dPoW-mainnet
CEAL | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/CEAL_badge.svg) | dPoW-mainnet
CHAIN | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/CHAIN_badge.svg) | dPoW-mainnet
CHIPS | [chips](https://github.com/jl777/chips3/tree/dev) | dev | ![dPOW Status](http://159.69.45.70/svg/CHIPS_badge.svg) | dPoW-3P
COMMOD | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/COMMOD_badge.svg) | dPoW-mainnet
COQUICASH | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/COQUICASH_badge.svg) | dPoW-mainnet
CRYPTO | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/CRYPTO_badge.svg) | dPoW-mainnet
DEX | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/DEX_badge.svg) | dPoW-mainnet
DION | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/DION_badge.svg) | dPoW-mainnet
DSEC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/DSEC_badge.svg) | dPoW-mainnet
EMC2 | [emc2](https://github.com/emc2foundation/einsteinium) | lastest master | ![dPOW Status](http://159.69.45.70/svg/DION_badge.svg) | dPoW-3P
EQL | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/EQL_badge.svg) | dPoW-mainnet
ETOMIC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/ETOMIC_badge.svg) | dPoW-mainnet
GAME | [game](https://github.com/gamecredits-project/GameCredits) | latest master | ![dPOW Status](http://159.69.45.70/svg/GAME_badge.svg) | dPoW-3P
GIN | [gin](https://github.com/GIN-coin/gincoin-core) | latest master | ![dPOW Status](http://159.69.45.70/svg/GIN_badge.svg) | dPoW-3P
HODL | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/HODL_badge.svg) | dPoW-mainnet
HUSH3 | [komodo](https://github.com/KomodoPlatform/komodo/tree/hush3) | 0.4.0 | ![dPOW Status](http://159.69.45.70/svg/HUSH3_badge.svg) | dPoW-mainnet
ILN | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/ILN_badge.svg) | dPoW-mainnet
JUMBLR | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/JUMBLR_badge.svg) | dPoW-mainnet
K64 | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/K64_badge.svg) | dPoW-mainnet
KMDICE | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/KMDICE_badge.svg) | dPoW-mainnet
KOIN | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/KOIN_badge.svg) | dPoW-mainnet
KSB | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/KSB_badge.svg) | dPoW-mainnet
KV | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/KV_badge.svg) | dPoW-mainnet
MESH | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/MESH_badge.svg) | dPoW-mainnet
MGW | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/MGW_badge.svg) | dPoW-mainnet
MORTY | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/MORTY_badge.svg) | dPoW-mainnet
MSHARK | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/MSHARK_badge.svg) | dPoW-mainnet
NINJA | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/NINJA_badge.svg) | dPoW-mainnet
OOT | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/OOT_badge.svg) | dPoW-mainnet
OUR | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/OUR_badge.svg) | dPoW-mainnet
PANGEA | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/PANGEA_badge.svg) | dPoW-mainnet
PGT | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/PGT_badge.svg) | dPoW-mainnet
PIRATE | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/PIRATE_badge.svg) | dPoW-mainnet
PRLPAY | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/PRLPAY_badge.svg) | dPoW-mainnet
REVS | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/REVS_badge.svg) | dPoW-mainnet
RFOX | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/RFOX_badge.svg) | dPoW-mainnet
RICK | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/RICK_badge.svg) | dPoW-mainnet
SEC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/SEC_badge.svg) | dPoW-mainnet
SUPERNET | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/SUPERNET_badge.svg) | dPoW-mainnet
THC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/THC_badge.svg) | dPoW-mainnet
VRSC | [verus](https://github.com/VerusCoin/VerusCoin) | :construction_worker: | ![dPOW Status](http://159.69.45.70/svg/VRSC_badge.svg) | dPoW-mainnet
WLC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/WLC_badge.svg) | dPoW-mainnet
WLC21 | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/WLC21_badge.svg) | dPoW-mainnet
ZEXO | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/ZEXO_badge.svg) | dPoW-mainnet
ZILLA | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | ![dPOW Status](http://159.69.45.70/svg/ZILLA_badge.svg) | dPoW-mainnet

