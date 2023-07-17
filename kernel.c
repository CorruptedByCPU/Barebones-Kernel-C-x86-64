/*==============================================================================
Copyright (C) Andrzej Adamczyk (at https://blackdev.org/). All rights reserved.
==============================================================================*/

// definitions, that are always nice to have
#include	"stdint.h"
#include	"stddef.h"
#include	"stdbool.h"
#include	"stdarg.h"

// limine definitions
#include	"limine/limine.h"

// limine requests
static volatile struct limine_framebuffer_request limine_framebuffer_request = {
	.id = LIMINE_FRAMEBUFFER_REQUEST,
	.revision = 0
};

// our mighty kernel
void kernel( void ) {
	// linear framebuffer is available (with 32 bits per pixel)?
	if( limine_framebuffer_request.response == NULL || limine_framebuffer_request.response -> framebuffer_count != 1 || limine_framebuffer_request.response -> framebuffers[ 0 ] -> bpp != 32 )
		// no, infinite loop (screen will be black)
		for(;;);

	// set pointer to first pixel of video memory area
	uint32_t *pixel = (uint32_t *) limine_framebuffer_request.response -> framebuffers[ 0 ] -> address;

	// change all pixels color to RED
	for( uint64_t y = 0; y < limine_framebuffer_request.response -> framebuffers[ 0 ] -> height; y++ ) {
		for( uint64_t x = 0; x < limine_framebuffer_request.response -> framebuffers[ 0 ] -> width; x++ )
			pixel[ x ] = 0x00FF0000;

		// next line of pixels on framebuffer
		pixel = (uint32_t *) ((uint64_t) pixel + limine_framebuffer_request.response -> framebuffers[ 0 ] -> pitch);
	}

	// infinite loop
	for(;;);
}
