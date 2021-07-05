#!/usr/bin/env bash
# use testnet settings,  if you need mainnet,  use ~/.amerocore/amerox.pid file instead
export LC_ALL=C

amero_pid=$(<~/.amerocore/testnet3/amerox.pid)
sudo gdb -batch -ex "source debug.gdb" amerox ${amero_pid}
