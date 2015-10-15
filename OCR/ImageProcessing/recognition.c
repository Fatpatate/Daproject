//recognition.c

#include"recognition.h"

unsigned CompareCore(struct TextBlock *unknown, SDL_Surface *imgUnknown,
				struct TextBlock *known, SDL_Surface *imgKnown)
{
	int hKnown, hUnknown, wKnown, wUnknown;
	unsigned **tabKnown = toBWPicture(imgKnown, &wKnown, &hKnown);
	unsigned **tabUnknown = toBWPicture(imgUnknown, &wUnknown, &hUnknown);

	unsigned error = 0;
	int y = known->y1, y2 = unknown->y1;
	int x = known->x1, x2 = unknown->x1;

	for(; y>=known->y2 && error<5; y++, y2++)
	{
		for(; x>=known->x2 && error<5; x++, x2++)
		if(tabUnknown[y2][x2] != tabKnown[y][x])
		{
			error++;
		}
	}

	return (error<5);
}

unsigned Compare(struct TextBlock *unknown, SDL_Surface *imgUnknown,
				struct TextBlock *known, SDL_Surface *imgKnown)
{
	printf("On entre dans le compare lol\n");
	if((unknown->x2 - unknown->x1 == known->x2 - known->x1) && (unknown->y2 - unknown->y1 ==  known->y2 - known->y1))
	{
		printf("Ok le test est bon sa race\n");
		return CompareCore(unknown, imgUnknown, known, imgKnown);
	}
	else
	{
		return 0;
		//resize
	}
	
}

char CompareAlphabet(struct TextBlock *unknown, SDL_Surface *imgUnknown, SDL_Surface *imgKnown, struct TextBlock** alphabet, int sizeAlpha)
{
	printf(" b\n" );
	for(int i = 0; i<sizeAlpha; i++)
	{
		printf("%d\n", i );
		if(Compare(unknown, imgUnknown, alphabet[i], imgKnown))
		{
			if(i <= 25)
			{
				return 'a' + i;
			}
			else
			{
				return 'A' -26 +i;
			}
			printf("%d\n",i );
		}
	}
	return '?';
}

