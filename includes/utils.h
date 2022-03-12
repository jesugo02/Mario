#ifndef __UTILS
#define __UTILS
#include <SDL.h>
#include "map.h"
#include "mario.h"
#include "cam.h"
#include <time.h>
#include <SDL2/SDL_image.h>

SDL_Texture* load_image(char *image_path, SDL_Renderer **screen_renderer);
void gravity(Mario *mario, Map *map, CamGame *cam_game);

#endif