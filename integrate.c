#include <stdio.h>
#include <math.h>

#include "timer.h"
#include "adjust.h"

#include "integral_general.h"

void integral_recur (int nmin, int nmax, double vals[])	{
	// works backwards from I_100 using a given value at 100, and calculates the
	// values of the integral between nmin and nmax and stores them (as well as
	// calculating for all values > nmax, but it does not store them)

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
	// this function uses the gsl library to calculate the value of the integral
	// numerically
	gsl_integration_function(nmax, nmin, vals);
}

int main(void)	{

	#define NMAX 100 //array size for storing the values of I_n

	int nminn = 0; //min value of n to be calulated for integrals
	int nmaxx = 100; //max value of n to be calculated for integrals

	double vals1[NMAX + 1], vals2[NMAX + 1];

	integral_recur (nminn, nmaxx, vals1);

	integral_gen (nminn, nmaxx, vals2);

	// prints and compares the values of the different methods
	for(int i = 0,j = nminn; i <= nmaxx - nminn; i++,j++)	{
		printf("%.18f\t%.18f\t%d\n", vals1[i], vals2[i], j);
	}

	int count = 10;
	double time;
	double time1;
	double tmin = 1;
	double tmax = 2;

	// times integral_recur and integral_gen per function call
	// adjusts the number of calls such that there are enough calls to get a good
	// average time per function call
	printf("integral_recur\n");

	do {
			timer_start ();

			for (int k = 0; k <= count; k++) {

				integral_recur (nminn, nmaxx, vals1);

			}

			time = timer_stop ();

			time1 = time / count;

			printf (" %10.2f usec     %10.6f sec    %10d\n",
					time1 * 1.e6, time, count);

			/*
			 * adjust count such that cpu time is between
			 * tmin and tmax
			 */

			count = adjust_rep_count (count, time, tmin, tmax);


	} while ((time > tmax) || (time < tmin));

	printf("integral_gen\n");

	count = 10;

	do {
			timer_start ();

			for (int k = 0; k <= count; k++) {

			integral_gen (nminn, nmaxx, vals2);

			}

			time = timer_stop ();

			time1 = time / count;

			printf (" %10.2f usec     %10.6f sec    %10d\n",
					time1 * 1.e6, time, count);

			/*
			 * adjust count such that cpu time is between
			 * tmin and tmax
			 */

			count = adjust_rep_count (count, time, tmin, tmax);


	} while ((time > tmax) || (time < tmin));

	return 0;
}
