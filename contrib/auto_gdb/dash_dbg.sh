#!/usr/bin/env bash
# use testnet settings,  if you need mainnet,  use ~/.dashcore/amerod.pid file instead
export LC_ALL=C

dash_pid=$(<~/.dashcore/testnet3/amerod.pid)
sudo gdb -batch -ex "source debug.gdb" amerod ${dash_pid}
