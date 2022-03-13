#include "../includes/map.h"
#include "../includes/utils.h"
#include "../includes/init.h"
#include <errno.h>
#include <string.h>


Map initMap(char *path, SDL_Renderer **screen_renderer){
    int i, j;
    char c;
    Map map_lvl;
    FILE *lvl_map = NULL;

    strcpy(map_lvl.path, path);

    lvl_map = fopen(map_lvl.path, "r");

    map_lvl.file_map=lvl_map;

    if (lvl_map==NULL)
        printf("Error File open : %s", SDL_GetError());
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

void destroyMap(Map map_to_destroy){
    int i;
    fclose(map_to_destroy.file_map);

    SDL_DestroyTexture(map_to_destroy.sky);
    SDL_DestroyTexture(map_to_destroy.wall);

    for (i = 0; i < MAP_BLOC_HEIGTH; i++)
        free(map_to_destroy.data_map[i]);

    free(map_to_destroy.data_map);
}


void printMap(Map map_lvl, Mario mario, SDL_Renderer **screen_render, CamGame cam){

    int i, j, map_width, j_init, j_end;
    SDL_Texture *wall = map_lvl.wall;
    SDL_Texture *sky = map_lvl.sky;

    map_width = map_lvl.map_width;

    j_init = (cam.cam.x - mario.player_position.x) / UNIT_BLOC_GAME;
    j_end = (cam.cam.x + (SCREEN_WIDTH - mario.player_position.x) + UNIT_BLOC_GAME) / UNIT_BLOC_GAME;


    for (i = 0; i < MAP_BLOC_HEIGTH; i++){
        for (j = j_init; j < j_end; j++){
            if(map_lvl.data_map[i][j].case_pos.x >= 0 - UNIT_BLOC_GAME && map_lvl.data_map[i][j].case_pos.x <= SCREEN_WIDTH)
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