### Howto setup DPOW chain and notarizer exec

You need to do this on your **Main NN Node** if you don't want to touch it you can also use a completely new Node on which KMD BTC and DEX is synced.

The 3rd Party Node is not involved you only need the KMD Pubkey and KMD Private Key from it.

```bash
git clone https://github.com/jl777/komodo.git dexkomodo
cd ~/dexkomodo
git checkout jl777
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

add line to .komodo/komodo.conf
```bash
blocknotify=notarizer KMD "" %s
```

add line to ./komodo/DEX/DEX.conf
```bash
blocknotify=notarizer DEX "" %s
```

add line to ./bitcoin/bitcoin.conf
```bash
blocknotify=notarizer BTC bitcoin-cli %s
```

OR

```bash
echo 'blocknotify=notarizer BTC bitcoin-cli %s' >> ~/.bitcoin/bitcoin.conf
echo 'blocknotify=notarizer DEX "" %s' >> ~/.komodo/DEX/DEX.conf
echo 'blocknotify=notarizer KMD"" %s' >> ~/.komodo/komodo.conf
```
stop the affected chains

```bash
komodo-cli stop
komodo-cli -ac_name=DEX stop
bitcoin-cli stop
```
start KMD ( you are on mainnode don't forget setgenerate true 1)

start BTC

start DEX

start the DPOW chain: set 3P pubkey and handle ( find your handle here: https://github.com/jl777/komodo/blob/DEX/src/cc/dapps/pubkeys )
This chain does not have blocks so as long as you getconnections its fine

```bash
cd ~/dexkomodo/src/
./komodod -ac_name=DPOW -dexp2p=2 -addnode=136.243.58.134 -pubkey=<3rd party notarypubkey> -handle=YOUR-HANDLE
```
Import 3P KMD Priv Key to DPOW chain
```bash
komodo-cli -ac_name=DPOW importprivkey YOUR-3PKEY-HERE
```
stop the chain
```bash
komodo-cli -ac_name=DPOW stop
```

restart the DPOW chain: set 3P pubkey and handle ( find your handle here: https://github.com/jl777/komodo/blob/DEX/src/cc/dapps/pubkeys )
```bash
cd ~/dexkomodo/src/
./komodod -ac_name=DPOW -dexp2p=2 -addnode=136.243.58.134 -pubkey=<3rd party notarypubkey> -handle=YOUR-HANDLE    ( find your handle here: https://github.com/jl777/komodo/blob/DEX/src/cc/dapps/pubkeys )
```

go to
```bash
cd ~/dexkomodo/src/
gcc -o ~/.dpow/bin/notarizer cc/dapps/notarizer.c -lm
```

wait 2 minutes after that run

```bash
komodo-cli -ac_name=DPOW DEX_list 0 0 handles | jq '.matches[].tagB' | sort | uniq | jq
```
if you show up in the list you are fine

Please PR is something is missing

CHMEX

