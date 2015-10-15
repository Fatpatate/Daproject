//imageDivision.h

#include"TextBlock.h"
#include"pixelOperations.h"

#ifndef IMAGE_DIVISION_H
#define IMAGE_DIVISION_h

void findBounds(unsigned **tab, int pStartDim1, int pStopDim1, int pStartDim2,
	int pStopDim2, char pDim1,  int *pBound1, int *pBound2, int pCheckUntilEnd);


void getLine(unsigned **tab, int pTabWidth, int pTabHeight, int pStartX,
				 int pStartY, int *pTopBound, int *pLeftBound);

void topBotChar(unsigned **tab, int pTabWidth, int pTabHeight, int pStartX,
				int pStartY, int *pTopBound, int *pLeftBound);

void getChar(unsigned **tab, int pTabWidth, struct TextBlock *pTextBlock,
 				int pStartX, int pStartY, int *pLeftBound, int *pRightBound);

struct TextBlock **getAllChar(unsigned **tab, int pTabWidth,
				 struct TextBlock *pLine);

struct TextBlock **getAllLine(unsigned **tab, struct TextBlock *pPage);

#endif
