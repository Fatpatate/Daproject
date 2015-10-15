//imageDivision.c


#include"imageDivision.h"
#include"../Helper/arrayHelper.h"

void findBounds(unsigned **tab, int pStartDim1, int pStopDim1, int pStartDim2,
	int pStopDim2, char pDim1,  int *pBound1, int *pBound2, int pCheckUntilEnd)
{
	if(tab)
	{
		int	lBound1 =0, lBound2 = 0;
		int lDim2 = 0;
		int lLastBlackLine = 0;

		//Bool
		int	lFound1 = 0;
		int lFound2 = 0;
		int	lCurrentLineBlank = 1;
		int lTestBlock = 0;
		int lCheckUntilEnd;

		for(int lDim1 = pStartDim1; lDim1 < pStopDim1; lDim1++)
		{
			lDim2= pStartDim2;
			lCurrentLineBlank = 1;

			if(pCheckUntilEnd)
			{
				lCheckUntilEnd = 1;
			}
			else
			{
				lCheckUntilEnd = !lFound2;
			}

			while(lDim2 < pStopDim2 && lCheckUntilEnd)
			{
				if(pDim1 == 'x')
				{
					lTestBlock = (tab[lDim2][lDim1] == 1);
				}
				else
				{
					lTestBlock = (tab[lDim1][lDim2] == 1);
				}

				if (!lFound1 && lTestBlock)
					// find the top bound
				{
					lBound1 = lDim1;
					lFound1 = 1;
					lCurrentLineBlank = 0;
				}
				
				if(lFound1)
				{
					if(lCurrentLineBlank && lTestBlock)
						// check if the line is blank
					{
						lCurrentLineBlank = 0;
						lLastBlackLine = lDim1;
					}
				
					if((lCurrentLineBlank &&
						(lDim2 == pStopDim2 -1)) || lDim1  == pStopDim1 -1)
					// determine the bottom bound
					{
						lBound2 = lDim1;
						lFound2 = 1;

						if(pCheckUntilEnd)
						{
							lCheckUntilEnd = 1;
							lBound2 = lLastBlackLine+1;
						}
						else
						{
							lCheckUntilEnd = !lFound2;
						}


							*pBound1 = lBound1;
							*pBound2 = lBound2;
					}
				}
				lDim2++;
			}
		}
	}
	else
	{
		printf("Error while searching bounds: tab null? \n");
	}
}

void getLine(unsigned **tab, int pTabWidth, int pTabHeight, int pStartX,
				int pStartY, int *pTopBound, int *pLeftBound)
{
	findBounds(tab, pStartY, pTabHeight, pStartX, pTabWidth, 'y', pTopBound,
				 pLeftBound,0);
}

void topBotChar(unsigned **tab, int pTabWidth, int pTabHeight, int pStartX,
				int pStartY, int *pTopBound, int *pLeftBound)
{
	findBounds(tab, pStartY, pTabHeight, pStartX, pTabWidth, 'y', pTopBound,
				 pLeftBound,1);
}

void getChar(unsigned **tab, int pTabWidth, struct TextBlock *pTextBlock,
				int pStartX, int pStartY, int *pLeftBound, int *pRightBound)
{
	if(pTextBlock)
	{
		findBounds(tab, pStartX, pTabWidth, pStartY, pTextBlock->y2, 'x',
					pLeftBound, pRightBound,0);
	}
	else
	{
		printf("getChar error : text block null\n");
	}
}

struct TextBlock **getAllChar(unsigned **tab, int pTabWidth,
								 struct TextBlock *pLine)
{
	if(tab && pLine)
	{
		struct TextBlock **lArray = NULL;
		int lFinalX = 0;
		int lNbChar = 0;

		lArray = malloc( 100 * sizeof(*lArray)); // WE HAVE TO CHANGE THIS !

		while(lFinalX < (pLine->x2))
		{
			int lLeft = 0, lRight = 0;
			getChar(tab, pTabWidth, pLine, lFinalX, pLine->y1, &lLeft, &lRight);

			if(lLeft != lRight)
			{
				struct TextBlock *lChar = textBlockInit(pLine->x1, pLine->x2,
														pLine->y1, pLine->y2);
				if(lChar)
				{
					lChar->x1 = lLeft;
					lChar->x2 = lRight;
					topBotChar(tab, lChar->x2, lChar->y2+1, lChar->x1,lChar->y1,
								&lChar->y1, &lChar->y2);

					lFinalX = lRight;

					printf("x1 %d x2 %d y1 %d y2 %d\n", lChar->x1, lChar->x2,
								lChar->y1, lChar->y2);
					lArray[lNbChar] = lChar;
					drawBlock(tab, lChar);
					printf("Char %d saved\n",
							 lNbChar+1);

					lNbChar++;
				}
			}
			else
			{
				lFinalX = pLine->x2;
			}
		}
		printf("Nb of Char = %d\n", lNbChar);
		return lArray;
	}
	else
	{
		printf("getAllChar error: tab or line null\n");
		return NULL;
	}
}

struct TextBlock **getAllLine(unsigned **tab, struct TextBlock *pPage)
{
	if(tab && pPage)
	{
		struct TextBlock **lArray = NULL;
		int lFinalY = 0;
		int lNbLine = 0;

		lArray = malloc( 100*sizeof(struct TextBlock)); // WE HAVE TO CHANGE THIS !

		while(lFinalY < (pPage->y2))
		{
			int lTop = 0, lBot = 0;
			getLine(tab, pPage->x2, pPage->y2, 0, lFinalY, &lTop, &lBot);

			if(lTop != lBot)
			{
				struct TextBlock *lLine = textBlockInit(pPage->x1, pPage->x2,
														pPage->y1, pPage->y2);
				if(lLine)
				{
					lLine->y1 = lTop;
					lLine->y2 = lBot;

					lFinalY = lBot;

					printf("x1 %d x2 %d y1 %d y2 %d\n", lLine->x1, lLine->x2, 
								lLine->y1, lLine->y2);
					lArray[lNbLine] = lLine;
					//drawBlock(tab, lLine);
					printf("-----------------------------------------------\n");
					printf("Line %d saved\n",
							 lNbLine+1);
					getAllChar(tab, pPage->x2, lLine);
					lNbLine++;
				}
			}
			else
			{
				lFinalY = pPage->y2;
			}
		}
		printf("Nb of Lines = %d\n", lNbLine);
		return lArray;
	}
	else
	{
		printf("getAllChar error: tab or line null\n");
		return NULL;
	}
}

