/* neuralOperations.c: Contains the following methods
		- computeResult: applies the input function to the neural
			sum of the input neuron.
		- newWeights: changes the weights of the input neuron.

		- neuralSum
		- changeWeightOutput
		- changeWeightInput
		- deltaOutput
		- deltaInput
*/

#include "neuralOperations.h"

double computeResult(struct Neuron *pThis, double (*func)(double)) 
{
	double lOutput = .0;

	if (pThis != NULL)
	{
		lOutput = (*func)(neuralSum(pThis));
	}
	else
	{
		printf("\nERROR IN computeResult.c : input Neuron null \n");
	}
	return lOutput;
}

double newWeights(struct Neuron *pThis, double pLearningRate, double pTheoValue)
{
	double	lNeuralSum			= neuralSum(pThis);
	double	lExperimentalValue	=
					sigmoid(sigmoid(lNeuralSum) * pThis->postNeuronWeight);

	double	lDeltaOutput	= deltaOutput(lExperimentalValue, pTheoValue);
	double	lDeltaInput	= deltaInput(lDeltaOutput, pThis->postNeuronWeight,
										lNeuralSum);

	double lChangeOutput	= changeWeightOutput(pLearningRate, lDeltaOutput,
													lNeuralSum);



	pThis->experimentalResult	= lExperimentalValue;
	pThis->postNeuronWeight		+= lChangeOutput;
	
	for(int i =0; i< pThis->nbInputs; i++)
	{
		pThis->weights[i] += changeWeightInput(pLearningRate, lDeltaInput, 
												pThis->inputs[i]);
	}
	return (pTheoValue -lExperimentalValue);
}


double neuralSum(struct Neuron *pThis)
{
	double 	sum	=0;

	for(int i = 0; i < pThis->nbInputs; ++i)
	{
		sum += (pThis->weights[i])*(pThis->inputs[i]);
	}

	return sum;
}

double changeWeightOutput(double pLearningRate, double pDeltaOutput ,
							 double pNeuralSum)
{
	return pLearningRate * pDeltaOutput * sigmoid(pNeuralSum);
}

double changeWeightInput(double pLearningRate, double pDeltaInput,double pInput)
{
	return pLearningRate *  pDeltaInput * pInput;
}

double deltaOutput(double pOutput, double pTarget)
{
	return pOutput * (pTarget - pOutput);
}

double deltaInput(double pDeltaOutput, double pOutputWeight, double pNeuralSum)
{
	return sigmoidDerivative(sigmoid(pNeuralSum)) * pDeltaOutput *pOutputWeight;
}

void computePrecision(struct Neuron *pThis)
{
	double lR1	= pThis->theoricalResult;
	double lR2	= pThis->experimentalResult;

	pThis->resultPrecision = fabsf(lR1 - lR2);
}
