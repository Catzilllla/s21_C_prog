#include "../s21_decimal.h"

int s21_is_less(s21_decimal left_value, s21_decimal right_value) {
  int sign_left = 0;
  int sign_right = 0;
  int left_bit = 0;
  int right_bit = 0;
  zero_check_my(&left_value);
  zero_check_my(&right_value);
  sign_left = check_sign_my(left_value);
  sign_right = check_sign_my(right_value);
  int result = 0;
  correction_decimal(&left_value);
  correction_decimal(&right_value);
  if (sign_left != sign_right) {
    if (sign_left)
      result = 1;
    else
      result = 0;
  } else {
    equalize_scale(&left_value, &right_value);
    for (int j = 2; j >= 0; j--) {
      for (int i = 31; i >= 0; i--) {
        left_bit = get_bit_my(left_value.bits[j], i);
        right_bit = get_bit_my(right_value.bits[j], i);
        if (right_bit && (right_bit != left_bit)) {
          if (!sign_left)
            result = 1;
          else
            result = 0;
          j = -1;
          break;
        } else if (left_bit && (right_bit != left_bit)) {
          if (!sign_left)
            result = 0;
          else
            result = 1;
          j = -1;
          break;
        } else
          result = 0;
      }
    }
  }
  return result;
}

//===========================================================
//====================== EQUAL ==============================
//===========================================================

int s21_is_equal(s21_decimal dst, s21_decimal src) {
  int cmp_count = 0;
  correction_decimal(&src);
  correction_decimal(&dst);
  if (check_sign_my(dst) != check_sign_my(src)) {
    return 0;
  }
  equalize_scale(&dst, &src);
  for (int i = 0; i < 4; i++) {
    if (s21_bits_is_greater(dst, src, i) == 2) {
      cmp_count++;
    }
  }
  return cmp_count == 4 ? 1 : 0;
}

//===========================================================
//==================== END EQUAL ============================
//===========================================================

int s21_is_less_or_equal(s21_decimal left_value, s21_decimal right_value) {
  int result = 0;
  result = s21_is_equal(left_value, right_value);
  if (!result) result = s21_is_less(left_value, right_value);
  return result;
}

int s21_is_greater_or_equal(s21_decimal left_value, s21_decimal right_value) {
  return !s21_is_less(left_value, right_value);
}

int s21_is_greater(s21_decimal left_value, s21_decimal right_value) {
  return !s21_is_less_or_equal(left_value, right_value);
}

int s21_is_not_equal(s21_decimal dst, s21_decimal src) {
  return s21_is_equal(dst, src) == 0 ? 1 : 0;
}
