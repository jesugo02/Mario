#include "../includes/mario.h"
#include "../includes/init.h"
#include "../includes/map.h"
#include "../includes/utils.h"
#include <time.h>

Mario initPlayer(SDL_Renderer **screen_render){
    Mario my_mario;

    my_mario.state = SEE_RIGHT;

    my_mario.player_image = load_image("image/Mario.png", screen_render);

    if (my_mario.player_image == NULL){
        printf("Player not charge\n");
    }
    

    my_mario.player_position.x = my_mario.player_cam.x = SCREEN_WIDTH/3;
    my_mario.player_position.y = 0; // Ajouter une ligne de jeu
    my_mario.player_cam.y = my_mario.player_position.y + MARIO_HEIGTH ;
    my_mario.player_position.w = MARIO_WIDTH;
    my_mario.player_position.h = MARIO_HEIGTH;

    return my_mario;
}

void printPlayer(Mario mario, SDL_Renderer **screen_render){

    // printf("%d\n", mario.player_cam.x/UNIT_BLOC_GAME);
    
    SDL_RenderCopy(*screen_render, mario.player_image, NULL, &mario.player_position);
}

void destroyPlayer(Mario mario){
    SDL_DestroyTexture(mario.player_image);
}

void gravity(Mario *mario, Map *map, SDL_Renderer **render){
    int i, j;

    i = mario->player_cam.x / UNIT_BLOC_GAME;
    j = mario->player_cam.y / UNIT_BLOC_GAME;

    while (map->data_map[j][i].char_case != WALL){

        mario->player_cam.y++;
        mario->player_position.y++;
        
        i = mario->player_cam.x / UNIT_BLOC_GAME;
        j = mario->player_cam.y / UNIT_BLOC_GAME;

        SDL_RenderClear(*render);
        printPlayer(*mario, render);
        printMap(*map, render);
        SDL_RenderPresent(*render);

        // SDL_Delay(10);
    }
}