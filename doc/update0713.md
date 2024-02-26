### dPoW 0.7.13 update information


### Restore THC

- Restart the THC daemon on the **main server**. This coin has been restored to the dPoW assets.

```bash
komodo-cli -ac_name=THC -ac_supply=251253103 -ac_reward=360000000,300000000,240000000,180000000,150000000,90000000,0 -ac_staked=100 -ac_eras=7 -ac_end=500001,1000001,1500001,2000001,2500001,4500001,0 -ac_perc=233333333 -ac_cc=2 -ac_ccenable=229,236,240 -ac_script=2ea22c8020987fad30df055db6fd922c3a57e55d76601229ed3da3b31340112e773df3d0d28103120c008203000401ccb8 -ac_founders=150 -ac_cbmaturity=1 -ac_sapling=1 -earlytxid=7e4a76259e99c9379551389e9f757fc5f46c33ae922a8644dc2b187af2a6adc1 -addnode=157.230.45.184 -addnode=165.22.52.123 -puskey=$pubkey
```

- Remember to import your private key, prepare utxos and open THC p2p port (`36789`) in the firewall.

### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
cd iguana
make
pkill -9 iguana
./m_notary_main && ./m_notary_3rdparty (or via Docker: ./m_notary_3rdparty_docker)
```

Restart dPoW operations and ensure that your iguana is running smoothly.
