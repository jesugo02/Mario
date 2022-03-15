#ifndef MOVE_MAP_PLAYER
#define MOVE_MAP_PLAYER
#include "map.h"
#include "mario.h"
#include "init.h"
#include "cam.h"
#include "utils.h"

#define SPEED_GAME 4

#define HEIGHT_JUMP MARIO_HEIGTH
enum {LEFT, RIGTH, JUMP, DOWN};

void moveMap(int direction, Map *map_to_move, int colision);
void movePlayer(int direction, Mario *mario, int colision);

void move(int direction, Mario *mario, Map *map, CamGame *cam_game, int colision);
void jump(Mario *mario, Map *map, CamGame* camGame, int *gravity_status);

#endif //MOVE_MAP_PLAYER