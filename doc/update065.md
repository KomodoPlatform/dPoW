### For All Season 6 Ops - Verus and MM2 API seednode update 

#### Update NATURE & SIXCOIN (on 3P node)

These new coins are Antara smartchains, so no deamon install or building is needed - we just use our existing komodod.

```bash
# Source your pubkey
cd ~/komodo/src
source ~/dPoW/iguana/pubkey.txt

# Start NATURE
./komodod -ac_name=NATURE -ac_supply=1999999999 -ac_reward=1000000000 -ac_perc=100000000 -ac_snapshot=1440 -ac_blocktime=120 -ac_cbmaturity=2 -ac_public=1 -ac_cc=666 -ac_founders=1 -ac_script=a914928d456c145599dad2de18c4afa1cb3c34692ec587 -ac_adaptivepow=1 -pubkey=$pubkey -addnode=44.235.28.232 -addnode=44.234.227.211 -addnode=52.40.137.187 -addnode=44.212.140.52 -addnode=3.210.245.206 &
./komodod -ac_name=NATURE importprivkey ${YOUR_PRIVATE_KEY}

# Start SIXCOIN
cd ~/komodo/src
source ~/dPoW/iguana/pubkey.txt
./komodod -ac_name=SIXCOIN -ac_supply=1999999999 -ac_reward=1000000000 -ac_perc=100000000 -ac_snapshot=1440 -ac_blocktime=120 -ac_cbmaturity=1 -ac_public=1 -ac_cc=666 -ac_founders=1 -ac_script=a9145267717e0e4a2f32f95f27eb04ae40fad07bcd7087 -ac_adaptivepow=1 -pubkey=$pubkey -addnode=35.82.212.142 -addnode=52.37.233.254 -addnode=34.231.15.102 -addnode=54.227.166.29 &

./komodod -ac_name=SIXCOIN importprivkey ${YOUR_PRIVATE_KEY}


# Check NATURE sync status
tail -f ~/.komodo/NATURE/debug.log

# Check SIXCOIN sync status
tail -f ~/.komodo/SIXCOIN/debug.log

# Update your dPoW repo and restart iguana
cd dPoW
git checkout master
git pull
pkill -9 iguana
cd iguana
./m_notary_build
./m_notary_3rdparty

# Split funds
curl --url "http://127.0.0.1:7779" --data "{\"coin\":\"NATURE\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":33}"
curl --url "http://127.0.0.1:7779" --data "{\"coin\":\"SIXCOIN\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":33}"

```

Make sure chain is running smoothly and notarisations are progressing.
