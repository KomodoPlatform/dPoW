#!/bin/bash
set -eo pipefail

## Set the cli binary
cli = $1

## Get the number of node connections
conn=$(${cli} getconnectioncount)

## If we have no connections throw an error
if [ "$conn" -eq "0" ]; then
    ## Log error
    echo "HEALTHCHECK: FAIL - ${cli} has ${conn} active node connections.";
    ## Exit with error
    exit 1;
else
    ## Log succesful health check
    echo "HEALTHCHECK: SUCCESS - ${cli} has ${conn} active node connections.";
    ## Exit with success
    exit 0;
fi
