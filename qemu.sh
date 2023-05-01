#!/bin/bash
#===============================================================================
# Copyright (C) Andrzej Adamczyk (at https://blackdev.org/). All rights reserved.
#===============================================================================

qemu-system-x86_64			\
	--enable-kvm			\
	-m 64				\
	-cdrom build/barebones.iso	\
	-rtc base=localtime 		\
	-serial mon:stdio
