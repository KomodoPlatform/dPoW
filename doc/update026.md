### dPoW 0.3.0 update information:

**The Chips blockchain will perform a mandatory Hard Fork at block 6874120, which comes around 3rd Sep**
** The bitcoin DDA will be changed to adaptivePoW allowing CPU & ASIC mining without chain stalling**
** Please update your Chips node prior to the HF (or you'll end up on a stuck/wrong chain) on your 3P NN Server**

- Please update your Chips Coin's and iguana codebase **prior to 6874120** and build it
- It is not mandatory to mine Chips with your notary node CPU but you are encouraged to mine Chips with any CPU
- adaptivePoW was developed by jl777 and zawy12 based on LWMA, tested by KMD Team. The apow integrated in Chips is based on one of the first stable iteration/version of apow from Komodo codebase
- Mining, transactions and HF tests were performed by phm87
- Notarizing with the new code prior to HF was successfully tested by daemonfox (thank you to him)
- ASIC Attacks were tested by SHossain and phm87, thank you to SHossain
- First code review was performed by jl777 and second review by sg777, thank you to jl777 and sg777
- For any question or issue, please contact phm87
- To minimize notary node downtime, you can git pull and build chips while iguana is still running. The procedure here below was written to minimize RAM usage
- Chips official repo won't be https://github.com/jl777/chips3 anymore but it will move to https://github.com/chips-blockchain/chips ; both master branches are aligned for the aPoW HF. Official docs and dPoW Readme will be updated in another PR.

## Procedure (if your RAM is limitated):
1. Stop iguana and chips
```bash
pkill -15 iguana
chips-cli stop
```
2. Update Chips (using jl777 repo, master branch)
```bash
cd chips3
git pull
./build.sh
```
Remark: make can be more rapid than a whole build.sh
3. Start chips with your pubkey set and wait that it is synced with network
```bash
source ~/komodo/src/pubkey.txt
chipsd -pubkey=$pubkey &
```

4. Update & Launch iguana

5. Make sure your iguana is running properly and has not crashed. Restart iguana if it has crashed.


## Procedure with reduced downtime (if you have available RAM):
When Chips is stopped, Iguana will complain but if it does not crash, it can continue to notarize during Chips compilation or Chips restart.
The iguana RPC Calls stopcoin, pausecoin and startcoin can be used to avoid unecessary logs in iguana.

1. Update and build Chips
Optional: use stopcoin RPC iguana call
2. Stop Chips daemon
3. Start newly build Chips daemon
Optional: wait that Chips is synced and use startcoin RPC iguana call
4. Make sure your iguana is running properly and has not crashed. Restart iguana if it has crashed.


## How to mine Chips with CPU?
setgenerate is not present in Chips codebase, generatetoaddress works fine to use the internal miner contained in Chips codebase while Stratum mining can be done with the usual submitblock and getbalocktemplate

1. Create mine.sh with the following content
Please replace bWQKUzuWKJYCpDAv93xNuceANgL3aQ559k by your own chips address.
```bash
#!/bin/bash

date
echo started in ${DIR}

while true; do
        chips-cli generatetoaddress 100 'bWQKUzuWKJYCpDAv93xNuceANgL3aQ559k' 1000000
done
exec bash
```

2. Make mine.sh executable
```bash
chmod +x mine.sh
```

3. Mine with internal CPU miner
```bash
./mine.sh
```

4. Stop the miner
Ctrl-C to stop the script. 

