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
| KMD      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-Mainnet |
| LTC      | [litecoin](https://github.com/litecoin-project/litecoin) | [0.16](https://github.com/litecoin-project/litecoin/tree/69fce744115a7d2889ff1b90e89582b83de405ad)     | [![dPOW Status](https://badges.komodo.earth/svg/KMD_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-Mainnet |
| CCL      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/CCL_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-mainnet |
| CLC      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/CLC_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-mainnet |
| DOC      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-mainnet |
| GLEEC    | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/GLEECOLD_badge.svg?maxAge=60)](https://komodostats.com) | dPoW-mainnet |
| ILN      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/ILN_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-mainnet |
| KOIN     | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/KOIN_badge.svg?maxAge=60)](https://komodostats.com)     | dPoW-mainnet |
| MARTY    | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/MORTY_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-mainnet |
| PIRATE   | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/PIRATE_badge.svg?maxAge=60)](https://komodostats.com)   | dPoW-mainnet |
| THC      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://badges.komodo.earth/svg/THC_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-mainnet |
| MCL      | [marmarachain](https://github.com/marmarachain/marmara)  | [7938b2c](https://github.com/marmarachain/marmara/commit/7938b2cb5d791ee30790384903a61a4934b7e8f1)     | [![dPOW Status](https://badges.komodo.earth/svg/MCL_badge.svg?maxAge=60)](https://komodostats.com)      | dPoW-3p      |
| TOKEL    | [tokel](https://github.com/TokelPlatform/tokel)          | [b97260d](https://github.com/TokelPlatform/tokel/commit/b97260d4ac9d91f6bd28b116a1cee794a3a3035e)      | [![dPOW Status](https://badges.komodo.earth/svg/TOKEL_badge.svg?maxAge=60)](https://komodostats.com)    | dPoW-3P      |
