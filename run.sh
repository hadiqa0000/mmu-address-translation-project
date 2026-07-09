#!/bin/bash


set -e


MODULE_NAME="verify_paddr"

# Check if the user provided a physical address argument
if [ -z "$1" ]; then
    echo "❌ Error: Missing physical address."
    echo "Usage: $0 <physical_address>"
    echo "Example: $0 0x1e6fd9000"
    exit 1
fi

PHYS_ADDR=$1

make clean > /dev/null 2>&1 || true
make


if lsmod | grep -q "$MODULE_NAME"; then
   
    sudo rmmod $MODULE_NAME
fi

