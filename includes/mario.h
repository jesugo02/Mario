#ifndef __MARIO
#define __MARIO

#include <SDL.h>
#include "../includes/map.h"
#define MARIO_WIDTH 50
#define MARIO_HEIGTH 50
#define PLAYER_SPEED 5
enum {SEE_RIGHT, SEE_LEFT};

typedef struct Mario{
    int state;
    SDL_Texture* player_image;
    SDL_Rect player_position;

    SDL_Rect player_cam;
} Mario;

Mario initPlayer(SDL_Renderer **screen_render);
void printPlayer(Mario mario, SDL_Renderer **screen_render);
void destroyPlayer(Mario mario);

void gravity(Mario *mario, Map *map, SDL_Renderer **render);

#endif