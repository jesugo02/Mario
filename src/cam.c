#include "../includes/cam.h"
#include "../includes/init.h"

CamGame initCam(Mario mario){
    CamGame mycam;

    mycam.cam.x = SPAUN_POINT;
    mycam.cam.y = mario.player_position.y + MARIO_HEIGTH;

    return mycam; 
}