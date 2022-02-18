#include <SDL.h>

#ifndef MAP_H
#define MAP_H

#define UNIT_BLOC_GAME 10 //pixels
#define MAP_WIDTH 13
#define MAP_HEIGTH 5

enum { WALL, SKY};

typedef struct case_map{
    char char_case;
    SDL_Rect case_pos;
} case_map;

typedef struct map{
    case_map data_map[MAP_WIDTH][MAP_HEIGTH];
} map;

map initMap(char *path);
SDL_Texture* load_image(char *image_path, SDL_Renderer *screen_renderer);
void printMap(map map_lvl, SDL_Renderer *screen_render);
#endif //MAP_H