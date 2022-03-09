#include "../includes/moveMapAndPlayer.h"

void moveMap(int direction, Map *map_to_move){
    int i, j, jumpCount;

    for (i = 0; i < MAP_BLOC_HEIGTH; i++){
        for (j = 0; j < map_to_move->map_width; j++){
            switch (direction)
            {
            case LEFT:
                map_to_move->data_map[i][j].case_pos.x+=8;
                break;

            case RIGTH:
                map_to_move->data_map[i][j].case_pos.x-=8;
                break;

            case JUMP:
                break;
            }
        }
        
    }
    
}