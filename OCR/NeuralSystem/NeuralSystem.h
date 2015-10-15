/* NeuralSystem.h */

#include"Neuron/Neuron.h"

#ifndef NEURALSYSTEM_H
#define NEURALSYSTEM_H

#define K_NUMBER_NEURONS 32

#define K_INPUTS_X 4
#define K_INPUTS_Y 3

struct NeuralSystem
{
	struct Neuron	*Neurons[K_NUMBER_NEURONS];
	double		allInputs[K_INPUTS_X][K_INPUTS_Y];
	double		(*fTheoValue)(double *pTableInputs, int pTableSize);
	int		numberOfNeurons;
	int		numberOfLoops;
};

#endif

struct NeuralSystem *neuralSystemInit(int pNumberOfLoops,
						double (*pFTheoValue)(double pTableInputs[K_INPUTS_X],
						int pTableSize),
						double pAllInputs[K_INPUTS_X][K_INPUTS_Y]);
