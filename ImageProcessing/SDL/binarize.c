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

/*return a matrix filled with 0(white pixel) and 1(black)
depending on the color of the pixel

unsigned short M[] binary_mat(SDl_Surface *img)
{
  Uint8 val;
  Uint32 pixel;
  unsigned short M[];

  for (int i = 0; i < img->w; i++)
  {
    for (int j = 0; j < img->h; j++)
    {
      pixel = getpixel(img, i, j);
      SDL_GetRGB(pixel, img->format, &val, &val, &val);
      if (val < 128)
        
    }
  }
} */
