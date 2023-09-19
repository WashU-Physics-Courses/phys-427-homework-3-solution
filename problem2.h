#pragma once

#include <cmath>

template <typename F>
double gauss_quadrature_10(const F &f, double a, double b) {
  // abscissas and weights for 10-point Gauss quadrature
  const double x[5] = {0.1488743389816312, 0.4333953941292472,
                       0.6794095682990244, 0.8650633666889845,
                       0.9739065285171717};
  const double w[5] = {0.2955242247147529, 0.2692667193099963,
                       0.2190863625159821, 0.1494513491505806,
                       0.0666713443086881};
  // this is the solution in Numerical Recipes
  double xm = 0.5 * (b + a);
  double xr = 0.5 * (b - a);
  double s = 0.0;
  for (int i = 0; i < 5; i++) {
    double dx = xr * x[i];
    s += w[i] * (f(xm + dx) + f(xm - dx));
  }
  return xr * s;
}
