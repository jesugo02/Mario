#include "../includes/init.h"
#include <errno.h>

void initAllScreenAndRenderer(SDL_Window **window, SDL_Renderer **window_renderer){
    
    if (SDL_Init(SDL_INIT_VIDEO) == -1 || IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
        printf("\nError of initialisation : %s\n", SDL_GetError());
        exit(-1);
    }

    *window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN);
    if (*window==NULL){
        printf("\nError of initialisation window : %s\n", SDL_GetError());
        exit(-1);
    }

    *window_renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*window_renderer==NULL){
        printf("\nError of initialisation renderer : %s\n", SDL_GetError());
        exit(-1);
    }

}

void destroyAllScreenAndRenderer(SDL_Window **window, SDL_Renderer **window_renderer){
    SDL_DestroyRenderer(*window_renderer);
    SDL_DestroyWindow(*window);
    IMG_Quit();
    SDL_Quit();
}