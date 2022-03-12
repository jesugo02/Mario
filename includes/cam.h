#ifndef __CAM_H
#define __CAM_H

#include <SDL.h>

#include "mario.h"

typedef struct  CamGame{
    SDL_Rect cam;
}CamGame;

CamGame initCam(Mario mario);

#endif