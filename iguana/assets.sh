#!/usr/bin/env bash
# set -eo pipefail

source $HOME/config.nn

case "$1" in

  start_all)
    # Replaces assetchains
    ./listassetchainparams | while read args; do
        gen=""
        if [ $[RANDOM % 20] == 1 ]; then
          gen=" -gen -genproclimit=1"
        fi
        $komodo_binary $gen $args -pubkey=$pubkey -addnode=$seed_ip &
        sleep ${delay:-20}
    done
  ;;

  all)
    # Replaces komodo's ./fiat-cli
    ./listassetchains | while read chain; do
      echo $chain
      $cli_binary --ac_name=$chain ${*:2}
    done
  ;;

  *)
    # Replaces komodo's fiat and ac folder
    $cli_binary --ac_name=${1^^} ${*:2}
  ;;

esac
