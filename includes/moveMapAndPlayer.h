#ifndef MOVE_MAP_PLAYER
#define MOVE_MAP_PLAYER
#include "map.h"
#include "mario.h"
#include "init.h"
#include "cam.h"

#define SPEED_GAME 4

#define HEIGHT_JUMP MARIO_HEIGTH*2
enum {LEFT, RIGTH, JUMP, DOWN};

void moveMap(int direction, Map *map_to_move);
void movePlayer(int direction, Mario *mario);

void move(int direction, Mario *mario, Map *map, CamGame *cam_game);
void jump(Mario *mario, Map *map, CamGame* camGame, int *gravity_status);

#endif //MOVE_MAP_PLAYER