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
KMD | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-Mainnet
BTC | [bitcoin](https://github.com/bitcoin/bitcoin) | 0.16 | active :white_check_mark: | dPoW-Mainnet
AXO | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
BET | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
BNTN | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
BOTS | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
BTCH | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
CCL | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
CEAL | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
CHAIN | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
CHIPS | [chips](https://github.com/jl777/chips3/tree/dev) | dev | active :white_check_mark: | dPoW-3P
COMMOD | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
COQUICASH | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
CRYPTO | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
DEX | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
DION | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
DSEC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
EMC2 | [emc2](https://github.com/emc2foundation/einsteinium) | lastest master | active :white_check_mark: | dPoW-3P
EQL | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
ETOMIC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
GAME | [game](https://github.com/gamecredits-project/GameCredits) | latest master | active :white_check_mark: | dPoW-3P
GIN | [gin](https://github.com/GIN-coin/gincoin-core) | latest master | active :white_check_mark: | dPoW-3P
HODL | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
HUSH3 | [komodo](https://github.com/KomodoPlatform/komodo/tree/hush3) | 0.4.0 | active :white_check_mark: | dPoW-mainnet
ILN | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
JUMBLR | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
K64 | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
KMD | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
KMDICE | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
KOIN | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
KSB | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
KV | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
MESH | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
MGW | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
MORTY | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
MSHARK | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
NINJA | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
OOT | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
OUR | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
PANGEA | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
PGT | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
PIRATE | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
PRLPAY | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
REVS | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
RFOX | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
RICK | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
SEC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
SUPERNET | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
THC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
VRSC | [verus](https://github.com/VerusCoin/VerusCoin) | :construction_worker: | paused :construction_worker: | dPoW-mainnet
WLC | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
WLC21 | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
ZEXO | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet
ZILLA | [komodo](https://github.com/komodoplatform/komodo) | 0.5.0 | active :white_check_mark: | dPoW-mainnet

