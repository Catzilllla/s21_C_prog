#include "s21_math.h"

long double s21_ceil(double x) {
  long double result;
  if (S21_IS_NAN(x)) {
    result = S21_NAN;
  } else if (S21_IS_INF(x) == 1) {
    result = S21_pINF;
  } else if (S21_IS_INF(x)) {
    result = S21_nINF;
  } else {
    if (x == (long long int)x) {
      result = x;
    } else {
      result = (long long int)x + ((x > 0) ? 1 : 0);
    }
  }
  return result;
}
