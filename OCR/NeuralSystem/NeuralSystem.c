/* NeuralSystem.c: initializes a NeuralSystem */

#include "NeuralSystem.h"

struct NeuralSystem *neuralSystemInit(int pNumberOfLoops,
						double (*pFTheoValue)(double TableInputs[K_INPUTS_X],
						int pSizeTable),
						double pAllInputs[K_INPUTS_X][K_INPUTS_Y])
{
	struct Neuron		*lNeuron		= NULL;
	struct NeuralSystem *lNeuralSystem	= NULL;


	lNeuralSystem = (struct NeuralSystem *)malloc(sizeof(struct NeuralSystem));
	


	/* Begin */

	lNeuralSystem->numberOfLoops = pNumberOfLoops;

	lNeuralSystem->numberOfNeurons		= K_INPUTS_X;

	lNeuralSystem->fTheoValue = pFTheoValue;

	//copy all inputs possible
	for(int x = 0 ; x <K_INPUTS_X ; x++)
	{
		for (int y = 0 ; y < K_INPUTS_Y ; y++)
		{
			lNeuralSystem->allInputs[x][y] = pAllInputs[x][y];
		}
	}
	//printf("XOR truth table: done\n");

	//Initialization of the Neurons
	for(int i = 0 ; i < K_INPUTS_X ; i++)
	{
		lNeuron				= neuronInit(pAllInputs[i], K_INPUTS_Y);
		lNeuron->theoricalResult= pFTheoValue(lNeuron->inputs, K_INPUTS_Y);
		lNeuralSystem->Neurons[i]	= lNeuron;
	}

	return lNeuralSystem;
}
