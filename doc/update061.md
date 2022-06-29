### dPoW 0.6.1 update information

- Update your Tokel Coin's codebase to [d2e98de](https://github.com/TokelPlatform/tokel/commit/d2e98de9d1ac6e26c20d540d5a8d7a493e2cf5fd), build it and then restart it with reindex.

```bash
cd ~/tokel/
git pull
git checkout d2e98de9d1ac6e26c20d540d5a8d7a493e2cf5fd
make -j4
source ~/komodo/src/pubkey.txt
~/tokel/src/tokeld -reindex -addnode=65.21.77.109 -addnode=147.135.105.85 -addnode=na.smk.dog -addnode=dev.smk.dog -pubkey=$pubkey &
```
