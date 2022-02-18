#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "./mapGame/map.h"

int main(int argc, char const *argv[]){
	int game = 1;
	SDL_Window* screen = NULL;
	SDL_Renderer *screen_render = NULL;
	SDL_Event e;

	if (SDL_Init(SDL_INIT_VIDEO)==-1){
		printf("SDL not initialise : %s", SDL_GetError());
		exit(-1);
	}
	IMG_Init(IMG_INIT_PNG);
	
	screen = SDL_CreateWindow("Super Mario", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 840, 500, SDL_WINDOW_SHOWN);
	if (screen == NULL){
		printf("Screen not initialise : %s", SDL_GetError());
		exit(-1);
	}

	screen_render = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	if (screen_render == NULL){
		printf("Render not initialise : %s", SDL_GetError());
		exit(-1);
	}else{
	}

	// map game_map = initMap("./levelFile/lvl1.txt");
	SDL_Surface *i = NULL;
	i = IMG_Load("t.png");
	if (i==NULL)
	{
		printf("\n%s\n", IMG_GetError());
	}else{
		printf("%p", i);
	}
	
	SDL_Texture *j = SDL_CreateTextureFromSurface(screen_render, i);
	SDL_RenderCopy(screen_render, j, NULL, NULL);
	while (game){
		// printMap(game_map, screen_render);
		while (SDL_PollEvent(&e)!=0){
			switch (e.type){
			case SDL_QUIT:
				game = 0;
				break;
			
			default:
				break;
			}
		}
		// SDL_SetRenderDrawColor(screen_render, 255, 255, 255, 255);
		SDL_RenderClear(screen_render);
		SDL_RenderPresent(screen_render);
	}
	
	SDL_DestroyRenderer(screen_render);
	SDL_DestroyWindow(screen);
	IMG_Quit();
	SDL_Quit();
}
