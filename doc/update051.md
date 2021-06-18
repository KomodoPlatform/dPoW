Due to emerging situation with VRSC, notary node ops have been asked to cease dPoW operations for VRSC ASAP.
Please be on standby to update once available.

1. Stop the daemon and make the coin non-launch:
```
pkill -9 iguana
VerusCoin/src/verus stop
sed -i.old 's/coins\/vrsc/#coins\/vrsc/' dPoW/iguana/m_notary_3rdparty 
```

2. Restart dPoW operations:
`dPoW/iguana/m_notary_3rdparty`

If using nntools, @webworker01 has released an update

```
pkill -9 iguana
VerusCoin/src/verus stop
cd ~/nntools
git pull
startnotary
```

Confirm via checkmark at https://discord.com/channels/412898016371015680/456828345871761408/855252269100433438

Thanks
