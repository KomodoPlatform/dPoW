### dPoW 0.6.2 update information

#### Update seednode mm2

A new version of the AtomicDEX-API has just been released! Please update your seednodes to [`ce32ab8da`](https://github.com/KomodoPlatform/atomicDEX-API/releases/tag/beta-2.1.6805).
Once updated, stop and restart your seednode(s).

```bash
cd ~/nn_mm2_seed
git pull
./stop_mm2.sh
./update_mm2.sh
./run_mm2.sh
```


#### Move CHIPS & MIL to Season 6 network

CHIPS and MIL have passed their respective hardfork blocks, though VRSC is not yet ready for Season 6 so please continue VRSC dPoW operations on S5 until otherwise notified.

**S5 Ops on overtime**
Please stop both the `m_notary_3rdpary` and `m_notary_verusholdover` iguanas and restart with the new versions.

**New S6 Ops**
Please stop and restart `m_notary_3rdpary` with the new version.

```bash
cd ~/dPoW/iguana
git pull
pkill -9 iguana
./m_notary_build
./m_notary_3rdparty

# S5 overtime only
./m_notary_verusholdover
```