/* executeSystem.c: executes the neural system with the input Neural System */

#include "executeSystem.h"

void executeSystem(struct NeuralSystem *pThis, int pNeuronNumber)
{
	/* core */
	int		lCount		= 1;
	struct Neuron	*lNeuron	= NULL;
	int		lModuloNeuron	= 0;
	/* Begin */

	if (pThis)
	{
		while (lCount <= pThis->numberOfLoops)
		{
			lModuloNeuron = 0;
			for (int i = 0 ; i <  pNeuronNumber ; i++)
			{
				/*Choosing the neuron we will work on */
				lNeuron		= pThis->Neurons[i];
				/*Modifying weights*/
				newWeights(lNeuron, .7, lNeuron->theoricalResult);
				computePrecision(lNeuron);
				if (lCount == 1 || lCount % (pThis->numberOfLoops/5) == 0)
				{
					lModuloNeuron++;
					if (lModuloNeuron == 1)
						printf("Loop count %d\n", lCount);
					printf("Inputs %f and %f -- ", 
						lNeuron->inputs[K_INPUTS_Y - 3],
						lNeuron->inputs[K_INPUTS_Y- 2]);
					printf("Expected Result = %f. ",
						lNeuron->theoricalResult);
					printf("Experimental Result found = %f\n",
						lNeuron->experimentalResult);
					printf("->Neuron precision: %f\n",lNeuron->resultPrecision);
					if (lModuloNeuron == K_INPUTS_Y+1)
						printf("\n");
				}

			}
			lCount++;
		}
		printf("\n");
	}
	else
	{
		printf("\nERROR IN executeSystem.c: Input Neuronal system null\n");
	}
}
