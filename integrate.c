#include <stdio.h>
#include <math.h>

#include "integral_general.h"

void integral_recur (int nmin, int nmax, double vals[])	{

	double vals1[100 + 1]; 

	vals1[100] = 0.00367843028136748866811;

	for(int i = 99; i >= nmin; vals1[i] = vals1[i + 1] / (i + 1) + 1 / (M_E * (i + 1)), i--);

	int j = 0;

	for(int i = nmin; i <= nmax; i++, j++)	{
		vals[j] = vals1[i];
	}
}


void integral_gen (int nmin, int nmax, double vals[]);

void integral_gen (int nmin, int nmax, double vals[])	{
	gsl_integration_function();
}

int main(void)	{

	#define NMAX 100

	int nminn = 60;
	int nmaxx = 80;

	double vals1[NMAX + 1], vals2[NMAX + 1];

	integral_recur (nminn, nmaxx, vals1);
	
	integral_gen (nminn, nmaxx, vals2);

	for(int i = 0,j = nminn; i <= nmaxx - nminn; i++,j++)	{
		printf("%f\t%f\t%d\n", vals1[i], vals2[i], j);
	}

	return 0;
}
