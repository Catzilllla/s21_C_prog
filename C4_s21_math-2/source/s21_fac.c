#include "s21_math.h"

double s21_fac(int i) {
  double res = 1;
  for (int j = 1; j <= i; j++) {
    res *= j;
  }
  return res;
}