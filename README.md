# Barebones-Kernel-x86-64

## This repository is for anyone who needs a working base for start. How you continue is up to you.

### The core of the Fern-Night kernel is based on this repository.

What will you need to build and run:

        - git
        of course,

        - clang
        because we don't need a cross-compiler,
        
        - ld or ld.lld
        i'm using LD from Binutils,

        - xorisso
        to create working iso file,

        - qemu
        we should somehow see our kernel in action :)

Compile:

        $ ./make.sh

Run:

        $ ./qemu.sh

Proper execution will show you a Red screen inside Qemu environment :)
