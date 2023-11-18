#include "s21_math.h"

double s21_fac(int);

long double s21_asin(double x) {
  long double result;
  int sign = (x > 0) ? 1 : -1;
  x = s21_fabs(x);
  if (x < -1 || 1 < x) {
    result = S21_NAN;
  } else if (x == 1) {
    result = S21_PI / 2;
  } else if (x > 0.5) {
    result = S21_PI / 2 - 2 * s21_asin(s21_sqrt((1 - x) / 2));
  } else {
    result = 0;
    long double elem = 1;
    int i = 0;
    while (elem > S21_EPS10 && i < 80) {
      elem = s21_pow(x, 2 * i + 1) * s21_fac(2 * i) /
             (s21_pow(4, i) * s21_fac(i) * s21_fac(i) * (2 * i + 1));
      result += elem;
      i++;
    }
  }
  return sign * result;
}