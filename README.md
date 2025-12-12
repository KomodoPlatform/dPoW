# dPoW client _iguana_

This repository is based on the original SuperNET codebase - commit [f29913e92b117399cd42e2fd05ff0d69d152c8fa](https://github.com/ca333/SuperNET/commit/f29913e92b117399cd42e2fd05ff0d69d152c8fa)

| Integration                      | Status                                                                                                                                          |
| -------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| CI build - Ubuntu (20.04, 22.04) | [![Build Status](https://github.com/komodoplatform/dpow/workflows/CI/badge.svg?maxAge=60)](https://github.com/KomodoPlatform/dPoW/actions)      |
| Codefactor analysis              | [![Grade](https://img.shields.io/codefactor/grade/github/komodoplatform/dpow)](https://www.codefactor.io/repository/github/komodoplatform/dpow) |
| Version                          | [![Version](https://img.shields.io/github/v/release/komodoplatform/dPoW)](https://github.com/KomodoPlatform/dPoW/releases)                      |
| Network Statistics               | [https://notary-stats.dragonhound.info](https://notary-stats.dragonhound.info/)/                                                                                 |

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

| Coin     | src                                                      | Version/Tree                                                                                           | Status                                                                                                              | dPoW         |
| -------- | -------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------- | ------------ |
| KMD      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/KMD.svg)](https://notary-stats.dragonhound.info/)      | dPoW-Mainnet |
| LTC      | [litecoin](https://github.com/litecoin-project/litecoin) | [0.21.4](https://github.com/litecoin-project/litecoin/tree/beae01d62292a0aab363b7a4d3f606708cea7260)   | [![dPOW Status](https://notary-stats.dragonhound.info/badges/LTC.svg)](https://notary-stats.dragonhound.info/)      | dPoW-Mainnet |
| BCZERO   | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/BCZERO.svg)](https://notary-stats.dragonhound.info/)   | dPoW-mainnet |
| CCL      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/CCL.svg)](https://notary-stats.dragonhound.info/)      | dPoW-mainnet |
| CLC      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/CLC.svg)](https://notary-stats.dragonhound.info/)      | dPoW-mainnet |
| GLEEC    | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/GLEEC.svg)](https://notary-stats.dragonhound.info/)    | dPoW-mainnet |
| ILN      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/ILN.svg)](https://notary-stats.dragonhound.info/)      | dPoW-mainnet |
| KOIN     | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/KOIN.svg)](https://notary-stats.dragonhound.info/)     | dPoW-mainnet |
| MDX      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/MDX.svg)](https://notary-stats.dragonhound.info/)      | dPoW-mainnet |
| PIRATE   | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/PIRATE.svg)](https://notary-stats.dragonhound.info/)   | dPoW-mainnet |
| RAPH     | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/RAPH.svg)](https://notary-stats.dragonhound.info/)     | dPoW-mainnet |
| THC      | [komodo](https://github.com/komodoplatform/komodo)       | [2651eaf](https://github.com/KomodoPlatform/komodo/commit/2651eafc5219de3775cb08ff128c334d4c812aa9)    | [![dPOW Status](https://notary-stats.dragonhound.info/badges/THC.svg)](https://notary-stats.dragonhound.info/)      | dPoW-mainnet |
| MCL      | [marmarachain](https://github.com/marmarachain/marmara)  | [7938b2c](https://github.com/marmarachain/marmara/commit/7938b2cb5d791ee30790384903a61a4934b7e8f1)     | [![dPOW Status](https://notary-stats.dragonhound.info/badges/MCL.svg)](https://notary-stats.dragonhound.info/)      | dPoW-3p      |
| TOKEL    | [tokel](https://github.com/TokelPlatform/tokel)          | [b97260d](https://github.com/TokelPlatform/tokel/commit/b97260d4ac9d91f6bd28b116a1cee794a3a3035e)      | [![dPOW Status](https://notary-stats.dragonhound.info/badges/TOKEL.svg)](https://notary-stats.dragonhound.info/)    | dPoW-3P      |


