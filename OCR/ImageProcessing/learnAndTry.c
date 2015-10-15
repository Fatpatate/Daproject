//learnAndTry.c

#include"learnAndTry.h"
#include"startProcessing.h"

void learnAndTry()
{
	SDL_Surface *img = load_image("test10.png");
	SDL_Surface *alpha = load_image("alphabet.png");

	struct TextBlock *alphabet = textBlockInit(0,0,0,0);
	alphabet = startLearning(alpha);
	struct TextBlock **testedCharacters = startProcessing(img);
	char result = CompareAlphabet(testedCharacters[0],img, alpha, &alphabet, 52);

	printf("The first letter of the image is : \"%c\"\n", result);
}
