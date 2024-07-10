# Barebones-Kernel-x86-64

## This repository is for anyone who needs a working base for start. How you continue is up to you.

### The core of the Foton/Fern-Night kernel is based on this repository.

What will you need to build and run:

        - git
        of course,

        - clang
        because we don't need a cross-compiler,
        
        - ld.lld
        linker from LLVM,

        - xorisso
        to create working iso file,

        - qemu
        we should somehow see our kernel in action :)

Compile:

        $ ./make

Run:

        $ ./qemu

Proper execution will show you a green sign mark at center of screen :)

<p align="center">
  <img src="https://blackdev.org/shot/barebones.png" />
</p>
