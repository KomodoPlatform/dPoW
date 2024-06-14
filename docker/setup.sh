#!/bin/bash
script_path=$(dirname $(realpath $0))

source ../iguana/pubkey.txt
if test -z "$pubkey"; then
    echo "Please make sure your public key is set in ~/dPoW/iguana/pubkey.txt"
    exit 1
fi

echo "Updating repository..."
git pull || sleep 5

echo "Downloading Zcach params..."
mkdir -p /home/${USER}/.zcash-params
./fetch-params.sh

echo "Setting up .env file..."
USER_ID=$(id -u)
GROUP_ID=$(id -g)
echo "PUBKEY=${pubkey}" > .env
echo "USER_ID=${USER_ID}" >> .env
echo "GROUP_ID=${GROUP_ID}" >> .env

echo "Setting up docker compose file..."
cp docker-compose.yml.template docker-compose.yml
sed "s/USERNAME/${USER}/gi" -i "docker-compose.yml"

echo "Setting up cli wrappers..."
ln -sf ${script_path}/cli_wrappers/doc-cli /home/$USER/.local/bin/doc-cli
ln -sf ${script_path}/cli_wrappers/marty-cli /home/$USER/.local/bin/marty-cli

echo "Setting up launch_files..."
cp ${script_path}/launch_files/run_DOC.sh.template run_DOC.sh
cp ${script_path}/launch_files/run_MARTY.sh.template run_MARTY.sh
sed "s/USER_PUBKEY/${pubkey}/gi" -i run_DOC.sh
sed "s/USER_PUBKEY/${pubkey}/gi" -i run_MARTY.sh

echo "Setting up conf files..."
mkdir -p /home/${USER}/.komodo/DOC
mkdir -p /home/${USER}/.komodo/MARTY
echo "" > /home/${USER}/.komodo/DOC/debug.log
echo "" > /home/${USER}/.komodo/MARTY/debug.log

rpcuser=$(tr -dc A-Za-z0-9 </dev/urandom | head -c 16)
rpcpassword=$(tr -dc A-Za-z0-9 </dev/urandom | head -c 16)
cp -f ${script_path}/conf_files/DOC.conf /home/${USER}/.komodo/DOC/DOC.conf
echo "rpcpassword=${rpcuser}" >> /home/${USER}/.komodo/DOC/DOC.conf
echo "rpcpassword=${rpcpassword}" >> /home/${USER}/.komodo/DOC/DOC.conf

rpcuser=$(tr -dc A-Za-z0-9 </dev/urandom | head -c 16)
rpcpassword=$(tr -dc A-Za-z0-9 </dev/urandom | head -c 16)
cp -f ${script_path}/conf_files/MARTY.conf /home/${USER}/.komodo/MARTY/MARTY.conf
echo "rpcpassword=${rpcuser}" >> /home/${USER}/.komodo/MARTY/MARTY.conf
echo "rpcpassword=${rpcpassword}" >> /home/${USER}/.komodo/MARTY/MARTY.conf

echo "Make sure you update the whitelist addresses in /home/${USER}/.komodo/MARTY/MARTY.conf and /home/${USER}/.komodo/DOC/DOC.conf files to include your own address before building the docker images!"
echo "Setup complete!"
