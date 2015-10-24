# include "grayscale.h"

void gray_scale(SDL_Surface *img)
{
  Uint8 r, g, b, gray;
  Uint32 pixel;
  for (int i = 0; i < img->w; i++)
  {
    for (int j = 0; j < img->h; j++)
    {
      pixel = getpixel(img, i, j);
      SDL_GetRGB(pixel, img->format, &r, &g, &b);
      r *= 0.3;
      g *= 0.59;
      b *= 0.11;
      gray = r + g + b;
      pixel = SDL_MapRGB(img->format, gray, gray, gray);
      putpixel(img, i, j, pixel);
    }
  }
}
