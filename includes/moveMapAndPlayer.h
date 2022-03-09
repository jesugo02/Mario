#ifndef MOVE_MAP_PLAYER
#define MOVE_MAP_PLAYER
#include "map.h"

enum {LEFT, RIGTH, JUMP, DOWN};

void moveMap(int direction, Map *map_to_move);

#endif //MOVE_MAP_PLAYER