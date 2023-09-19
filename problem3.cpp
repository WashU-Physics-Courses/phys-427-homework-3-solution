#include "problem1.h"
#include "problem2.h"

#include <iostream>

int main() {
  double th_max = 0.01 * M_PI;
  // auto f1 = [th_max](double x) { return 1.0 / std::sqrt(std::pow(std::sin(th_max),2)
  //                                                       - std::pow(std::sin(x),2)); };
  double k = std::sin(th_max * 0.5);
  auto f = [k](double x) { return 1.0 / std::sqrt(1.0 - k*k*std::pow(std::sin(x), 2)); };

  auto t = gauss_quadrature_10(f, 0.0, M_PI * 0.5);
  // auto t = adaptive_simpson(f, 0.0, M_PI * 0.5, 1e-8);

  std::cout << "th_max = 0.01 * pi: t/t0 = " << t * 2.0 / M_PI << std::endl;

  th_max = 0.1 * M_PI;
  k = std::sin(th_max * 0.5);
  auto f2 = [k](double x) { return 1.0 / std::sqrt(1.0 - k*k*std::pow(std::sin(x), 2)); };
  t = gauss_quadrature_10(f2, 0.0, M_PI * 0.5);
  std::cout << "th_max = 0.1 * pi: t/t0 = " << t * 2.0 / M_PI << std::endl;

  th_max = M_PI / 6;
  k = std::sin(th_max * 0.5);
  auto f3 = [k](double x) { return 1.0 / std::sqrt(1.0 - k*k*std::pow(std::sin(x), 2)); };
  t = gauss_quadrature_10(f3, 0.0, M_PI * 0.5);
  std::cout << "th_max = pi / 6: t/t0 = " << t * 2.0 / M_PI << std::endl;

  th_max = M_PI / 3;
  k = std::sin(th_max * 0.5);
  auto f4 = [k](double x) { return 1.0 / std::sqrt(1.0 - k*k*std::pow(std::sin(x), 2)); };
  t = gauss_quadrature_10(f4, 0.0, M_PI * 0.5);
  std::cout << "th_max = pi / 3: t/t0 = " << t * 2.0 / M_PI << std::endl;

  th_max = M_PI / 2;
  k = std::sin(th_max * 0.5);
  auto f5 = [k](double x) { return 1.0 / std::sqrt(1.0 - k*k*std::pow(std::sin(x), 2)); };
  t = gauss_quadrature_10(f5, 0.0, M_PI * 0.5);
  std::cout << "th_max = pi / 2: t/t0 = " << t * 2.0 / M_PI << std::endl;

  // th_max = 179.0 / 180.0 * M_PI;
  // k = std::sin(th_max * 0.5);
  // auto f6 = [k](double x) { return 1.0 / std::sqrt(1.0 - k*k*std::pow(std::sin(x), 2)); };
  // // t = gauss_quadrature_10(f6, 0.0, M_PI * 0.5);
  // auto result = adaptive_simpson(f6, 0.0, M_PI * 0.5, 1e-12);
  // t = std::get<1>(result);
  // std::cout << "th_max = 179^o: t/t0 = " << t * 2.0 / M_PI << std::endl;

  return 0;
}
