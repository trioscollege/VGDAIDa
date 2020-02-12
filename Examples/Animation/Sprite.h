#ifndef SPRITE_H
#define SPRITE_H

#include "Image.h"


class Sprite 
{
	Image *image;		// source image
	SDL_Rect src_rect;	// where in source image

public:
	Sprite(Image *image, int x, int y, int w, int h);

	~Sprite();

	void draw(SDL_Surface *dst, int x, int y);

	unsigned getWidth() const;
	unsigned getHeight() const;
};

#endif
