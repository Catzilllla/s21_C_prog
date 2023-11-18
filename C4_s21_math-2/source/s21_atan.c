#include "s21_math.h"

long double s21_atan(double x) {
  long double result;
  if (S21_IS_INF(x)) {
    result = S21_IS_INF(x) * S21_PI / 2;
  } else {
    result = s21_asin((x) / (s21_sqrt(1 + x * x)));
  }
  return result;
}