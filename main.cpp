#include "SDL.h"
#include "Logger.h"

using namespace std;

int main(int argc, char* argv[])
{
	// declarations
	Logger log;   // create a Logger instance	
	SDL_Window *window;  // Declare window pointer
	SDL_Renderer *renderer;  // Declare renderer

	// START PROGRAM
	log.write("Program Started.");
	// Initialize SDL's Video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		log.write("Failed to init SDL");
		return false;
	}
	log.write("SDL initialization was successful.");

	// Create our window centered at 1024x768 resolution
	window = SDL_CreateWindow(
	"SDL Template",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	1024,
	768,
	SDL_WINDOW_SHOWN);	
	log.write("SDL window was created.");

	// make renderer
	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

	// MAIN LOOP
	bool loop = true;
	log.write("Entering main loop.");
	while (loop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				loop = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					loop = false;
					break;
				case SDLK_a:

					break;				
				default:
					break;
				}
			}
		}
		SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		for (int x=0;x<1024;x++)
		{
			SDL_RenderDrawPoint(renderer, x, 384);
		}		
		SDL_RenderPresent(renderer);
	}
	log.write("Exited main loop.");
	// END PROGRAM
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	log.write("Program Ended.");
	return 0;
}