# dPoW client _iguana_

This repository is based on the original SuperNET codebase - commit [f29913e92b117399cd42e2fd05ff0d69d152c8fa](https://github.com/ca333/SuperNET/commit/f29913e92b117399cd42e2fd05ff0d69d152c8fa)

OS | Build Status 
-------------|------
Ubuntu 18.04 | [![Build Status](https://jenkinsmaster.sprnt.pw/buildStatus/icon?job=iguana-unix-jl777-release-v0.1)](https://jenkinsmaster.sprnt.pw/job/iguana-unix-jl777-release-v0.1)
Debian | [![Build Status](https://jenkinsmaster.sprnt.pw/buildStatus/icon?job=iguana-pnacl-jl777-release-v0.1)](https://jenkinsmaster.sprnt.pw/job/iguana-pnacl-jl777-release-v0.1/)
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

#

**Please note: Automatic UTXO split is deactivated by default.**
