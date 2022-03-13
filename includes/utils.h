#ifndef __UTILS
#define __UTILS

#define NO_COLISION 2001
#include <SDL.h>
#include "map.h"
#include "mario.h"
#include "cam.h"
#include "moveMapAndPlayer.h"
#include <errno.h>
#include <time.h>
#include <SDL2/SDL_image.h>

SDL_Texture* load_image(char *image_path, SDL_Renderer **screen_renderer);
void gravity(Mario *mario, Map *map, CamGame *cam_game);
int getMapWidth(char *path);
int testColision(CamGame cam, Map map, Mario mario, int direction);
#endif