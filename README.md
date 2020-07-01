# dPoW client _iguana_

This repository is based on the original SuperNET codebase - commit [f29913e92b117399cd42e2fd05ff0d69d152c8fa](https://github.com/ca333/SuperNET/commit/f29913e92b117399cd42e2fd05ff0d69d152c8fa)

Integration | Status 
-------------|------
CI build - Ubuntu (16.04, 18.04) | [![Build Status](https://github.com/komodoplatform/dpow/workflows/CI/badge.svg?maxAge=60)](https://github.com/KomodoPlatform/dPoW/actions)
Codefactor analysis | [![Grade](https://img.shields.io/codefactor/grade/github/komodoplatform/dpow)](https://www.codefactor.io/repository/github/komodoplatform/dpow)
Version | [![Version](https://img.shields.io/github/v/release/komodoplatform/dPoW)](https://github.com/KomodoPlatform/dPoW/releases)

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

#### [Notary Node metrics](http://stats.kmd.io/) - http://stats.kmd.io/

[![dPOW Status](http://116.203.64.110/svg/date_badge.svg?maxAge=60)](https://komodostats.com)
* active - last notarization less than 2.5 hours ago
* irregular - last notarization more than 2.5 and less than 24 hours ago
* inactive - last notarization more than 24 hours ago

Coin | src | Version/Tree | Status | dPoW 
--------|------|---|------|------
KMD | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
BTC | [bitcoin](https://github.com/bitcoin/bitcoin) | 0.16 | [![dPOW Status](http://116.203.64.110/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-Mainnet
AXO | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/AXO_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
AYA | [aryacoin](https://github.com/sillyghost/AYAv2) | [fd94422 (AYAv2.1.0)](https://github.com/sillyghost/AYAv2/tree/fd94422aff2886919dc963d85c313df4dfb0d770) | [![dPOW Status](http://116.203.64.110/svg/AYA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
BET | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/BET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
BOTS | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/BOTS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
BTCH | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/BTCH_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CCL | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/CCL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CHIPS | [chips](https://github.com/jl777/chips3/tree/master) | [31d59f9](https://github.com/jl777/chips3/tree/31d59f9d8fa4a8e00dd474ef0561a5b174056d86) | [![dPOW Status](http://116.203.64.110/svg/CHIPS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
COQUICASH | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/COQUICASH_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
CRYPTO | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/CRYPTO_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
DEX | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/DEX_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
EMC2 | [emc2](https://github.com/emc2foundation/einsteinium) | [70d7dc2](https://github.com/emc2foundation/einsteinium/tree/70d7dc2b94e0b275f026ae51fda2a23725929bfd) | [![dPOW Status](http://116.203.64.110/svg/EMC2_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
GAME | [game](https://github.com/gamecredits-project/GameCredits) | latest master (025f105) | [![dPOW Status](http://116.203.64.110/svg/GAME_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
HODL | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/HODL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
HUSH3 | [hush3](https://github.com/myhush/hush3) | [7f7876d](https://github.com/MyHush/hush3/tree/7f7876d2084daebc89b1914c870fa407c4fbef4e) | [![dPOW Status](http://116.203.64.110/svg/HUSH3_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
ILN | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/ILN_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
JUMBLR | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/JUMBLR_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
KOIN | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/KOIN_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MCL | [marmarachain](https://github.com/marmarachain/Marmara-v.1.0) | [03dd780](https://github.com/marmarachain/Marmara-v.1.0/tree/03dd78037067ebb27af8b33f6adcdbede3813007) | [![dPOW Status](http://116.203.64.110/svg/MCL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3p
MESH | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/MESH_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MGW | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/MGW_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MORTY | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
MSHARK | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/MSHARK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
NINJA | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/NINJA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
OOT | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/OOT_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PANGEA | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/PANGEA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PGT | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/PGT_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
PIRATE | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/PIRATE_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
REVS | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/REVS_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
RFOX | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/RFOX_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
RICK | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/RICK_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
STBL | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/STBL_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
SUPERNET | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/SUPERNET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
THC | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/THC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
VRSC | [verus](https://github.com/VerusCoin/VerusCoin) | [ab82cc9 (v0.7.0-4)](https://github.com/VerusCoin/VerusCoin/tree/ab82cc9aad27db997d8dd9d30ebd973a78c22abc) | [![dPOW Status](http://116.203.64.110/svg/VRSC_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-3P
WLC21 | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/WLC21_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
ZILLA | [komodo](https://github.com/komodoplatform/komodo) | [e159b4e](https://github.com/KomodoPlatform/komodo/tree/e159b4e7a40d3886519401c4074e957a1f9d42ba) | [![dPOW Status](http://116.203.64.110/svg/ZILLA_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet
