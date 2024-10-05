# dPoW 0.8.0 update information


## GLEEC Update: Prior season nodes only
#### Stop `GLEEC`, and move the data folder 

```bash
komodo-cli -ac_name=GLEEC stop
mv ~/.komodo/GLEEC ~/.komodo/GLEEC_OLD
```
## All nodes
#### Launch new version of `GLEEC`

```bash
source ~/dPoW/iguana/pubkey.txt
komodod -pubkey=$pubkey -ac_name=GLEEC -ac_supply=1000000000 -ac_end=1 -ac_public=1 -ac_staked=50 -addnode=65.21.52.182 -addnode=135.181.80.132 &

# Import Main server private key
komodo-cli -ac_name=GLEEC importprivkey ${YOUR_MAIN_SERVER_PRIVATE_KEY}
```

#### Launch old version of `GLEEC` with `datadir` param

```bash
source ~/dPoW/iguana/pubkey.txt
komodod -pubkey=$pubkey -ac_name=GLEEC -ac_supply=210000000 -ac_public=1 -ac_staked=100 -addnode=95.217.161.126 -addnode=209.222.101.247 -addnode=103.195.100.32 -datadir=${HOME}/.komodo/GLEEC_OLD &
```

#### Check GLEEC installation

When both GLEEC daemons are running, check your GLEEC installation using `./dPoW/iguana/checkGLEEC.sh`. If everything is correct, it should display "GLEEC install - Ok!". In case of errors, verify that your GLEEC chain launch parameters are correct and that the directory names match the documentation (i.e., GLEEC_OLD for the old GLEEC chain and GLEEC for the new one). Try to resolve the errors by resyncing the chains or correcting any issues you find.

#### Open the Iguana P2P ports

Please note that iguana ports were changed to 13348 for main and 13345 3rd party networks
After git pull restart your iguana and adjust your firewall settings accordingly, e.g. :

- `sudo ufw allow 13848/tcp comment 'iguana s8 mainnet p2p'`
- `sudo ufw allow 13845/tcp comment 'iguana s8 3rd p2p' `

If you are a returning Notary Node operator, don't forget to close the Season 7 Iguana ports and the ports for removed coins once Season 8 begins. Follow the instructions in [https://www.cyberciti.biz/faq/how-to-delete-a-ufw-firewall-rule-on-ubuntu-debian-linux/](https://www.cyberciti.biz/faq/how-to-delete-a-ufw-firewall-rule-on-ubuntu-debian-linux/).

#### Update and restart Iguana

```bash
cd ~/dPoW/iguana
git checkout master 
git pull
make
./m_notary_main
./m_notary_3rdparty # or ./m_notary_3rdparty_docker
```


#### Would you like to know more?

Full Setup Instructions at [https://komodoplatform.com/en/docs/notary/](https://komodoplatform.com/en/docs/notary/)

