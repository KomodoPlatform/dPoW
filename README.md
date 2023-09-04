# dPoW client _iguana_

This repository is based on the original SuperNET codebase - commit [f29913e92b117399cd42e2fd05ff0d69d152c8fa](https://github.com/ca333/SuperNET/commit/f29913e92b117399cd42e2fd05ff0d69d152c8fa)

| Integration                      | Status                                                                                                                                          |
| -------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| CI build - Ubuntu (20.04, 22.04) | [![Build Status](https://github.com/komodoplatform/dpow/workflows/CI/badge.svg?maxAge=60)](https://github.com/KomodoPlatform/dPoW/actions)      |
| Codefactor analysis              | [![Grade](https://img.shields.io/codefactor/grade/github/komodoplatform/dpow)](https://www.codefactor.io/repository/github/komodoplatform/dpow) |
| Version                          | [![Version](https://img.shields.io/github/v/release/komodoplatform/dPoW)](https://github.com/KomodoPlatform/dPoW/releases)                      |
| Network Statistics               | https://stats.kmd.io/                                                                                                                           |

---

## Installation

General [Setup instructions](https://github.com/KomodoPlatform/Documentation/blob/nn_docs_update/docs/notary/setup-Komodo-Notary-Node.md)

### Build instructions for NN operations:

`cd iguana`

#### Build iguana for notary operations

`make`

#### Start main-net notarizations:

`./m_notary_main`

#### Start 3rd party notarizations:

`./m_notary_3rdparty`

#### Start 3rd party notarizations (in Docker):

`./m_notary_3rdparty_docker`

**Please note: Automatic UTXO split is deactivated by default.**

## dPoW asset status

### dPoW assets update requirements

**Please note:** All dPoW protected blockchain projects are required to open an issue ticket with upgrade details in this repository and at least 4 weeks prior to a mandatory update - in case of significant code changes (>2000 lines of code altered/added) open the issue ticket at least 8 weeks prior to the mandatory update. Send the official update announcement ref to `partners@komodoplatform.com`.

#### [Notary Node metrics](http://stats.kmd.io/) - http://stats.kmd.io/

#### [Notary Addresses](https://deckersu.github.io/notaries_addresses.html)

[![dPOW Status](https://badges.komodo.earth/svg/date_badge.svg?maxAge=60)](https://komodostats.com)

- active - last notarization less than 2.5 hours ago
- irregular - last notarization more than 2.5 and less than 24 hours ago
- inactive - last notarization more than 24 hours ago

| Coin     | src                                                      | Version/Tree                                                                                           | Status                                                                                                  | dPoW         |
| -------- | -------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------- | ------------ |
| KMD      | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-Mainnet |
| LTC      | [litecoin](https://github.com/litecoin-project/litecoin) | [0.16](https://github.com/litecoin-project/litecoin/tree/69fce744115a7d2889ff1b90e89582b83de405ad)     | [![dPOW Status](https://badges.komodo.earth/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-Mainnet |
| CCL      | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/CCL_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-mainnet |
| CLC      | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/CLC_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-mainnet |
| DOC      | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-mainnet |
| GLEEC    | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/GLEEC_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-mainnet |
| ILN      | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/ILN_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-mainnet |
| KOIN     | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/KOIN_badge.svg?maxAge=60)](https://komodostats.com)     | dPoW-mainnet |
| MARTY    | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-mainnet |
| NINJA    | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/NINJA_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-mainnet |
| PIRATE   | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/PIRATE_badge.svg?maxAge=60)](https://komodostats.com)   | dPoW-mainnet |
| SUPERNET | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/SUPERNET_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet |
| THC      | [komodo](https://github.com/komodoplatform/komodo)       | [156dba6](https://github.com/KomodoPlatform/komodo/tree/156dba60184c07d0781a57d5b5005b8f3dba0c98)      | [![dPOW Status](https://badges.komodo.earth/svg/THC_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-mainnet |
| AYA      | [aryacoin](https://github.com/KomodoPlatform/AYAv2)      | [d40b0d7](https://github.com/KomodoPlatform/AYAv2/tree/d40b0d7682d1568fc4bb5a18c705c0681ecfaa85)       | [![dPOW Status](https://badges.komodo.earth/svg/AYA_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-3P      |
| CHIPS    | [chips](https://github.com/chips-blockchain/chips)       | [f0dfd82](https://github.com/chips-blockchain/chips/tree/f0dfd82dd9f98626dd0045c3ed93102dfd5988fb)     | [![dPOW Status](https://badges.komodo.earth/svg/CHIPS_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-3P      |
| EMC2     | [emc2](https://github.com/emc2foundation/einsteinium)    | [8d988f0](https://github.com/emc2foundation/einsteinium/tree/8d988f05a5ccafed5cf4c16493ef30cf3125f7a9) | [![dPOW Status](https://badges.komodo.earth/svg/EMC2_badge.svg?maxAge=60)](https://komodostats.com)     | dPoW-3P      |
| MCL      | [marmarachain](https://github.com/marmarachain/marmara)  | [c675fcb](https://github.com/marmarachain/marmara/tree/c675fcb5bce34b6bb2ae8032109302a7473035cb)       | [![dPOW Status](https://badges.komodo.earth/svg/MCL_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-3p      |
| MIL      | [mil](https://github.com/emc2foundation/mil)             | [5df2e4d](https://github.com/emc2foundation/mil/tree/5df2e4d569e546c71e730aa85ad2a0813f3b6369)         | [![dPOW Status](https://badges.komodo.earth/svg/MIL_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-3P      |
| TOKEL    | [tokel](https://github.com/TokelPlatform/tokel)          | [f1fc997](https://github.com/TokelPlatform/tokel/tree/f1fc997c5b66ea53992c77a8478aa5a157c4fbc3)        | [![dPOW Status](https://badges.komodo.earth/svg/TOKEL_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-3P      |
| VRSC     | [verus](https://github.com/VerusCoin/VerusCoin)          | [25f82df](https://github.com/VerusCoin/VerusCoin/tree/25f82df12aee24c64681ca69ddd21ae19528fe25)        | [![dPOW Status](https://badges.komodo.earth/svg/VRSC_badge.svg?maxAge=60)](https://komodostats.com)     | dPoW-3P      |
