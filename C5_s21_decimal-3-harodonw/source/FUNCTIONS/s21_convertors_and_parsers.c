#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (input_errors_float(src, dst)) {
    return CONVERSION_ERROR;
  }
  if (!src) {
    return CONVERSION_OK;
  }

  reset_decimal(dst);

  unsigned int sign = src < 0;

  int scale = 0;
  // Приведение 7 значимых цифр
  dst->bits[0] = seven_signific(src, &scale);

  // Приведение scale к области от 0 до 28
  unsigned int count_scale = 0;
  while (scale < 0 && count_scale <= MAX_DEGREE) {
    mult_ten(dst);
    ++scale;
    ++count_scale;
  }
  while (scale > MAX_DEGREE) {
    div_ten(dst);
    --scale;
  }

  set_sign(dst, sign);
  set_scale(dst, scale);

  return CONVERSION_OK;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) {
    return CONVERSION_ERROR;
  }

  reset_decimal(dst);
  int sign = src < 0;

  src = abs(src);
  dst->bits[0] = src;

  set_sign(dst, sign);

  return CONVERSION_OK;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  correction_decimal(&src);
  if (get_scale(src) > 28) {
    return OverflowException;
  }

  *dst = 0;
  int bool = 0;

  void *p = NULL;
  p = decimal_to_str(src);
  if (bool == 1) {
    *dst = 0;
  } else
    *dst = atof(p);
  if (src.bits[3] & 1 << 31) {
    *dst *= -1;
  }
  return bool;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) {
    return CONVERSION_ERROR;
  }

  int output = CONVERSION_OK;
  *dst = 0;

  output = s21_truncate(src, &src);

  if (output) {
    return CONVERSION_ERROR;
  }

  if (src.bits[1] || src.bits[2]) {
    output = CONVERSION_ERROR;
  } else {
    if (get_bit(src, BITS_SIZE - 1) && !get_sign(src)) {
      output = CONVERSION_ERROR;
    } else {
      *dst = src.bits[0];
    }
  }

  // if (sign) {*dst = ~(*dst - 1);}
  if (get_sign(src)) {
    *dst = -*dst;
  }
  return output;
}
