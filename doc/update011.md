### dPoW 0.1.1 update informations:

<b>Please note</b>: https://github.com/KomodoPlatform/dPoW#dpow-asset-status contains repo, branch and version information ref. all dPoW assets. For Komodo, ACs and dPoW you can either use the master branch or the tagged release version.


- Komodo core was updated to [0.5.2](https://github.com/KomodoPlatform/komodo/releases/tag/0.5.2) - please update your AC & Komodo mining-nodes and restart the mining daemon with `-opretmintxfee=0.004` - this feature was added in https://github.com/KomodoPlatform/komodo/commit/c4d60f8defbe8036846a9baa410411f26528355a and allows miners to set the desired minimum transaction fee for processing big opret transactions (>256 bytes). We recommend min 0.004 per 1 Kb.

```shell
cd ~/komodo
git pull
git checkout 0.5.2 #or master branch
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- HUSH3 was upgraded to [3.3.1](https://github.com/MyHush/hush3/releases/tag/v3.3.1) and will hard fork on January 29th with the season 3.5 3rd party pubkeys. Please update your HUSH3 daemon on the main NNs (keep operating on the main NN for now) and prepare the hush daemon on your 3P NN. We are updating `dPoW` for 3P operations a few days prior to the hardfork activation and will notify you for the 3P migration.

```shell
cd ~/
git clone https://github.com/MyHush/hush3
cd hush3
git checkout v3.3.1
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- dPoW was updated to [0.1.1](https://github.com/KomodoPlatform/dPoW/releases/tag/0.1.1) which removes obsoleted coins, added update instructions, NN_changelog and bumped version to 0.1.1.

```shell
cd ~/dPoW
git pull
git checkout 0.1.1 #or master branch
cd iguana
./m_notary_build
```


