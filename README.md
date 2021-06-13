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
KMD | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
LTC | [bitcoin](https://github.com/litecoin=project/litecoin) | 0.16 | [![dPOW Status](https://badges.komodo.live/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
AXO | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/AXO_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
AYA | [aryacoin](https://github.com/KomodoPlatform/AYAv2) | [3d03bdf](https://github.com/KomodoPlatform/AYAv2/commit/3d03bdfc27cd4920ad8c3340bcaef15691b7f843) | [![dPOW Status](https://badges.komodo.live/svg/AYA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
BET | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/BET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
BOTS | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/BOTS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
BTCH | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/BTCH_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CCL | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/CCL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CHIPS | [chips](https://github.com/chips-blockchain) | [70362d](https://github.com/chips-blockchain/chips/commit/70362d54645748194b72e1cc753cca8be4f8629b) | [![dPOW Status](https://badges.komodo.live/svg/CHIPS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
COQUICASH | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/COQUICASH_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CRYPTO | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/CRYPTO_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
DEX | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/DEX_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
EMC2 | [emc2](https://github.com/emc2foundation/einsteinium) | [70d7dc2](https://github.com/emc2foundation/einsteinium/tree/70d7dc2b94e0b275f026ae51fda2a23725929bfd) | [![dPOW Status](https://badges.komodo.live/svg/EMC2_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
GleecBTC | [gleecbtc](https://github.com/KomodoPlatform/GleecBTC-FullNode-Win-Mac-Linux) | [3c486d4](https://github.com/KomodoPlatform/GleecBTC-FullNode-Win-Mac-Linux/tree/3c486d448dece7fc9a174b7a2eb36e651c1f3529) | [![dPOW Status](https://badges.komodo.live/svg/GLEECBTC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
GLEEC | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/GLEEC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
HODL | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/HODL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
ILN | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/ILN_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
JUMBLR | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/JUMBLR_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
KOIN | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/KOIN_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MCL | [marmarachain](https://github.com/marmarachain/Marmara-v.1.0) | [03dd780](https://github.com/marmarachain/Marmara-v.1.0/tree/03dd78037067ebb27af8b33f6adcdbede3813007) | [![dPOW Status](https://badges.komodo.live/svg/MCL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3p
MESH | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/MESH_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MGW | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/MGW_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MORTY | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MSHARK | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/MSHARK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
NINJA | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/NINJA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
OOT | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/OOT_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PANGEA | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/PANGEA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PIRATE | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/PIRATE_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
REVS | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/REVS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
RICK | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/RICK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
SFUSD | [sfusd](https://github.com/pbcllc/sfusd-core) | [d96497c](https://github.com/pbcllc/sfusd-core/commit/d96497cbcec0dcf185cc149f1b3988a5964e5112) | [![dPOW Status](https://badges.komodo.live/svg/SFUSD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
SUPERNET | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/SUPERNET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
THC | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/THC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
VRSC | [verus](https://github.com/VerusCoin/VerusCoin) | [7a740d2 (v0.7.3-6)](https://github.com/VerusCoin/VerusCoin/tree/7a740d2b02f54457e2a8b2d205387ed3895aacc9) | [![dPOW Status](https://badges.komodo.live/svg/VRSC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
ZILLA | [komodo](https://github.com/komodoplatform/komodo) | [24c449b](https://github.com/KomodoPlatform/komodo/tree/24c449b7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](https://badges.komodo.live/svg/ZILLA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
