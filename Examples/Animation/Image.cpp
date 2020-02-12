#include <SDL_Image.h>

#include "Image.h"


Image::Image(const string &filename)
{
	image = IMG_Load(filename.c_str());
	if (image == NULL) 
		throw Exception("Failed to load: " + filename);
}


Image::~Image()
{
	SDL_FreeSurface(image);
}

void Image::draw(SDL_Surface *dst, int x, int y)
{
	SDL_Rect dst_rect;
	dst_rect.x = x;
	dst_rect.y = y;
	SDL_BlitSurface(image, NULL, dst, &dst_rect);
}


void Image::draw(SDL_Surface *dst, int x, int y, SDL_Rect *src_rect)
{
	SDL_Rect dst_rect;
	dst_rect.x = x;
	dst_rect.y = y;
	SDL_BlitSurface(image, src_rect, dst, &dst_rect);
}


unsigned Image::getWidth() const
{
	return image->w;
}

unsigned Image::getHeight() const
{
	return image->h;
}
