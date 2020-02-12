#include <cstdlib>
#include <cmath>
using namespace std;

#include "Particle.h"

#define PI 3.141592653589793238462643383


void ParticleSystem::generate(float cx, float cy, int n, Uint32 color)
{
	for (int i=0; i<n; ++i) {

		double angle = 2*PI*rand()/(double)RAND_MAX;
		double speed = 0 + 10*rand()/(double)RAND_MAX;

		float vx = (float)(speed * cos(angle));
		float vy = (float)(speed * sin(angle));

		plist.push_back(new Particle(cx, cy, vx, vy, color));
	}
}


void ParticleSystem::updateAndDraw()
{
	list<Particle*>::iterator it = plist.begin();

	while (it != plist.end()) {

		// dereference iterator to get particle pointer
		Particle* p = *it;

		if (!p->alive) {
			// erase particle
			it = plist.erase(it);
			delete p;
		} else {
			// update and draw particle
			p->updateAndDraw();
			++it;  // next, please
		}
	}
}
