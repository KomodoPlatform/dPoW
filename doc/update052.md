### dPoW 0.5.1 update information

- Update your AYA Coin's codebase to [02afeac](https://github.com/KomodoPlatform/AYAv2/tree/02afeacdc0702bd160abef603f03167381f39097), build it and then restart it

#### AYA

- Make sure your local repo is tracking the KomodoPlatform version of the repo at https://github.com/KomodoPlatform/AYAv2 by using `cd ~/AYAv2/;git remote -v`

```bash
cd ~/AYAv2/
# git reset --hard # (if necessary)
git pull
git checkout 02afeac
./build.sh
```

Build script (build.sh) available from [https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#aryacoin-aya](https://docs.komodoplatform.com/notary/setup-Komodo-Notary-Node.html#aryacoin-aya)

- Restart it

```bash
cd ~/AYAv2/src
./aryacoin-cli stop
source ~/dPoW/iguana/pubkey.txt
./aryacoind -pubkey=$pubkey &
```

#### dPoW

- Update your dPoW repo, Kill iguana, and restart it

```bash
cd ~/dPoW
git checkout master
git pull
pkill -15 iguana
cd ~/dPoW/iguana
./m_notary_3rdparty
```
