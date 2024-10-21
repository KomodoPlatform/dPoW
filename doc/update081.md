# dPoW 0.8.1 update information

### Stop and remove `SUPERNET` & `NINJA`

```bash
komodo-cli -ac_name=SUPERNET stop
komodo-cli -ac_name=NINJA stop
rm -rf ~/.komodo/SUPERNET
rm -rf ~/.komodo/NINJA
```

### Prepare GLEEC_OLD datafolder by create a symlink (mandatory)

```bash
ln -s -f $HOME/.komodo/GLEEC_OLD/GLEEC.conf $HOME/.komodo/GLEEC_OLD/GLEEC_OLD.conf
```

### Update `komodod` on main node

```bash
cd ~/komodo/
git fetch --all
git checkout 2651eaf
./zcutil/build.sh -j$(nproc)
```

### Restart the old GLEEC chain

```bash
komodo-cli -ac_name=GLEEC -datadir=$HOME/.komodo/GLEEC_OLD stop; sleep 5
~/dPoW/iguana/checkGLEEC.sh # check the GLEEC installation
source pubkey.txt
komodod -pubkey=$pubkey -ac_name=GLEEC -ac_supply=210000000 -ac_public=1 -ac_staked=100 -datadir=${HOME}/.komodo/GLEEC_OLD -addnode=95.217.161.126 -addnode=209.222.101.247 -addnode=103.195.100.32 &
```

### Make sure the old GLEEC chain is running smoothly and has caught up with the latest notarizations
```bash
komodo-cli -ac_name=GLEEC -datadir=$HOME/.komodo/GLEEC_OLD getinfo
# It should look like this: https://github.com/KomodoPlatform/komodo/pull/637#issue-2586189960
# i.e., the notarized block height should be close to the longest chain, and the name should be GLEEC_OLD.
```

This ensures the old GLEEC chain is functioning as expected and is up-to-date with notarizations.

### Restart Iguana

```bash
# Update dPoW repo
cd ~/dPoW
git checkout master
git pull

# Restart Iguana
pkill -9 iguana
cd iguana
./m_notary_build
./m_notary_main
```

Make sure notarisations are progressing.


