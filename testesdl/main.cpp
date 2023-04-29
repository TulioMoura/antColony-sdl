#include <iostream>

#include <SDL.h>


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	if (!window)
	{
		std::cerr << "Error failed to create window!\n";
		return 1;
	}

	 SDL_Surface * screenSurface = SDL_GetWindowSurface(window);
	 
	 SDL_Event event;
	 bool quit = false;

	 //start code here

	 while (!quit) {
		 while (SDL_PollEvent(&event) != 0) {
			 if (event.type == SDL_QUIT) {
				 quit = true;
			 }
		 }

		 SDL_UpdateWindowSurface(window);
	 }

	 SDL_Quit();


	return 0;
}