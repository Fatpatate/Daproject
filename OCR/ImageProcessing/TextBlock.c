//TextBlock.h structure with uselful information about a text block
//(first pixel's coor, height and width)
//Here is the initializer

#include"TextBlock.h"

struct TextBlock* textBlockInit(int pX1, int pX2, int pY1, int pY2)
{
	struct TextBlock* lTextBlock = NULL;
	lTextBlock = malloc(sizeof(struct TextBlock));
	lTextBlock->x1 = pX1;
	lTextBlock->x2 = pX2;
	lTextBlock->y1 = pY1;
	lTextBlock->y2 = pY2;

	return lTextBlock;
}
