/* Neuron.h */

#include <stdio.h>
#include <stdlib.h>
#include "../../Helper/mathsHelper.h"

/* Definition of the structure Neuron */

#ifndef NEURON_H
#define NEURON_H

struct Neuron
{
	double	*inputs;
	double	*weights;
	double	postNeuronWeight;
	double	experimentalResult;
	double	theoricalResult;
	double	resultPrecision;
	int	nbInputs;
};

struct Neuron *neuronInit(double pInputs[], int pNbInputs);

#endif
