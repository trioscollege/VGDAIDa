#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h> // int types

// screen pixels
extern Uint32 *g_pbuf;

// screen width and height
extern float   g_width;
extern float   g_height; 

// length of screen scanline in pixels
extern Uint32  g_pitch;

extern float   g_gravity;

#endif
