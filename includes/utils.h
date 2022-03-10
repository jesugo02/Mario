#ifndef __UTILS
#define __UTILS
#include <SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* load_image(char *image_path, SDL_Renderer **screen_renderer);

#endif