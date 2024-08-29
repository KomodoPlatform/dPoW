# dPoW 0.7.16 update information


### Stop `GLEEC`, and move the data folder

```bash
komodo-cli -ac_name=GLEEC stop
mv ~/.komodo/GLEEC ~/.komodo/GLEEC_OLD
```
### Launch new version of `GLEEC`

```bash
source ~/dPoW/iguana/pubkey.txt
komodod -pubkey=$pubkey -ac_name=GLEEC -ac_supply=1000000000 -ac_end=1 -ac_public=1 -ac_staked=50 -addnode=65.21.52.182 -addnode=135.181.80.132 &

# Import Main server private key
komodo-cli -ac_name=GLEEC importprivkey ${YOUR_MAIN_SERVER_PRIVATE_KEY}
```

### Launch old version of `GLEEC` with `datadir` param

```bash
source ~/dPoW/iguana/pubkey.txt
komodod -pubkey=$pubkey -ac_name=GLEEC -ac_supply=210000000 -ac_public=1 -ac_staked=100 -addnode=95.217.161.126 -addnode=209.222.101.247 -addnode=103.195.100.32 -datadir=${HOME}/.komodo/GLEEC_OLD &
```


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
./m_notary_3rdparty
```

Make sure notarisations are progressing.
