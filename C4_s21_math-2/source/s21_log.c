#include "s21_math.h"

long double s21_log(double x) {
  long double pow = 0, count = 2, result, temp;
  if (S21_IS_INF(x) == 1) {
    result = S21_pINF;
  } else if (S21_IS_INF(x) == -1) {
    result = S21_NAN;
  } else if (x != 1) {
    while ((x >= 10) || (0 < x && x < 1)) {
      if (0 < x && x < 1) {
        x = x * 10;
        pow = pow - 1;
      } else {
        x = x * 0.1;
        pow = pow + 1;
      }
    }
    x /= 10;
    if (x < 0) {
      result = -S21_NAN;
    } else if (x == 0) {
      result = S21_nINF;
    } else {
      x--;
      result = x;
      temp = x;
      while (s21_fabs(result) > S21_EPS10) {
        result = result * -x * (count - 1) / count;
        count = count + 1;
        temp = temp + result;
      }
      result = temp + (pow + 1) * S21_M_LN10;
    }
  }
  return (x == 1) ? 0 : result;
}
