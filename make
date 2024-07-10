#!/bin/bash
#===============================================================================
# Copyright (C) Andrzej Adamczyk (at https://blackdev.org/). All rights reserved.
#===============================================================================

# clear view of what's goin on
clear

# delete old files
rm -rf build && mkdir -p build/iso

# we use clang, as no cross-compiler needed
C="clang -include ./library/std.h"
LD="ld.lld"

# default flags for clang
ARCH="x86-64"
DEFAULT_FLAGS="-march=${ARCH} -mtune=generic -Ofast -m64 -ffreestanding -nostdlib -nostartfiles -fno-stack-protector -fno-builtin -mno-red-zone"
CFLAGS_KERNEL="${DEFAULT_FLAGS} -mno-mmx -mno-sse -mno-sse2 -mno-3dnow"
LDFLAGS="-nostdlib -static -no-dynamic-linker"

# external resources initialization
git submodule update --init

# build kernel file
${C} -c kernel/init.c -o build/kernel.o ${CFLAGS_KERNEL} || exit 1;
${LD} build/kernel.o -o build/kernel -T tools/linker.kernel ${LDFLAGS} || exit 1;

# copy compressed kernel file and limine files into destined iso folder
gzip -k build/kernel
cp build/kernel.gz tools/limine.cfg limine/limine-bios.sys limine/limine-bios-cd.bin limine/limine-uefi-cd.bin build/iso

# convert iso directory to iso file
xorriso -as mkisofs -b limine-bios-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table --efi-boot limine-uefi-cd.bin -efi-boot-part --efi-boot-image --protective-msdos-label build/iso -o build/barebones.iso > /dev/null 2>&1

# install bootloader limine inside created
limine/limine bios-install build/barebones.iso > /dev/null 2>&1