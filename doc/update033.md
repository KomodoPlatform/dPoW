### dPoW 0.3.3 update instructions


- Update AYA in your 3p node. Checkout to the commit `3d03bdfc27cd4920ad8c3340bcaef15691b7f843`

#### Step 1: Update AYA source code

- Stop AYA daemon and AYA dPoW operations on your 3P NN before proceeding - do make sure you are using https://github.com/KomodoPlatform/AYAv2


```bash
git clone https://github.com/KomodoPlatform/AYAv2
cd ~/AYAv2
git pull
git checkout 3d03bdf
```

#### Step 2: Build and restart AYA

```bash
./autogen.sh
./configure
make
```

- Start AYA daemon

#### Step 3: Continue AYA dpow operations

- Continue AYA dPoW operations

note: iguana does not require rebuild


