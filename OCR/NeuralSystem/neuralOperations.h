/* neuralOperations.h */

#include "Neuron/Neuron.h"

#ifndef NEURAL_OPERATIONS_H
#define NEURAL_OPERATIONS_H

double computeResult(struct Neuron *pThis, double (*func)(double));

double newWeights(struct Neuron *pThis,double pLearningRate, double pTheoValue);


double neuralSum(struct Neuron *pThis);

double changeWeightOutput(double pLearningRate, double pDeltaOutput,
							 double pNeuralSum);
double changeWeightInput(double pLearningRate,double pDeltaInput,double pInput);

double deltaOutput(double pOutput, double pTarget);
double deltaInput(double pDeltaOutput, double pOutputWeight, double pNeuralSum);

void computePrecision(struct Neuron *pThis);

#endif
