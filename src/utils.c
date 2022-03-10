#include "../includes/utils.h"

SDL_Texture* load_image(char *image_path, SDL_Renderer **screen_renderer){
    SDL_Surface *image_surface = NULL;
    SDL_Texture *image_texture = NULL;

    image_surface = IMG_Load(image_path);
    if (image_surface == NULL){
        printf("\nImage not charge : %s\n", IMG_GetError());
        exit(-1);
        return NULL;
    }else{
        image_texture = SDL_CreateTextureFromSurface(*screen_renderer, image_surface);
        printf("\n%p\n", image_texture);
        SDL_FreeSurface(image_surface);
        if (image_texture==NULL){
            printf("\nTexture not charge : %s\n", SDL_GetError());
            return NULL;
        }else
            return image_texture;
    }
}