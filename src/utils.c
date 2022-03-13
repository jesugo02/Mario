#include "../includes/utils.h"

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

void gravity(Mario *mario, Map *map, CamGame *cam_game){
    int i, j;

    i = cam_game->cam.x / UNIT_BLOC_GAME;
    j = cam_game->cam.y / UNIT_BLOC_GAME;

    if (map->data_map[j][i].char_case != WALL){

        cam_game->cam.y++;
        mario->player_position.y++;
        
        i = cam_game->cam.x / UNIT_BLOC_GAME;
        j = cam_game->cam.y / UNIT_BLOC_GAME;

    }
}

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

int testColision(CamGame cam, Map map, Mario mario, int direction){
    int i_bloc, j_first_bloc, i_second_bloc, j_second_bloc;

    switch (direction){

        case RIGTH:
        i_bloc =( cam.cam.x + MARIO_WIDTH + PLAYER_SPEED ) / UNIT_BLOC_GAME;
        j_first_bloc = (cam.cam.y - 1) / UNIT_BLOC_GAME ;

        j_second_bloc = ( cam.cam.y - UNIT_BLOC_GAME - 1) / UNIT_BLOC_GAME;

        if (map.data_map[j_first_bloc][i_bloc].char_case == WALL){
            return map.data_map[j_first_bloc][i_bloc].case_pos.x - (mario.player_position.x + MARIO_WIDTH);
        }else if( map.data_map[j_second_bloc][i_bloc].char_case == WALL){
            return map.data_map[j_second_bloc][i_bloc].case_pos.x - (mario.player_position.x + MARIO_WIDTH);
        } else if(mario.player_position.x + PLAYER_SPEED > SCREEN_WIDTH - MARIO_WIDTH){
            return SCREEN_WIDTH - (mario.player_position.x + MARIO_WIDTH);
        }else
            return NO_COLISION;
        
        case LEFT:
        i_bloc =( cam.cam.x - PLAYER_SPEED ) / UNIT_BLOC_GAME;
        j_first_bloc = (cam.cam.y - 1) / UNIT_BLOC_GAME ;

        j_second_bloc = ( cam.cam.y - UNIT_BLOC_GAME - 1 ) / UNIT_BLOC_GAME;

        if (map.data_map[j_first_bloc][i_bloc].char_case == WALL){
            return mario.player_position.x - (map.data_map[j_first_bloc][i_bloc].case_pos.x + UNIT_BLOC_GAME);
        }else if(map.data_map[j_second_bloc][i_bloc].char_case == WALL){
            return mario.player_position.x - (map.data_map[j_second_bloc][i_bloc].case_pos.x + UNIT_BLOC_GAME);
        } else if(cam.cam.x - PLAYER_SPEED < 0){
            return mario.player_position.x;
        }else
            return NO_COLISION;
        break;
    
    }
}