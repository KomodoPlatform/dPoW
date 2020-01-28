### dPoW 0.1.2 update informations:

<b>Please note</b>: https://github.com/KomodoPlatform/dPoW#dpow-asset-status contains repo, branch and version information ref. all dPoW assets. For Komodo, ACs and dPoW you can either use the master branch or the tagged release version.


- HUSH3 is migrating to 3P NN operations on January 29th. Please stop your HUSH3 NN operations on the main NN <b>now</b> and make sure you are running HUSH3 [3.3.1](https://github.com/MyHush/hush3/releases/tag/v3.3.1) on your 3P NN as advised in the [ 0.1.1 update instructions](https://github.com/KomodoPlatform/dPoW/blob/master/doc/update011.md). Restart the NN operations on January 29th after the hardfork activation on block 166250.


##### check (local) time of the fork activation
```shell
cd ~/hush3
./contrib/block_time.pl 166250
```

- dPoW was updated to [0.1.2](https://github.com/KomodoPlatform/dPoW/releases/tag/0.1.2) which migrates the HUSH3 NN operations from main to 3P [changelog](https://github.com/KomodoPlatform/dPoW/blob/master/doc/changelog.md) and bumped version to 0.1.2.

```shell
cd ~/dPoW
git pull
git checkout 0.1.2 #or master branch
cd iguana
./m_notary_build #rebuild/restart dPoW when HF activates
```
