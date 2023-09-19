#pragma once

#include <tuple>
#include <cmath>
#include <iostream>

template <typename F>
double trapezoidal_next(const F& f, double a, double b, double dx, double S) {
  double sum = 0.0;
  for (double x = a + 0.5 * dx; x < b; x += dx) {
    sum += f(x);
  }
  return 0.5 * (S + dx * sum);
}

template <typename F>
std::tuple<bool, double> adaptive_simpson(const F& f, double a, double b, double tolerance) {
  double h = b - a;

  double S = 0.5 * h * (f(a) + f(b));
  double I = S;

  for (int n = 1; n < 100; n++) {
    std::cout << n << " " << I << std::endl;
    double Snext = trapezoidal_next(f, a, b, h, S);
    double Inext = (4.0 * Snext - S) / 3.0;

    if (std::abs((Inext - I) / Inext) / 15.0 < tolerance) {
      return std::make_tuple(true, Inext);
    }
    I = Inext;
    S = Snext;
    h *= 0.5;
  }
  return std::make_tuple(false, I);
}
