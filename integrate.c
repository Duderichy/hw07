#include <stdio.h>
#include <math.h>

#include "timer.h"
#include "adjust.h"

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
	gsl_integration_function(nmax, nmin, vals);
}

int main(void)	{

	#define NMAX 100

	int nminn = 0;
	int nmaxx = 100;

	double vals1[NMAX + 1], vals2[NMAX + 1];

	integral_recur (nminn, nmaxx, vals1);

	integral_gen (nminn, nmaxx, vals2);

	for(int i = 0,j = nminn; i <= nmaxx - nminn; i++,j++)	{
		printf("%.18f\t%.18f\t%d\n", vals1[i], vals2[i], j);
	}

	int count = 10;
	double time;
	double time1;
	double tmin = 1;
	double tmax = 2;

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
