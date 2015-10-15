#include "mathsHelper.h"

/* mathsHelper.c: Contains the following mathematical methods
		- sigmoid: returns the sigmoid of the input
		- sigmoidDerivative: returns the derivative of the sigmoid of the input
		- mathsRand: returns a random number between a and b
		*/

double sigmoid(double x)
{
	return (1/(1+exp(-x)));
	//return tanh(x);
}

double sigmoidDerivative(double x)
{
	return sigmoid(x)*(1- sigmoid(x));
	//return (1- x*x);
}

double mathsRand(double a, double b)
{
		return (b - a) * ((double)rand() / RAND_MAX) + a;
}

double funcXOR(double *inputs, int size)
{
	size++;
	double lOutput = 0.;
	if(inputs[1] != inputs[0])
		lOutput = 1.;
	return lOutput;
}
