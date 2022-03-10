#ifndef MOVE_MAP_PLAYER
#define MOVE_MAP_PLAYER
#include "map.h"
#include "mario.h"

#define SPEED_GAME 4
enum {LEFT, RIGTH, JUMP, DOWN};

void moveMap(int direction, Map *map_to_move);
void movePlayer(int direction, Mario *mario);

#endif //MOVE_MAP_PLAYER