#include "s21_math.h"

double s21_fac(int);

long double s21_sin(double x) {
  long double result;
  if (S21_IS_INF(x) || S21_IS_NAN(x)) {
    result = S21_NAN;
  } else {
    if (x > 0) {
      while (x >= S21_PI) {
        x = x - 2 * S21_PI;
      }
    } else {
      while (-x >= S21_PI) {
        x = x + 2 * S21_PI;
      }
    }
    int sign = -1;
    long double elem;
    result = x;
    for (int i = 3; i < 20; i += 2) {
      elem = sign * s21_pow(x, i) / s21_fac(i);
      result += elem;
      sign *= -1;
    }
  }
  return result;
}