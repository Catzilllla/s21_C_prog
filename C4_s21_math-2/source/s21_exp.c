#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  long double elem = 1;
  int i = 1;
  int sign = (x > 0) ? 1 : -1;
  x = s21_fabs(x);
  while (S21_EPS15 < elem && elem < S21_MAX_LONG_DOUBLE) {
    elem *= x;
    elem /= i++;
    result += elem;
  }
  if (result > S21_MAX_LONG_DOUBLE && sign != -1) {
    result = S21_pINF;
  } else if (sign == -1) {
    result = 1.0 / result;
  }
  return result;
}
