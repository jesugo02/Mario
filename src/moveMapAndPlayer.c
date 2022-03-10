#include "../includes/moveMapAndPlayer.h"
#include "../includes/init.h"
#include "../includes/mario.h"
void moveMap(int direction, Map *map_to_move){
    int i, j, jumpCount, widthMap = map_to_move->map_width;

    for (i = 0; i < MAP_BLOC_HEIGTH; i++){
    
        switch (direction){
        case LEFT:
            if(!(map_to_move->data_map[i]->case_pos.x+SPEED_GAME>0))
                for (j = 0; j < widthMap; j++)
                    map_to_move->data_map[i][j].case_pos.x+=SPEED_GAME;
            break;

        case RIGTH:
            if(!(map_to_move->data_map[i][widthMap-1].case_pos.x-SPEED_GAME < SCREEN_WIDTH-UNIT_BLOC_GAME))
                for (j = 0; j < widthMap; j++)
                    map_to_move->data_map[i][j].case_pos.x-=SPEED_GAME;
            break;

        }
        
    }

    // for (i = 0; i < MAP_BLOC_HEIGTH; i++){
    //     for (j = 0; j < map_to_move->map_width; j++)
    //         printf("| %d %d |", map_to_move->data_map[i][j].case_pos.x, map_to_move->data_map[i][j].case_pos.y);

    //     printf("\n\n");
    // }
    
}

void movePlayer(int direction, Mario *mario){
    switch (direction){
        case LEFT:
            mario->player_position.x-= PLAYER_SPEED;
            break;

        case RIGTH:
            mario->player_position.x+= PLAYER_SPEED;
            break;

    }
}