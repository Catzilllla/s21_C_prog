#include "s21_math.h"

long double s21_acos(double x) {
  long double result;
  if (x == -1) {
    result = S21_PI;
  } else if (x == 1) {
    result = 0;
  } else {
    result = S21_PI / 2 - s21_asin(x);
  }
  return result;
}