### dPoW 0.6.3 update information

#### Update seednode mm2

Please update your seednodes to [`0f6c72615`](https://github.com/KomodoPlatform/atomicDEX-API/releases/download/beta-2.1.7404/mm2-0f6c72615-Linux-Release.zip).
Once updated, stop and restart your seednode(s). Make sure to check your certificates have not expired! 
If you see an error like `13 12:54:37, mm2:394] mm2:457] mm2:276] lp_native_dex:355] lp_native_dex:589] P2P initializing error: 'Error reading WSS key/cert file "/etc/letsencrypt/live/na3p.smk.dog/privkey.pem": Permission denied (os error 13)'` in your logs, check the instructions at https://github.com/smk762/nn_mm2_seed#step-4-restart-mm2 to fix the permissions.

```bash
cd ~/nn_mm2_seed
git pull
./stop_mm2.sh
./update_mm2.sh
./run_mm2.sh      # Should return {"result":"2.1.7404_mm2.1_0f6c72615_Linux_Release","datetime":"2022-08-10T18:42:54+07:00"}
tail -f mm2.log   # To check everything is running smoothly.
```


#### For Season 5 Ops still running VRSC on last season's keys

```bash
cd ~/VerusCoin
git pull
git checkout 25ed684
./zcutil/build.sh -j$(expr $(nproc) - 1)

cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
```
