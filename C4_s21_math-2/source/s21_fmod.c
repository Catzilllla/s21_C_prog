#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if (S21_IS_NAN(y) || y == 0 || S21_IS_INF(x)) {
    result = S21_NAN;
  } else if (x == 0) {
    result = 0;
  } else {
    result = s21_fabs(x);
    y = s21_fabs(y);

    while (result >= y) {
      result -= y;
    }
  }
  return result * ((x > 0) ? 1 : -1);
}