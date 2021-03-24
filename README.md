```
git clone https://github.com/litecoin-project/litecoin
cd litecoin
git checkout 0.16
./autogen
./configure --without-gui --with-incompatible-bdb
make -j4
```

# optional, add a bash shortcut to litecoin-cli and litecoind
```
make install
```

# create litecoin.conf 
```
mkdir ~/.litecoin
echo "rpcuser=SOMEUSER" > ~/.litecoin/litecoin.conf
echo "rpcpassword=SOME_SECURE_PASSWORD" >> ~/.litecoin/litecoin.conf
echo "rpcport=9332" >> ~/.litecoin/litecoin.conf
chmod 600 ~/.litecoin/litecoin.conf
```

# start litecoind, WAIT FOR IT TO SYNC
```
cd src
./litecoind &
```

# build iguana
```
git clone https://github.com/alrighttt/dpow
cd dpow/iguana
git checkout LTC-dev
./m_notary_build
```

# create pubkey.txt with YOUR PUBKEY
```
echo 'pubkey=020000000000000000000000000000000000000000000000000000000000000000' > pubkey.txt
```

# create wp_testnet, add YOUR WIF
```
echo 'curl --url "http://127.0.0.1:7776" --data "{\"method\":\"walletpassphrase\",\"params\":[\"Uxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\", 9999999]}"' > wp_testnet
chmod 700 wp_testnet
```

# import your litecoin WIF and fund it
```
litecoin-cli importprivkey "YOUR_LTC_WIF" "" false
```


# start the notary
```
./m_notary_LTC
```
