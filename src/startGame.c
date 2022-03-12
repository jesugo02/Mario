#include "../includes/startGame.h"
#include "../includes/map.h"
#include "../includes/moveMapAndPlayer.h"
#include "../includes/mario.h"
#include "../includes/cam.h"


void play(SDL_Renderer **screen_renderer){
    SDL_Event e;
    int continuer=1;

    Map my_map = initMap("levelFile/lvl1.txt", screen_renderer);
    Mario my_mario = initPlayer(screen_renderer);
    CamGame game_camera = initCam(my_mario);

    while (continuer){

        // gravity(&my_mario, &my_map, screen_renderer);

        while (SDL_PollEvent(&e)){
            switch (e.type){
                case SDL_QUIT:
                destroyMap(my_map);
                destroyPlayer(my_mario);
                continuer=0;
                break;

			case SDL_KEYDOWN:
				switch (e.key.keysym.sym){
					case  SDLK_RIGHT:
                    move(RIGTH, &my_mario, &my_map, &game_camera);
					break;

					case  SDLK_LEFT:
                    move(LEFT, &my_mario, &my_map, &game_camera);
					break;
				}
				break;

            }

        }
        SDL_RenderClear(*screen_renderer);
        if (continuer){
            printMap(my_map, my_mario, screen_renderer, game_camera);
            printPlayer(my_mario, screen_renderer);
        }
        SDL_RenderPresent(*screen_renderer);
    }
}