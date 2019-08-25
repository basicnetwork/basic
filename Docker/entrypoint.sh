#!/bin/sh
cd /opt/basic/bin

if [ -f '/opt/basic/bin/data-dir/config.ini' ]; then
    echo
  else
    cp /config.ini /opt/basic/bin/data-dir
fi

if [ -f '/opt/basic/bin/data-dir/genesis.json' ]; then
    echo
  else
    cp /genesis.json /opt/basic/bin/data-dir
fi

if [ -d '/opt/basic/bin/data-dir/contracts' ]; then
    echo
  else
    cp -r /contracts /opt/basic/bin/data-dir
fi

exec /opt/basic/bin/basicd $@
