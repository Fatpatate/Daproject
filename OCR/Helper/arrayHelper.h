#include<stdio.h>
#include<stdlib.h>
#include"../ImageProcessing/TextBlock.h"

#ifndef ARRAY_HELPER_H
#define ARRAY_HELPER_H

void drawDoubleArray(unsigned **pDoubleArray, int pX1, int pX2,
						int pY1, int pY2);

void freeDoubleArray(unsigned **pTab, int pSizeY);

void drawBlock(unsigned **pDoubleArray, struct TextBlock *pBlock);

#endif