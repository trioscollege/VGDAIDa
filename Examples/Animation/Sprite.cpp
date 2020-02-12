#include "Sprite.h"


Sprite::Sprite(Image *image, int x, int y, int w, int h)
{
	this->image = image;
	src_rect.x = x;
	src_rect.y = y;
	src_rect.w = w;
	src_rect.h = h;
}


Sprite::~Sprite()
{
}


void Sprite::draw(SDL_Surface *screen, int x, int y)
{
	image->draw(screen, x, y, &src_rect);
}

unsigned Sprite::getWidth() const
{
	return src_rect.w;
}

unsigned Sprite::getHeight() const
{
	return src_rect.h;
}
