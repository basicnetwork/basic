#!/bin/bash

# Usage:
# Go into cmd loop: sudo ./basicc.sh
# Run single cmd:  sudo ./basicc.sh <basicc paramers>

PREFIX="docker exec docker_basic_1 basicc"
if [ -z $1 ] ; then
  while :
  do
    read -e -p "basicc " cmd
    history -s "$cmd"
    $PREFIX $cmd
  done
else
  $PREFIX $@
fi
