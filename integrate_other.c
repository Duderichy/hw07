#include <stdio.h>
#include <math.h>


//void integral_recur (int nmin, int nmax, double vals[]); //do I need prototypes if func() before main()

//have to work backwards in order to get this to work, multiplying by small numbers == bad


void integral_recur (int nmin, int nmax, double vals[])	{

	// Use different array then set vals to certain position in that array or store only certain things in the array

	double vals1[100 + 1]; //or set size to nmin + nmax + 1 so it matches with size vals1 in main()

	vals1[100] = 0.00367843028136748866811;      // initial condition given by integrator

	for(int i = 99; i >= nmin; vals1[i] = vals1[i + 1] / (i + 1) + 1 / (M_E * (i + 1)), i--);

	int j = 0;

	for(int i = nmin; i <= nmax; i++, j++)	{

		vals[j] = vals1[i];

	}

	// *vals[] = *vals[nmin] // get vals to point to nmin in vals (I don't think I can do this)
		//Might end up having to use for loop to put values in vals instead

	//decided to do for loop only storing the vals that i want between nmin and nmax (inclusive)
}

void integral_gen (int nmin, int nmax, double vals[])	{



}




int main(void)	{

	#define NMAX 100

	int nminn = 20;
	int nmaxx = 40;

	double vals1[NMAX + 1], vals2[NMAX + 1];

	integral_recur (nminn, nmaxx, vals1); //returns nminn to nmaxx in vals1[] in positions 0 to nmaxx - nminn

	/*
	for(int i = 0; i <= nmaxx - nminn; i++)	{
		printf("%f\t%d\n", vals1[i], i);
	}
	*/

	integral_gen (nminn, nmaxx, vals2);

	return 0;
}