#include <iostream>
using namespace std;

#include "SpriteAnimation.h"


int main(int argc, char **argv)
{
	Image *bg;
	Image *hondaSSheet;
	Image *jewelSSheet;

	try {
		// load background
		bg = new Image("images/bg.png");
		
		// load Honda sprite sheet
		hondaSSheet = new Image("images/Honda.png");

		// load jewel sprite sheet
		jewelSSheet = new Image("images/jewel.png");

	} catch (Exception e) {
		cout << "Exception: " << e.what() << endl;
		return -1;
	}

	// declare animations
	SpriteAnimation honda;
	SpriteAnimation jewel;

	// initialize Honda frames from sprite sheet
	for (int j=0; j<4; j++)
		for (int i=0; i<3; i++)
			honda.addFrame(Sprite(hondaSSheet, 105*i, 90*j, 105, 90));

	// initialize jewel frames from sprite sheet
	for (int i=0; i<15; i++)
		jewel.addFrame(Sprite(jewelSSheet, 52*i, 0, 52, 52));


	//
	// initialize SDL
	//

	int w = bg->getWidth();
	int h = bg->getHeight();

	if (SDL_Init(SDL_INIT_EVERYTHING ) == -1)
		SDL_Quit();

	SDL_Surface *screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if (screen == NULL) 
		SDL_Quit();

	SDL_Event event;
	bool done = false;

	int honda_x = 220;

	//
	// Main loop
	//

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
			}
		}

		// get keyboard status
		SDL_PumpEvents();
		Uint8 *key_state = SDL_GetKeyState(NULL);

		// move honda, if needed
		if (key_state[SDLK_LEFT])
			honda_x -= 10;
		if (key_state[SDLK_RIGHT])
			honda_x += 10;

		// restore background
		bg->draw(screen, 0, 0);

		// draw current animation frames
		jewel.draw(screen, 175, 125);
		honda.draw(screen, honda_x, 110);    

		// advance to next frame
		jewel.update();
		honda.update();

		// show latest frame
		SDL_Flip(screen);

		// control frame rate
		SDL_Delay(80);
	}

	// destroy images used
	delete bg;
	delete hondaSSheet;
	delete jewelSSheet;

	// shut down SDL
	SDL_Quit();

	return 0;
}
