/* mathsHelper.h */

#ifndef MATHS_HELPER_H
#define MATHS_HELPER_H

#include <time.h>
#include <math.h>
#include <stdlib.h> 

double sigmoid(double x);
double sigmoidDerivative(double x);
double mathsRand(double a, double b);
double funcXOR(double *inputs, int size);
#endif
