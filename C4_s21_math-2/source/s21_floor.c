#include "s21_math.h"

long double s21_floor(double x) {
  long double result;
  if (x == (long long int)x) {
    result = x;

  } else {
    result = s21_ceil(x - 1);
  }
  return result;
}