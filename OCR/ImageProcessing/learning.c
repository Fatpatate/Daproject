//learning.c

#include "learning.h"


struct TextBlock* startLearning(SDL_Surface *pImage)
{
	if(pImage)
	{
		init_sdl();
		display_image(pImage);

		int lImgW, lImgH;
		unsigned **tab = toBWPicture(pImage, &lImgW, &lImgH);
		struct TextBlock *lPage = textBlockInit(0, lImgW, 0, lImgH);
		return getAllLine(tab, lPage)[0];
		//SDL_FreeSurface(img);
		//freeDoubleArray(firstLine);
	}
	else
	{
		printf("startLearning.c : null image\n");
		return NULL;
	}
}

