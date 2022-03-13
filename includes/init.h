#ifndef INIT_H
#define INIT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "map.h"

#define GAME_NAME "Mario Sokoban"
#define SCREEN_WIDTH 840
#define SCREEN_HEIGTH MAP_BLOC_HEIGTH*UNIT_BLOC_GAME
#define SPAUN_POINT 0 /*SCREEN_WIDTH/3*/

void initAllScreenAndRenderer(SDL_Window **window, SDL_Renderer **window_renderer);
void destroyAllScreenAndRenderer(SDL_Window **window, SDL_Renderer **window_renderer);

#endif //INIT_H