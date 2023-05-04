#include <iostream>
#include "ant.h"
#include "environment.h"
#include <SDL.h>
#include <vector>
#include <ctime>
const int env_size_x = 50;
const int env_size_y = 50;
const int ant_qtd =100;
const int home_x = 25;
const int home_y = 25;



std::vector<ant> ant_arr;

int decay_meter = 0;
environment env = environment(env_size_x, env_size_y);

void execute(std::vector<ant> *a) {
	for (int i = 0; i < a->size(); i++) {
		a->at(i).action();
	}
}

void render(SDL_Surface* s, std::vector<ant> ants, environment * env) {

	int env_h = env->getH();
	int env_w = env->getW();
	double pixel_h = s->h/env_h;
	double pixel_w = s->w/env_w;

	SDL_FillRect(s, NULL, SDL_MapRGBA(s->format, 0xff, 0xff, 0xff, 0xff));

	for (int i = 0; i < env_h; i++) {
		for (int j = 0; j < env_w; j++) {

			SDL_Rect * pixel = new SDL_Rect();
			pixel->h = pixel_h;
			pixel->w = pixel_w;
			pixel->x = j * pixel_h;
			pixel->y = i * pixel_w;
			if (env->getCells(i,j)->getHome()) {
				SDL_FillRect(s, pixel , SDL_MapRGBA(s->format, 0xeb, 0x34, 0x34, 0xff));
			}
			else if (env->getCells(i, j)->getFood() > 0) {
				SDL_FillRect(s, pixel, SDL_MapRGBA(s->format, 0xeb, 0x34, 0xde, 0xff));
				
			}
			else if (env->getCells(i, j)->getFerA() > 0) {
				SDL_FillRect(s, pixel, SDL_MapRGBA(s->format, 0x34, 0xeb, 0x5e, 0xff));
			}
			else if (env->getCells(i, j)->getFerB() > 0) {
				SDL_FillRect(s, pixel, SDL_MapRGBA(s->format, 0x34, 0x64, 0xeb, 0xff));
			}
		}
	}
	for (int i = 0; i < ants.size(); i++) {
		SDL_Rect* pixel = new SDL_Rect();
		pixel->h = pixel_h;
		pixel->w = pixel_w;
		pixel->x = ants[i].getY() * pixel_h;
		pixel->y = ants[i].getX() * pixel_w;
		//std::cout << ants[i].getX();
		SDL_FillRect(s, pixel, SDL_MapRGBA(s->format, 0x00, 0x00, 0x00, 0xff));
	}
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 480, SDL_WINDOW_SHOWN);

	if (!window)
	{
		std::cerr << "Error failed to create window!\n";
		return 1;
	}

	 SDL_Surface * screenSurface = SDL_GetWindowSurface(window);
	 
	 SDL_Event event;
	 bool quit = false;

	 //initialize ant array and environment;
	 ant_arr.resize(ant_qtd);
	 for (int i = 0; i < ant_qtd; i++) {
		 ant_arr[i] = ant(home_x, home_y , &env);
	 }
	 env.setHome(home_x, home_y);
	 env.createFood(15, 15);
	 

	 //start code here

	 while (!quit) {
		 while (SDL_PollEvent(&event) != 0) {
			 if (event.type == SDL_QUIT) {
				 quit = true;
			 }
		 }
		 execute(&ant_arr);
		 render(screenSurface, ant_arr, &env);
		 SDL_UpdateWindowSurface(window);
		 decay_meter++;
		 if (decay_meter % 3 == 0) {
			 decay_meter = 0;
			 env.decay(1);
		 }

	 }

	 SDL_Quit();


	return 0;
}