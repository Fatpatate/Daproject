# ifndef BINARIZE_H_
# define BINARIZE_H_

# include <stdio.h>
# include <stdlib.h>
# include <SDL>
# include "pixel_operation.h"

void binarize(SDL_Surface *img);
unsigned short M[] binary_mat(SDL_Surface *img);

# endif
