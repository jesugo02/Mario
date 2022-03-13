#include "../includes/moveMapAndPlayer.h"

void moveMap(int direction, Map *map_to_move, int colision){
    int i, j, width_map = map_to_move->map_width;

        switch (direction){
        case LEFT:
            for (i = 0; i < MAP_BLOC_HEIGTH; i++)
                for (j = 0; j < width_map; j++)
                    map_to_move->data_map[i][j].case_pos.x+=colision == NO_COLISION ? PLAYER_SPEED : colision;
            break;

        case RIGTH:
            for (i = 0; i < MAP_BLOC_HEIGTH; i++)
                for (j = 0; j < width_map; j++)
                    map_to_move->data_map[i][j].case_pos.x-=colision == NO_COLISION ? PLAYER_SPEED : colision;
            break;

        }
            
}

void movePlayer(int direction, Mario *mario, int colision){
    switch (direction){
        case LEFT:
            mario->player_position.x-= colision == NO_COLISION ? PLAYER_SPEED : colision;
            break;

        case RIGTH:
            mario->player_position.x+= colision == NO_COLISION ? PLAYER_SPEED : colision;
            break;

    }
}

void move(int direction, Mario *mario, Map *map, CamGame *cam_game, int colision){
    int  widthMap = map->map_width, i, j;
    switch (direction)
    {
    case RIGTH:
        // if (!(mario->player_position.x + PLAYER_SPEED > SCREEN_WIDTH - MARIO_WIDTH)){

            cam_game->cam.x+= colision == NO_COLISION ? PLAYER_SPEED : colision;

            if (mario->player_position.x <= SCREEN_WIDTH * 2/3 || map->data_map[0][widthMap-1].case_pos.x-PLAYER_SPEED < SCREEN_WIDTH-UNIT_BLOC_GAME)
                movePlayer(RIGTH, mario, colision);
            else if( !(map->data_map[0][widthMap-1].case_pos.x-PLAYER_SPEED < SCREEN_WIDTH-UNIT_BLOC_GAME))
                moveMap(RIGTH, map, colision);
        // }       
        
        break;

    case LEFT:
        // if (!(mario->player_position.x - PLAYER_SPEED < 0)){

            cam_game->cam.x-= colision == NO_COLISION ? PLAYER_SPEED : colision;

            if (mario->player_position.x >= SCREEN_WIDTH * 1/3 || map->data_map[0]->case_pos.x+PLAYER_SPEED > 0)
                movePlayer(LEFT, mario, colision);
            else if( !( map->data_map[0]->case_pos.x+PLAYER_SPEED > 0))
                moveMap(LEFT, map, colision);

        // }
    
    }
}

void jump(Mario *mario, Map *map, CamGame* camGame, int *gravity_status){
    static int jump_heigth=0;

    if (jump_heigth!=HEIGHT_JUMP){
        mario->player_position.y--;
        camGame->cam.y--;

        jump_heigth++;
    }else{
        jump_heigth = 0;
        *gravity_status = 1;    
    }
}