#include "../includes/startGame.h"
#include "../includes/map.h"

void play(SDL_Renderer **screen_renderer){
    SDL_Event e;
    int continuer=1;

    Map my_map = initMap("levelFile/lvl1.txt", screen_renderer);

    while (continuer){

        while (SDL_PollEvent(&e)){
            switch (e.type){
            case SDL_QUIT:
                continuer=0;
                break;
            }

        }
        SDL_RenderClear(*screen_renderer);
        printMap(my_map, screen_renderer);
        SDL_RenderPresent(*screen_renderer);
    }
}