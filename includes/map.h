#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define UNIT_BLOC_GAME 30//pixels
#define MAP_BLOC_HEIGTH 10 // Nombre de bloc en hauteur
#define MAX_NAME_FILE_LVL 256


enum { WALL, SKY};

typedef struct Case_map{
    char char_case;
    SDL_Rect case_pos;
} Case_map;

typedef struct Map{
    Case_map **data_map;
    char path[MAX_NAME_FILE_LVL];
    SDL_Texture *wall;
    SDL_Texture *sky;
    int map_width;
} Map;

int getMapWidth(char *path);
Map initMap(char *path, SDL_Renderer **screen_renderer);
SDL_Texture* load_image(char *image_path, SDL_Renderer **screen_renderer);
void printMap(Map map_lvl, SDL_Renderer **screen_render);
#endif //MAP_H