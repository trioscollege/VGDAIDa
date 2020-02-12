#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>

#include "Exception.h"

class Image 
{
	SDL_Surface *image;

public:
	Image(const string& filename); //loads the image from file

	~Image(); //frees the image

	// draw entire image
	void draw(SDL_Surface *dst, int x, int y);

	// draw a portion of the image
	void draw(SDL_Surface *dst, int x, int y, SDL_Rect *src_rect);

	unsigned getWidth() const;
	unsigned getHeight() const;
};

#endif //IMAGE_H
