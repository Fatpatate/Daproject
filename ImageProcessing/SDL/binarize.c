# include "binarize.h"

/* input grayscaled img
set the image in black(0) and white(255) */

void  binarize(SDL_Surface *img)
{
  Uint8 r, g, b;
  Uint32 pixel;
  for (int i = 0; i < img->w; i++)
  {
    for (int j = 0; j < img->h; j++)
    {
      pixel = getpixel(img, i, j);
      SDL_GetRGB(pixel, img->format, &r, &g, &b);
      if ((r + g + b) / 3 < 128)
        pixel = SDL_MapRGB(img->format, 0, 0, 0);
      else
        pixel = SDL_MapRGB(img->format, 255, 255, 255);
      putpixel(img, i, j, pixel);
    }
  }
}

/*return a dyn_linear_matrix filled with 0(black pixel) and 1(white)
for pixel M[n],  x is obtained with n % width,
y is obtained with n / witdh */

unsigned short* binary_mat(SDL_Surface *img)
{
  Uint8 val;
  Uint32 pixel;
  unsigned short* mat;
  mat = malloc(img->w * img->h * sizeof(unsigned short));

  for (int y = 0; y < img->h; y++)
  {
    for (int x = 0; x < img->w; x++)
    {
      pixel = getpixel(img, x, y);
      SDL_GetRGB(pixel, img->format, &val, &val, &val);
      if (val < 128)
        mat[img->w * y + x] = 0;
      else
        mat[img->w * y + x] = 1;
    }
  }
  return mat;
}
