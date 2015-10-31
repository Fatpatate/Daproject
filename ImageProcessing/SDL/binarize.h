# ifndef BINARIZE_H_
# define BINARIZE_H_

# include <stdio.h>
# include <stdlib.h>
# include <SDL.h>
# include "pixel_operations.h"

void binarize(SDL_Surface *img);
unsigned short* binary_mat(SDL_Surface *img);

# endif
