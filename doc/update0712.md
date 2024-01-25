### dPoW 0.7.12 update information

- Shut down the THC daemon on the Main server. This coin has been removed from the dPoW assets.

```bash
komodo-cli -ac_name=THC stop
```

- Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Please restart dPoW operations and ensure that your iguana is running smoothly.

