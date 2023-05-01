#!/bin/bash
#===============================================================================
# Copyright (C) Andrzej Adamczyk (at https://blackdev.org/). All rights reserved.
#===============================================================================

clear

rm -rf build iso && mkdir build iso

C="clang"
LD="ld" # or "ld.lld" from llvm tools

CFLAGS="-O3 -march=x86-64 -m64 -nostdlib -fomit-frame-pointer -fno-builtin -fno-stack-protector -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -mno-3dnow"
LDFLAGS="-nostdlib -static -no-dynamic-linker"

git submodule update --init

${C} -c kernel.c -o build/kernel.o ${CFLAGS} || exit 1;

${LD} build/kernel.o -o build/kernel -T linker.kernel ${LDFLAGS}

cp build/kernel limine.cfg limine/limine.sys limine/limine-cd.bin limine/limine-cd-efi.bin iso

xorriso -as mkisofs -b limine-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table --efi-boot limine-cd-efi.bin -efi-boot-part --efi-boot-image --protective-msdos-label iso -o build/barebones.iso > /dev/null 2>&1

limine/limine-deploy build/barebones.iso > /dev/null 2>&1