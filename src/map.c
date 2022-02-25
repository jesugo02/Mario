#include "../includes/map.h"
#include <errno.h>
#include <string.h>

int getMapWidth(char *path){
    FILE* file_lvl = NULL;

    file_lvl = fopen(path, "r");

    if (file_lvl==NULL){
        printf("File not open %d", errno);
        exit(-1);
    }
    
    int i=0;
    while (fgetc(file_lvl)!='\n')
        i++;

    return i;    
}

Map initMap(char *path, SDL_Renderer **screen_renderer){
    int i, j;
    char c;
    Map map_lvl;

    strcpy(map_lvl.path, path);

    FILE *lvl_map = NULL;
    lvl_map = fopen(map_lvl.path, "r");

    if (lvl_map==NULL){
        printf("Error File open : %s", SDL_GetError());
    }
    
    map_lvl.map_width = getMapWidth(map_lvl.path);

    map_lvl.data_map = calloc(MAP_BLOC_HEIGTH, sizeof(Case_map**));
    for (i = 0; i < MAP_BLOC_HEIGTH; i++)
        map_lvl.data_map[i] = calloc(map_lvl.map_width, sizeof(Case_map));

    for (i = 0; i < MAP_BLOC_HEIGTH; i++){
        for (j = 0; j < map_lvl.map_width; j++){
            c = fgetc(lvl_map);

            if (c=='\n')
                c = fgetc(lvl_map);
            
            map_lvl.data_map[i][j].case_pos.x = UNIT_BLOC_GAME *j;
            map_lvl.data_map[i][j].case_pos.y = UNIT_BLOC_GAME *i;
            map_lvl.data_map[i][j].case_pos.w = UNIT_BLOC_GAME;
            map_lvl.data_map[i][j].case_pos.h = UNIT_BLOC_GAME;

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

    map_lvl.sky = load_image("image/sky.png", screen_renderer);
    map_lvl.wall = load_image("image/wall.png", screen_renderer);

    return map_lvl;
}

SDL_Texture* load_image(char *image_path, SDL_Renderer **screen_renderer){

    SDL_Surface *image_surface = NULL;
    SDL_Texture *image_texture = NULL;

    image_surface = IMG_Load(image_path);
    if (image_surface == NULL){
        printf("\nImage not charge : %s\n", IMG_GetError());
        exit(-1);
        return NULL;
    }else{
        image_texture = SDL_CreateTextureFromSurface(*screen_renderer, image_surface);
        SDL_FreeSurface(image_surface);
        if (image_texture==NULL){
            printf("\nTexture not charge : %s\n", SDL_GetError());
            return NULL;
        }else
            return image_texture;
    }
}

void printMap(Map map_lvl, SDL_Renderer **screen_render){

    int i, j, map_width;
    SDL_Texture *wall = map_lvl.wall;
    SDL_Texture *sky = map_lvl.sky;

    map_width = map_lvl.map_width;

    for (i = 0; i < MAP_BLOC_HEIGTH; i++){
        for (j = 0; j < map_width; j++){
            switch (map_lvl.data_map[i][j].char_case){
                case WALL:
                    if (SDL_RenderCopy(*screen_render, wall, NULL, &(map_lvl.data_map[i][j].case_pos)) == -1){
                        printf("\n Error Rendering : %s\n", SDL_GetError());
                    }
                    break;

                case SKY:
                    if (SDL_RenderCopy(*screen_render, sky, NULL, &(map_lvl.data_map[i][j].case_pos)) == -1){
                        printf("\nError Rendering : %s\n", SDL_GetError());
                    }
                    break;
            }
        }
    }

}