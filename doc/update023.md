### dPoW 0.2.3 update informations:

**The Hush coin's codebase is ready for Season 4 Activation in 3P node**

- Please update your Hush codebase to [7f7876d](https://github.com/MyHush/hush3/tree/7f7876d2084daebc89b1914c870fa407c4fbef4e) and build it

```bash
cd ~/hush3
git pull
git checkout 7f7876d
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Launch it

```bash
source ~/dPoW/iguana/pubkey.txt
~/hush3/src/hushd -pubkey=$pubkey -daemon
```

- Wait for the Hush chain to sync

- Update your dPoW repo

```bash
cd dPoW
git checkout master
git pull
```

- Start Notarizing Hush

```bash
~/dPoW/iguana/coins/hush3_7779
source ~/dPoW/iguana/pubkey.txt
curl --url "http://127.0.0.1:7779" --data "{\"agent\":\"iguana\",\"method\":\"dpow\",\"symbol\":\"HUSH3\",\"pubkey\":\"$pubkey\"}"
```
