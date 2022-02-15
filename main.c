#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	SDL_Renderer *renderer;
	SDL_Window *ecran = NULL;
	if(SDL_Init(SDL_INIT_VIDEO) == -1){
		printf("\nNE_PEUT_PAS_INITIALISER %s \n",SDL_GetError());
		exit(-1);
	}
	if(SDL_CreateWindowAndRenderer(680,420 , SDL_WINDOW_UTILITY | SDL_WINDOW_VULKAN | SDL_WINDOW_VULKAN, &ecran , &renderer) == -1){
		printf("CAN'T CREATE THE SCREEN %s",SDL_GetError());
		exit(-1);
	}
	SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 225);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
//	while(1);
	SDL_Quit();
    return 0;
}
