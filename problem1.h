#pragma once

#include <cmath>
#include <iostream>
#include <tuple>

template <typename F>
double trapezoidal_next(const F &f, double a, double b, double dx, double S) {
  double sum = 0.0;
  // the first extra point is at 0.5 * dx from a, rest are dx apart
  for (double x = a + 0.5 * dx; x < b; x += dx) {
    sum += f(x);
  }
  return 0.5 * (S + dx * sum);
}

template <typename F>
std::tuple<bool, double> adaptive_simpson(const F &f, double a, double b,
                                          double tolerance) {
  double h = b - a;

  // First trapezoidal estimate
  double S = 0.5 * h * (f(a) + f(b));
  double Sprime = S;

  for (int n = 1; n < 30; n++) {
    // std::cout << n << " " << Sprime << std::endl;
    // get the next trapezoidal estimate
    double Snext = trapezoidal_next(f, a, b, h, S);
    // construct the next Simpson estimate
    double Sprime_next = (4.0 * Snext - S) / 3.0;

    // check for convergence
    if (std::abs((Sprime_next - Sprime) / Sprime_next) / 15.0 < tolerance) {
      return std::make_tuple(true, Sprime_next);
    }
    // update for next iteration
    Sprime = Sprime_next;
    S = Snext;
    h *= 0.5;
  }
  return std::make_tuple(false, Sprime);
}
