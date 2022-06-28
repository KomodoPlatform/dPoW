# dPoW client _iguana_

This repository is based on the original SuperNET codebase - commit [f29913e92b117399cd42e2fd05ff0d69d152c8fa](https://github.com/ca333/SuperNET/commit/f29913e92b117399cd42e2fd05ff0d69d152c8fa)

Integration | Status 
-------------|------
CI build - Ubuntu (16.04, 18.04) | [![Build Status](https://github.com/komodoplatform/dpow/workflows/CI/badge.svg?maxAge=60)](https://github.com/KomodoPlatform/dPoW/actions)
Codefactor analysis | [![Grade](https://img.shields.io/codefactor/grade/github/komodoplatform/dpow)](https://www.codefactor.io/repository/github/komodoplatform/dpow)
Version | [![Version](https://img.shields.io/github/v/release/komodoplatform/dPoW)](https://github.com/KomodoPlatform/dPoW/releases)
Network Statistics | https://stats.kmd.io/

---


## Installation 

General [Setup instructions](https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#setup-komodo-notary-node)

### Build instructions for NN operations:


`cd iguana`

#### Build iguana for notary operations
`./m_notary_build`

#### Start main-net notarizations:
`./m_notary_main`

#### Start 3rd party notarizations:
`./m_notary_3rdparty`


###### To build and launch main-net notarizations in one step run `./m_notary`

#

**Please note: Automatic UTXO split is deactivated by default.**

### dPoW asset status

#### dPoW assets update requirements

**Please note:** All dPoW protected blockchain projects are required to open an issue ticket with upgrade details in this repository and at least 4 weeks prior to a mandatory update - in case of significant code changes (>2000 lines of code altered/added) open the issue ticket at least 8 weeks prior to the mandatory update. Send the official update announcement ref to `partners@komodoplatform.com`.

#### [Notary Node metrics](http://stats.kmd.io/) - http://stats.kmd.io/

[![dPOW Status](https://badges.komodo.live/svg/date_badge.svg?maxAge=60)](https://komodostats.com)
* active - last notarization less than 2.5 hours ago
* irregular - last notarization more than 2.5 and less than 24 hours ago
* inactive - last notarization more than 24 hours ago

Coin | src | Version/Tree | Status | dPoW 
--------|------|---|------|------
KMD | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
LTC | [litecoin](https://github.com/litecoin-project/litecoin) | [0.16](https://github.com/litecoin-project/litecoin/tree/69fce744115a7d2889ff1b90e89582b83de405ad) | [![dPOW Status](https://badges.komodo.live/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
BET | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/BET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
BOTS | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/BOTS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CCL | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/CCL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CLC | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/CLC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CRYPTO | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/CRYPTO_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
DEX | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/DEX_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
GLEEC | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/GLEEC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
HODL | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/HODL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
ILN | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/ILN_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
JUMBLR | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/JUMBLR_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
KOIN | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/KOIN_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MGW | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/MGW_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MORTY | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MSHARK | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/MSHARK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
NINJA | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/NINJA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PANGEA | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/PANGEA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PIRATE | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/PIRATE_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
REVS | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/REVS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
RICK | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/RICK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
SUPERNET | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/SUPERNET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
THC | [komodo](https://github.com/komodoplatform/komodo) | [d456be3](https://github.com/KomodoPlatform/komodo/tree/d456be35acd1f8584e1e4f971aea27bd0644d5c5) | [![dPOW Status](https://badges.komodo.live/svg/THC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
AYA | [aryacoin](https://github.com/KomodoPlatform/AYAv2) | [94e6bc0](https://github.com/KomodoPlatform/AYAv2/tree/94e6bc000c77401ac1b36f27a43d391984e81ac3) | [![dPOW Status](https://badges.komodo.live/svg/AYA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
CHIPS | [chips](https://github.com/chips-blockchain/chips) | [6e7560a](https://github.com/chips-blockchain/chips/tree/6e7560a69975d4419b3e36c817cdba6401bc8aed) | [![dPOW Status](https://badges.komodo.live/svg/CHIPS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
EMC2 | [emc2](https://github.com/emc2foundation/einsteinium) | [c329ae6](https://github.com/emc2foundation/einsteinium/tree/c329ae64397bea743054d06b779bb4cbfdcdd25f) | [![dPOW Status](https://badges.komodo.live/svg/EMC2_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
MCL | [marmarachain](https://github.com/marmarachain/marmara) | [a92d834](https://github.com/marmarachain/marmara/tree/a92d8344d3c545b2641a1e04479c90d19588abe7) | [![dPOW Status](https://badges.komodo.live/svg/MCL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3p
MIL | [mil](https://github.com/emc2foundation/mil) | [578bed7](https://github.com/emc2foundation/mil/tree/578bed7f403c4d4a16561317d356202ca60c605f) | [![dPOW Status](https://badges.komodo.live/svg/MIL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
SFUSD | [sfusd](https://github.com/pbcllc/sfusd-core) | [4e79e1b](https://github.com/pbcllc/sfusd-core/commit/4e79e1bbf9faa5305ed1091e863ef081c9272a8e) | [![dPOW Status](https://badges.komodo.live/svg/SFUSD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
TOKEL | [tokel](https://github.com/TokelPlatform/tokel) | [d2e98de](https://github.com/TokelPlatform/tokel/commit/d2e98de9d1ac6e26c20d540d5a8d7a493e2cf5fd) | [![dPOW Status](https://badges.komodo.live/svg/TOKEL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
VRSC | [verus](https://github.com/VerusCoin/VerusCoin) | [TBA]() | [![dPOW Status](https://badges.komodo.live/svg/VRSC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
