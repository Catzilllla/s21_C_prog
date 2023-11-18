#include "s21_math.h"

long double s21_pow(double x, double exp) {
  long double result;
  if (!exp || x == 1 || (x == -1 && (exp == S21_pINF || exp == S21_nINF))) {
    result = 1;
  } else if (x == S21_NAN || exp == S21_NAN) {
    result = S21_NAN;
  } else if ((x == S21_pINF && (exp == S21_nINF || exp == -1)) ||
             (x == S21_nINF && (exp == S21_nINF)) ||
             (x == 0 && (exp == S21_pINF || exp == 1)) ||
             (x < 0 && (exp == S21_nINF))) {
    result = 0;
  } else if ((x == S21_nINF && exp == -1) || (x == S21_nNULL && exp == 1)) {
    result = S21_nNULL;
  } else if ((x == S21_pINF && (exp == S21_pINF || exp == 1)) ||
             (x == S21_nINF && exp == S21_pINF) ||
             (x == 0 && (exp == S21_nINF || exp == -1)) ||
             (x < -1 && (exp == S21_pINF))) {
    result = S21_pINF;
  } else if ((x == S21_nINF && exp == 1) || (x == S21_nNULL && exp == -1)) {
    result = S21_nINF;
  } else if ((x == -1 && (exp == 1 && exp == -1))) {
    result = S21_nNULL;
  } else if (exp == (long long int)exp) {
    int not_even_exp = (long long int)exp % 2;
    int sign = (exp > 0) ? 1 : -1;
    exp = s21_fabs(exp);
    result = 1;
    while (result < S21_MAX_LONG_DOUBLE && exp > 0) {
      result *= x;
      exp--;
    }
    if (result >= S21_MAX_LONG_DOUBLE) {
      if (x < 0 && not_even_exp) {
        result = S21_nINF;
      } else {
        result = S21_pINF;
      }
    } else if (sign == -1) {
      result = 1.0 / result;
    }
  } else if (x < 0 || S21_IS_NAN(exp)) {
    result = S21_NAN;
  } else {
    result = s21_exp(exp * s21_log(x));
  }
  return result;
}
