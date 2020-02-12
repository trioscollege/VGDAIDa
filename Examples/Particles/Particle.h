#ifndef PARTICLE_H
#define PARTICLE_H

#include "Globals.h"


struct Particle
{
	float x, y;
	float vx, vy;
	Uint32 color;
	bool alive;

	Particle(float x, float y, float vx, float vy, Uint32 color)
	: x(x), y(y), vx(vx), vy(vy), color(color), alive(true)
	{
	}

	void putRGB32()
	{
		*(g_pbuf + g_pitch*(Uint32)y + (Uint32)x) = color;
	}

	void updateAndDraw()
	{
		if (y >= g_height || x >=g_width || x < 0) {
			// clippage
			alive = false;
			return;
		} else if (y < 0) {
			// don't clip yet (might come back down);
			// update but don't draw
		} else {
			putRGB32();
		}

		vy += g_gravity;
		x += vx;
		y += vy;
	}
};


#include <list>
using namespace std;

struct ParticleSystem
{
	list<Particle*> plist;

	void generate(float cx, float cy, int n, Uint32 color);

	void updateAndDraw();
};


#endif
