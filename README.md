# Barebones-Kernel-x86-64

#### This repository is for anyone who needs a working base for start. How you continue depends only on you.

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