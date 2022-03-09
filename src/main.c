#include <stdio.h>
#include <stdlib.h>
#include "../includes/init.h"
#include "../includes/map.h"
#include "../includes/startGame.h"
#include <errno.h>

int main(int argc, char const *argv[]){
	int game = 1;
	SDL_Window* screen = NULL;
	SDL_Renderer *screen_render = NULL;
	SDL_Event e;

	initAllScreenAndRenderer(&screen, &screen_render);

	while (game){

		while (SDL_PollEvent(&e)){
			switch (e.type){
			case SDL_QUIT:
				game=0;
				break;

			case SDL_KEYDOWN:
				switch (e.key.keysym.sym){
					case  SDLK_RETURN:
					play(&screen_render);
					break;
				}
				break;
			}
		}
		SDL_RenderClear(screen_render);
		SDL_RenderPresent(screen_render);
	}
	destroyAllScreenAndRenderer(&screen, &screen_render);
}
