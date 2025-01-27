# dPoW 0.8.4 update information

The primary purpose of this update is to reduce resource usage on Notary Node mainnet servers by removing the test chains `DOC` and `MARTY` from dPoW. However, these chains will remain operational for testing purposes within the Komodo Wallet and the Komodo DeFi Framework (KDF). This means removing them from your servers is optional and at your discretion.

This update specifically removes the `DOC` and `MARTY` chains from dPoW, meaning they will no longer be processed by `iguana`. Regarding the Komodo core daemon (`komodod`), if your server’s resources allow, you can continue running `komodod` for these chains to assist with block propagation and other related tasks.

### Stop and remove `DOC` & `MARTY` (optional)

```bash
komodo-cli -ac_name=DOC stop
komodo-cli -ac_name=MARTY stop
rm -rf ~/.komodo/DOC
rm -rf ~/.komodo/MARTY
```

### Restart Iguana

```bash
# Update dPoW repo
cd ~/dPoW
git checkout master
git pull

# Restart Iguana
pkill -9 iguana  # Note: This command may also terminate 3P Iguana if it is running on the same server.
cd iguana
./m_notary_build
./m_notary_main
```

Make sure notarisations are progressing.


