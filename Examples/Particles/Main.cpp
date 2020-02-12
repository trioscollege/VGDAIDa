#include <cstdlib>
#include <ctime>

using namespace std;

#include "Particle.h"
#include "Globals.h"


int main(int argc, char **argv)
{
	int w = 640;
	int h = 480;

	if (SDL_Init(SDL_INIT_EVERYTHING ) == -1)
		SDL_Quit();

	SDL_Surface *screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if (screen == NULL)
		SDL_Quit();


	srand((unsigned)time(NULL));

	// initialize globals
	g_pbuf = (Uint32*)screen->pixels;
	g_pitch = screen->pitch / 4;
	g_width = (float)w;
	g_height = (float)h;
	g_gravity = 1;

	ParticleSystem particles;

	SDL_Event event;
	bool done = false;
	bool slow = false;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				done = true;
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_ESCAPE)
					done = true;
				if (event.key.keysym.sym == SDLK_s)
					slow = !slow;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					// generate particles at clicked point
					particles.generate((float)event.button.x, (float)event.button.y, 500, 0xffffff);
				}
			}
		}

		// clear screen to black
		SDL_FillRect(screen, NULL, 0);

		// move and draw particles
		particles.updateAndDraw();

		// show them
		SDL_Flip(screen);

		// control frame rate
		if (!slow)
			SDL_Delay(20);
		else
			SDL_Delay(500);
	}

	// shut down SDL
	SDL_Quit();

	return 0;
}
