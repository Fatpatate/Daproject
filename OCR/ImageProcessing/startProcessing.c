//startProcessing.c

#include"startProcessing.h"
#include"../Helper/arrayHelper.h" //Has to be deleted when the test are finished

struct TextBlock** startProcessing(SDL_Surface* img)
{
	if(img)
	{
		init_sdl();
		display_image(img);

		int lImgW, lImgH;
		unsigned **tab = toBWPicture(img, &lImgW, &lImgH);

		struct TextBlock *lPage = textBlockInit(0, lImgW, 0, lImgH);
		return getAllLine(tab, lPage);
		//SDL_FreeSurface(img);
		//freeDoubleArray(firstLine);
	}
	else
	{
		printf("NULL IMAGE\n");
		return NULL;
	}
}
