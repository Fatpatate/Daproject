// pixel_operations.h

# ifndef PIXEL_OPERATIONS_H_
# define PIXEL_OPERATIONS_H_

# include <stdlib.h>
# include <SDL.h>

Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y);
void putpixel(SDL_Surface *surface, unsigned x, unsigned y, Uint32 pixel);

Uint32 createGreyPixel(SDL_Surface *img, Uint32 pixel);
SDL_Surface* createGreyPicture(SDL_Surface *img);

# endif
