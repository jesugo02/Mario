#include "map.h"
#include <SDL.h>
#include <SDL_image.h>

map initMap(char *path){
    map map_lvl;
    int i, j;
    char c;
    FILE *lvl_map = fopen(path, "r");

    for (i = 0; i < MAP_HEIGTH; i++){
        for (j = 0; j < MAP_WIDTH; j++){
            c = fgetc(lvl_map);
            map_lvl.data_map[i][j].case_pos.x = 10 *j;
            map_lvl.data_map[i][j].case_pos.y = 10 *i;

            switch (c){
            case 'W':
                map_lvl.data_map[i][j].char_case = WALL;
                break;

            case 'S':
                map_lvl.data_map[i][j].char_case = SKY;
                break;
            }
        }
    }
}

SDL_Texture* load_image(char *image_path, SDL_Renderer *screen_renderer){
    int test = IMG_Init(IMG_INIT_PNG);
    if (test != IMG_INIT_PNG)
    {
        printf("Erreur");
    }

    SDL_Surface *image_surface = NULL;
    SDL_Texture *image_texture = NULL;

    image_surface = IMG_Load(image_path);
    if (image_surface == NULL){
        printf("\nImage not charge : %s\n", IMG_GetError());
        exit(-1);
        return NULL;
    }else{
        image_texture = SDL_CreateTextureFromSurface(screen_renderer, image_surface);
        SDL_FreeSurface(image_surface);
        if (image_texture==NULL){
            printf("\nTexture not charge : %s\n", SDL_GetError());
            return NULL;
        }else
            return image_texture;
    }
    IMG_Quit();
}

void printMap(map map_lvl, SDL_Renderer *screen_render){
    
    int i, j;
    SDL_Texture *wall = load_image("t.png", screen_render);
    SDL_Texture *sky = load_image("t.png", screen_render);

    for (i = 0; i < MAP_HEIGTH; i++){
        for (j = 0; j < MAP_WIDTH; j++){
            switch (map_lvl.data_map[i][j].char_case)
            {
            case WALL:
                SDL_RenderCopy(screen_render, wall, &map_lvl.data_map[i][j].case_pos, NULL);
                break;

            case SKY:
                SDL_RenderCopy(screen_render, sky, &map_lvl.data_map[i][j].case_pos, NULL);
                break;
            
            default:
                break;
            }
        }
        
    }
    
}
