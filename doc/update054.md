### dPoW 0.5.4 update information

- Build and Sync the `tokel` branch of the komodo repository (https://github.com/KomodoPlatform/komodo/tree/tokel) and rename it to a tokel specific folder.

```bash
git clone https://github.com/komodoplatform/komodo -b tokel tokelkomodo
cd ~/tokelkomodo
./zcutil/build.sh
```

- Start and sync the Tokel chain

```bash
source ~/komodo/src/pubkey.txt
cd ~/tokelkomodo/src
./komodod -ac_name=TOKEL <<<TBA>>>
```

- Check you are on the right chain:

```bash
>>>>>>>>>> TOKEL: <<<TBA>>>
```

- Open p2p port

```bash
sudo ufw allow <<<TBA>>>/tcp
```

- Import your private key, you should have received TKL funding.

```bash
./komodo-cli -ac_name=TOKEL importprivkey <your-3p-privkey>
```

- Update your dPoW repo, Kill iguana, and restart it

```bash
cd ~/dPoW
git checkout master
git pull
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_3rdparty # start notarization
```

Split $TOKEL UTXOs with your normal acsplit script or any other way to make 0.0001.

E.G

```bash
chain="TOKEL"
unspent=$(~/komodo/src/komodo-cli -ac_name=${chain} listunspent | jq '[.[] | select (.generated==false and .amount==0.0001 and .spendable==true and (.scriptPubKey == "'${pubkey}'"))] | length')
echo "${chain}: $unspent"
if [ $unspent -lt 20 ]; then
  echo "Topping up ${chain}"
  curl --url "http://127.0.0.1:7779" --data "{\"coin\":\""${chain}"\",\"agent\":\"iguana\",\"method\":\"splitfunds\",\"satoshis\":\"10000\",\"sendflag\":1,\"duplicates\":"20"}"
fi
```
