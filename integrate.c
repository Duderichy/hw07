#include <stdio.h>
#include <math.h>


//void integral_recur (int nmin, int nmax, double vals[]); //do I need prototypes if func() before main()




void integral_recur (int nmin, int nmax, double vals[])	{

	// Use different array then set vals to certain position in that array or store only certain things in the array

	double vals1[nmax]; //or set size to nmin + nmax + 1 so it matches with size vals1 in main()

	vals[100] = 0.00367843028136748866811;      // initial condition given by integrator

	for(int i = 99; i >= nmin; vals[i] = vals[i + 1] / (i + 1) + 1 / (M_E * (i + 1)), i--);

	int j = 0;

	for(int i = nmin - 1; i <= nmax; vals[j] = vals1[i])	{

		printf("%f\n", vals[j]);

		i++;
		j++;

	}

	// *vals[] = *vals[nmin] // get vals to point to nmin in vals (I don't think I can do this)
		//Might end up having to use for loop to put values in vals instead

	//decided to do for loop only storing the vals that i want between nmin and nmax (inclusive)
}


void integral_gen (int nmin, int nmax, double vals[]);

void integral_gen (int nmin, int nmax, double vals[])	{



}




int main(void)	{

	#define NMAX 100

	int nmin = 1;
	int nmax = 20;

	printf("%d,%d", NMAX, nmax);

	double vals1[NMAX + 1], vals2[NMAX + 1];

	integral_recur (nmin, nmax, vals1);

	integral_gen (nmin, nmax, vals2);

	return 0;
}
