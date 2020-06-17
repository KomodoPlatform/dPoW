**The Hush coin's codebase is ready for Season 4 Activation in 3P node**

- Please update your Hush codebase to [7f7876d](https://github.com/MyHush/hush3/tree/7f7876d2084daebc89b1914c870fa407c4fbef4e)
- Build it

```bash
cd ~/hush3
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Launch it (replace `$pubkey` with your 3p pubkey)

```bash
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

```