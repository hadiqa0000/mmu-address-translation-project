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


sudo insmod ${MODULE_NAME}.ko phys_addr=$PHYS_ADDR


udo dmesg | tail -n 5

HEX_STRING=$(sudo dmesg | grep "Hex dump:" | tail -n 1 | awk -F "Hex dump: " '{print $2}')

if [ -n "$HEX_STRING" ]; then
    echo "Extracted Hex: $HEX_STRING"
    echo -n "Decoded Floats: "
    echo "$HEX_STRING" | xxd -r -p | od -An -t fD | awk '{$1=$1; print}'
else
    echo "❌ Could not find 'Hex dump:' in dmesg logs."
fi


sudo rmmod $MODULE_NAME

