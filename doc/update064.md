### For All Season 6 Ops - Verus and MM2 API seednode update 

#### Update VRSC (on 3P node)

```bash
# If not already cloned:
git clone https://github.com/VerusCoin/VerusCoin

# Build VRSC
cd ~/VerusCoin
git pull
git checkout bc894ba
./zcutil/build.sh -j$(expr $(nproc) - 1)

# (re)start VRSC
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
./verus-cli importprivkey ${YOUR_PRIVATE_KEY}

# Check sync status
tail -f ~/.komodo/VRSC/debug.log

# Update your dPoW repo and restart iguana (S5 new ops only, S6 overtime ops please wait for for HF block)
cd dPoW
git checkout master
git pull
pkill -9 iguana
cd iguana
./m_notary_build
./m_notary_3rdparty

# Split funds
curl --url "http://127.0.0.1:7779" --data "{\"coin\":\"VRSC\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":33}"

```

Make sure chain is running smoothly and notarisations are progressing.

** S5 Ops - thank you for your service! Don't forget to update any split scripts etc which may still be referencing the holdover port. Hardfork is at block 2291830, please wait until then to update/restart iguana. Until then, continue to use `./m_notary_verusholdover` **

#### Update Seednode

Please update your seednodes to [`6e4de5d`](https://github.com/KomodoPlatform/atomicDEX-API/releases/tag/beta-2.1.8741).
Once updated, stop and restart your seednode(s). Make sure to check your certificates have not expired! 
If you see an error like `13 12:54:37, mm2:394] mm2:457] mm2:276] lp_native_dex:355] lp_native_dex:589] P2P initializing error: 'Error reading WSS key/cert file "/etc/letsencrypt/live/na3p.smk.dog/privkey.pem": Permission denied (os error 13)'` in your logs, check the instructions at https://github.com/smk762/nn_mm2_seed#step-4-restart-mm2 to fix the permissions.

```bash
cd ~/nn_mm2_seed
git pull
./stop_mm2.sh
./update_mm2.sh
./run_mm2.sh      # Should return {"result":"2.1.8741_mm2.1_6e4de5d21_Linux_Release","datetime":"2022-11-14T13:40:18+03:00"}
tail -f mm2.log   # To check everything is running smoothly.
```