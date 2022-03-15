#include "../includes/mario.h"
#include "../includes/init.h"
#include "../includes/map.h"
#include "../includes/utils.h"
#include <time.h>

Mario initPlayer(SDL_Renderer **screen_render){
    Mario my_mario;

    my_mario.state = SEE_RIGHT;

    my_mario.player_image = load_image("image/Mario_.png", screen_render);

    if (my_mario.player_image == NULL){
        printf("Player not charge\n");
    }
    

    my_mario.player_position.x = SPAUN_POINT;
    my_mario.player_position.y = 0; // Ajouter une ligne de jeu
    my_mario.player_position.w = MARIO_WIDTH;
    my_mario.player_position.h = MARIO_HEIGTH;

    return my_mario;
}

void printPlayer(Mario mario, SDL_Renderer **screen_render){
    
    SDL_RenderCopy(*screen_render, mario.player_image, NULL, &mario.player_position);
}

void destroyPlayer(Mario mario){
    SDL_DestroyTexture(mario.player_image);
}
