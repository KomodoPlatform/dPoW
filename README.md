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
`./m_notary_KMD`

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
KMD | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
LTC | [litecoin](https://github.com/litecoin-project/litecoin) | [0.16](https://github.com/litecoin-project/litecoin/tree/69fce744115a7d2889ff1b90e89582b83de405ad) | [![dPOW Status](https://badges.komodo.live/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
AYA | [aryacoin](https://github.com/KomodoPlatform/AYAv2) | [02afeac](https://github.com/KomodoPlatform/AYAv2/commit/02afeacdc0702bd160abef603f03167381f39097) | [![dPOW Status](https://badges.komodo.live/svg/AYA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
BET | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/BET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
BOTS | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/BOTS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CCL | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/CCL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CLC | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/CLC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CHIPS | [chips](https://github.com/chips-blockchain/chips) | [70362d5](https://github.com/chips-blockchain/chips/tree/70362d54645748194b72e1cc753cca8be4f8629b) | [![dPOW Status](https://badges.komodo.live/svg/CHIPS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
CRYPTO | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/CRYPTO_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
DEX | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/DEX_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
EMC2 | [emc2](https://github.com/emc2foundation/einsteinium) | [a716ae8](https://github.com/emc2foundation/einsteinium/tree/a716ae80995e51b9a9d0bd5977a3463bbda4a17e) | [![dPOW Status](https://badges.komodo.live/svg/EMC2_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
GLEEC | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/GLEEC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
HODL | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/HODL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
ILN | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/ILN_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
JUMBLR | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/JUMBLR_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
KOIN | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/KOIN_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MCL | [marmarachain](https://github.com/marmarachain/marmara) | [b288dfd](https://github.com/marmarachain/marmara/tree/b288dfd66e2761e40af717362f75e4d5319c4f7f) | [![dPOW Status](https://badges.komodo.live/svg/MCL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3p
MESH | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/MESH_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MGW | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/MGW_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MIL | [mil](https://github.com/KomodoPlatform/mil-1) | [d96497c](https://github.com/KomodoPlatform/mil-1/tree/4fb038958b7ad05baffa698c4e4ccbefdd211f0a) | [![dPOW Status](https://badges.komodo.live/svg/MIL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
MORTY | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MSHARK | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/MSHARK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
NINJA | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/NINJA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PANGEA | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/PANGEA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PIRATE | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/PIRATE_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
REVS | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/REVS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
RICK | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/RICK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
SFUSD | [sfusd](https://github.com/pbcllc/sfusd-core) | [d96497c](https://github.com/pbcllc/sfusd-core/commit/d96497cbcec0dcf185cc149f1b3988a5964e5112) | [![dPOW Status](https://badges.komodo.live/svg/SFUSD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
SUPERNET | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/SUPERNET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
THC | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/THC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
TOKEL | [tokel](https://github.com/komodoplatform/komodo) | [f39a088](https://github.com/KomodoPlatform/komodo/tree/f39a0881a5d672f7c1131e5ae6d390e8cdccb037) | [![dPOW Status](https://badges.komodo.live/svg/TOKEL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
VOTE2022 | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/VOTE2021_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
VRSC | [verus](https://github.com/VerusCoin/VerusCoin) | [81dac44](https://github.com/VerusCoin/VerusCoin/tree/81dac44081e469a08e013de2e400edf73cdd94e2) | [![dPOW Status](https://badges.komodo.live/svg/VRSC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
ZILLA | [komodo](https://github.com/komodoplatform/komodo) | [d7edae2](https://github.com/KomodoPlatform/komodo/tree/d7edae28b8f49de5c4ae6f7ab24b29fc5ab14320) | [![dPOW Status](https://badges.komodo.live/svg/ZILLA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
