## dPoW 0.7.8 update information

- On your 3P node, update your Verus Coin's codebase to [`54e0cf2`](https://github.com/VerusCoin/VerusCoin/tree/54e0cf27af6cc1f0204830f7009e10d9a05d040b), build it and then restart it.

### Update VSRC

#### Using docker setup

```bash
cd notary_docker_3p
git pull
./update vrsc # supply sudo password when asked
./start vrsc
```

#### Using other setup

- Build Verus Coin

```bash
vrsc_commit='54e0cf2'
cd ~/VerusCoin
git pull
git checkout ${vrsc_commit}
./zcutil/build.sh -j$(expr $(nproc) - 1)
```

- Restart it

```bash
cd ~/VerusCoin/src
./verus stop
source ~/dPoW/iguana/pubkey.txt
./verusd -pubkey=$pubkey &
```

#### Update your dPoW repo

```bash
cd ~/dPoW
git checkout master
git pull
```

Once complete, monitor your node to ensure it is running correctly and notarisations are progressing.


### Update your seed node.

Update your MM2 seed node codebase to the [latest release](https://github.com/KomodoPlatform/komodo-defi-framework/releases/tag/v1.0.7-beta)  [`79f6205 `](https://github.com/KomodoPlatform/komodo-defi-framework/tree/79f620559a635704959d3e88067f7ffe5ee30f1f)

- If using the https://github.com/smk762/nn_mm2_seed repo, update it and restart:

```bash
cd ~/nn_mm2_seed
git pull
./update_coins.sh
./update_mm2.sh
./stop_mm2.sh
./run_mm2.sh
```

- If using the https://github.com/smk762/notary_docker_3p repo, update it and restart:

```bash
cd ~/notary_docker_3p
git pull
./update mm2
./start mm2
```

- Once complete, check the mm2 logs to confirm it is running correctly.
- Run `./version.sh` to confirm the version is `v1.0.7-beta`

### Update Dragon Node

If using https://github.com/smk762/dragon_node repo, update it to align with the latest seed node version:

```bash
cd ~/dragon_node
git pull
./stats
```
