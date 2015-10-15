// recognition.h

#ifndef RECOGNITION_H
#define RECOGNITION_H

#include <SDL.h>
#include "imageProcessing.h"
#include "TextBlock.h"
#include "imageDivision.h"


unsigned CompareCore(struct TextBlock *unknown, SDL_Surface *imgUnknown,
						struct TextBlock *known, SDL_Surface *imgKnown);


unsigned Compare(struct TextBlock *unknown, SDL_Surface *imgUnknow,
					struct TextBlock *known, SDL_Surface *imgKnown);


char CompareAlphabet(struct TextBlock *unknown, SDL_Surface *imgUnknown,
						SDL_Surface *imgKnown, struct TextBlock** alphabet,
						int sizeAlpha);

#endif
