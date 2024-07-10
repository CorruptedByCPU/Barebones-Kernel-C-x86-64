/*==============================================================================
Copyright (C) Andrzej Adamczyk (at https://blackdev.org/). All rights reserved.
==============================================================================*/

	//----------------------------------------------------------------------
	// variables, structures, definitions of kernel
	//----------------------------------------------------------------------
	#include	"config.h"
	//----------------------------------------------------------------------
	// variables
	//----------------------------------------------------------------------
	#include	"data.c"

// our mighty kernel
void _entry( void ) {
	// linear framebuffer is available (and 32 bits color per pixel available)?
	if( limine_framebuffer_request.response == NULL || limine_framebuffer_request.response -> framebuffer_count != 1 || limine_framebuffer_request.response -> framebuffers[ 0 ] -> bpp != 32 )
		// no, infinite loop (screen will stay black)
		while( TRUE );

	// set pointer to first pixel of video memory area
	uint32_t *pixel = (uint32_t *) limine_framebuffer_request.response -> framebuffers[ 0 ] -> address;

	// draw green sign mark
	uint64_t offset_x = 0;
	for( uint64_t y = (limine_framebuffer_request.response -> framebuffers[ 0 ] -> height >> STD_SHIFT_2) - 16; y < (limine_framebuffer_request.response -> framebuffers[ 0 ] -> height >> STD_SHIFT_2) + 16; y++ ) { for( uint64_t x = (limine_framebuffer_request.response -> framebuffers[ 0 ] -> width >> STD_SHIFT_2) - 16; x < (limine_framebuffer_request.response -> framebuffers[ 0 ] -> width >> STD_SHIFT_2) + 16; x++ ) { pixel[ (y * limine_framebuffer_request.response -> framebuffers[ 0 ] -> width) + x + offset_x ] = 0x0000FF00; } offset_x++; }
	for( uint64_t y = (limine_framebuffer_request.response -> framebuffers[ 0 ] -> height >> STD_SHIFT_2) + 16; y > (limine_framebuffer_request.response -> framebuffers[ 0 ] -> height >> STD_SHIFT_2) - 64; y-- ) { for( uint64_t x = (limine_framebuffer_request.response -> framebuffers[ 0 ] -> width >> STD_SHIFT_2) - 16; x < (limine_framebuffer_request.response -> framebuffers[ 0 ] -> width >> STD_SHIFT_2) + 16; x++ ) { pixel[ (y * limine_framebuffer_request.response -> framebuffers[ 0 ] -> width) + x + offset_x ] = 0x0000FF00; } offset_x += (y % 2); }

	// infinite loop
	while( TRUE );
}
