//TextBlock.h structure containing useful information about a text block
//(first pixel's coor, height and width)
// Here is the structure

#include<stdlib.h>

#ifndef TEXTBLOCK_H
#define TEXTBLOCK_H
struct TextBlock
{
	int x1, x2;
	int y1, y2;
};

#endif

struct TextBlock* textBlockInit(int pX1, int pX2, int pY1, int pY2);
