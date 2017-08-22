#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

#include "integral_general.h"

// integrates the given function for all n values between nmin and nmax

double f (double x, void *params) {
  double n = *(double *) params;
  double f = exp (-x) * pow (x, n);
  return f;
}

void gsl_integration_function (int nmax, int nmin, double vals[]) {

  double result, error;
  double a = 0., b = 1.;
  double abserr = 1.8e-9, relerr = 1.e-9;
  double n;
  size_t np = 1000;
  gsl_integration_workspace *w = gsl_integration_workspace_alloc (np);

  gsl_function F;
  F.function = &f;

  for (int i = nmin, j = 0; i <= nmax; i++, j++)
  {
     n = (double) i;
     F.params = &n;

     gsl_integration_qag (&F, a, b, abserr, relerr, np, GSL_INTEG_GAUSS15, w,
   		          &result, &error);

     // printf ("%5d   % .18f", i, result);
     // printf ("   % .18f", error);
     // printf ("   %zu\n", w->size);
     vals[j] = result;
  }

  gsl_integration_workspace_free (w);

}
