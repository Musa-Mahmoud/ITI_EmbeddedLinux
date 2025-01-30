#!/bin/zsh

ARG=$1

if [ "$ARG" = "clean" ]; then
    rm led.* final.map
elif [ -z "$ARG" ]; then
    ~/x-tools/aarch64-rpi3-linux-gnu/bin/aarch64-rpi3-linux-gnu-gcc -mcpu=cortex-a53 -nostdlib -static -ffreestanding main.c startup.s -T linker.ld -Wl,-Map=final.map -o led.elf
    ~/x-tools/aarch64-rpi3-linux-gnu/bin/aarch64-rpi3-linux-gnu-objcopy led.elf -O binary led.img
else
    echo "Invalid command"
fi
