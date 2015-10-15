/* Neuron.c: initalizes a Neuron */

#include"Neuron.h"


/* Method initializing a neuron */
struct Neuron *neuronInit(double pInputs[], int pNbInputs)
{
	double			lRandomWeight	= .0;
	struct Neuron		*lNeuron	= NULL;

	lNeuron 		= (struct Neuron *)malloc(sizeof(struct Neuron));
	/* Begin */
	lNeuron->experimentalResult	= 0.;
	lNeuron->theoricalResult	= 0.;
	lNeuron->resultPrecision	= 0.;
	lNeuron->nbInputs		= pNbInputs;

	srand(time(NULL));
	lRandomWeight = mathsRand(-0.2, 0.2);
	lNeuron->postNeuronWeight = lRandomWeight;

	lNeuron->inputs = pInputs;
	lNeuron->weights = malloc(pNbInputs * sizeof(double));

	for(int i = 0 ; i < pNbInputs; i++)
	{
		/* Putting a random float for the weight */
		lRandomWeight = mathsRand(-2,2);
		lNeuron->weights[i] = lRandomWeight;
	}

	return lNeuron;
}
