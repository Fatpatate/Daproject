//arrayHelper.c

#include"arrayHelper.h"


//Draw a 0/1 doubleArray
void drawDoubleArray(unsigned **pDoubleArray, int pX1, int pX2,
						int pY1, int pY2)
{
	if(pDoubleArray)
	{
		for(int y = pY1; y < pY2; ++y)
		{
			for(int x = pX1; x < pX2; ++x)
			{
				if (pDoubleArray[y][x] == 1)
				{
					printf("0");
				}
				
				if	(pDoubleArray[y][x] == 0)
				{
					printf(".");
				}
			}
			printf("\n");
		}
	}
	else
	{
		printf("Draw PB\n");
	}
}

void drawBlock(unsigned **pDoubleArray, struct TextBlock *pBlock)
{
	if(pBlock)
	{
		drawDoubleArray(pDoubleArray, pBlock->x1, pBlock->x2,
						pBlock->y1, pBlock->y2);
	}
	else
	{
		printf("Draw Block Pb: block null?\n");
	}
}


//Free a Double Array
void freeDoubleArray(unsigned **pTab, int pSizeY)
{
	for(int y = 0; y < pSizeY; ++y)
	{
		free(pTab[y]);
	}
	free(pTab);
}
