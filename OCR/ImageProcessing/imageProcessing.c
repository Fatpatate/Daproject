//imageProcessing.c : functions used to work on a picture
//(Load, Display, getLine...)

#include"imageProcessing.h"


// Wait for a key to be pressed
void wait_for_keypressed(void)
{
	SDL_Event	event;
	for (;;) // Infinite loop
	{
		SDL_PollEvent( &event );
	    	switch (event.type)
			{
	    		// Someone pressed a key -> leave the function
	    		case SDL_KEYDOWN: return;
	    		default: break;
	    	}
	}
}


// Initialize SDL
void init_sdl(void)
{
	// Init only the video part
	if( SDL_Init(SDL_INIT_VIDEO)==-1 )
	{
		// If it fails, die with an error message
		errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
	}
}


// Load an image in memory from its path
SDL_Surface* load_image(char *path)
{
	SDL_Surface          *img;
	img = IMG_Load(path);

	if (!img)
	{
		errx(3, "can't load %s: %s", path, IMG_GetError());
	}

	return img;
}


// Display an Image
SDL_Surface* display_image(SDL_Surface *img)
{
	SDL_Surface          *screen;
	// Set the window to the same size as the image
	screen = SDL_SetVideoMode(img->w, img->h, 0, SDL_SWSURFACE|SDL_ANYFORMAT);
	
	if ( screen == NULL )
	{
		errx(1, "Couldn't set %dx%d video mode: %s\n",
			img->w, img->h, SDL_GetError());
	}

	/* Blit onto the screen surface */
	if(SDL_BlitSurface(img, NULL, screen, NULL) < 0)
		{
			warnx("BlitSurface error: %s\n", SDL_GetError());
		}

	// Update the screen
	SDL_UpdateRect(screen, 0, 0, img->w, img->h);

	// wait for a key
	wait_for_keypressed();

	// return the screen for further uses
	return screen;
}


// Replace the picture by a B&W version (Binarization)
unsigned **toBWPicture(SDL_Surface *img, int *pWidth, int *pHeight)
{
	if(img)
	{
		Uint8 r, g, b;
		Uint8 mean;
		unsigned **tab = malloc(img->h * sizeof(*tab));


		if(tab)
		{
			for(int y= 0; y< img->h; y++)
			{
				tab[y] = malloc(img->w * sizeof(**tab));

				for(int x=0; x< img->w; x++)
				{
					SDL_GetRGB(getpixel(img, x, y), img->format,
						&r, &g, &b);

					mean = (0.3*r + 0.59*g + 0.11*b);

					if(mean > 162)
					{
						tab[y][x] = 0;
					}
					else
					{
						tab[y][x] = 1;
					}
				}
			}
			*pWidth = img->w;
			*pHeight = img->h;

		}
		else
		{
			printf("ERROR: BW Picture => Tab pointer error ff mental \n");
		}
		return tab;
	}
	else
	{
		printf("ERROR WITH TOBWPicture function\n");
		return NULL;
	}
}
