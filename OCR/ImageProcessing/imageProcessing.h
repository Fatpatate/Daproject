//imageProcessing.h

#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"pixelOperations.h"
#include<err.h>

#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

void wait_for_keypressed(void);

void init_sdl(void);

SDL_Surface* load_image(char *path);

SDL_Surface* display_image(SDL_Surface *img);

unsigned **toBWPicture(SDL_Surface *img, int *pWidth, int *pHeight);

#endif
