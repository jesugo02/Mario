#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char const *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Event e;
    int continuer=1;
    SDL_Window *w;
    SDL_Renderer *r;
    SDL_Surface *s;
    SDL_Texture *t;

    SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &w, &r);
    
    while (continuer){
        while (SDL_PollEvent(&e)){
            switch (e.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
             
            case SDL_MOUSEBUTTONDOWN:
                s = IMG_Load("image/sky.png");
                t = SDL_CreateTextureFromSurface(r, s);
                SDL_RenderCopy(r, t, NULL, NULL);
                break;
            }
        }

        SDL_RenderPresent(r);        
    }
    SDL_FreeSurface(s);
    SDL_DestroyTexture(t);
    SDL_DestroyWindow(w);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
