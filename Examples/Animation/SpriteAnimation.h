#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <vector>

using namespace std;

#include "Sprite.h"


class SpriteAnimation
{
	vector<Sprite> frames;
	size_t currentFrame;

public:

	SpriteAnimation(size_t length=0)
	{
		if (length > 0)
			frames.reserve(length);
		currentFrame = 0;
	}

	void addFrame(const Sprite& s)
	{
		frames.push_back(s);
	}

	unsigned getLength() const
	{
		return frames.size();
	}

	void update()
	{
		++currentFrame;
		if (currentFrame >= frames.size())
			currentFrame = 0;
	}

	void draw(SDL_Surface *dst, int x, int y)
	{
		if (frames.size() > 0)
			frames[currentFrame].draw(dst, x, y);
	}
};

#endif
