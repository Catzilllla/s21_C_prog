#include "../s21_decimal.h"


void zero_check_my(s21_decimal *decimal) {
  if ((decimal->bits[0] == 0) && (decimal->bits[1] == 0) &&
      (decimal->bits[2] == 0)) {
    decimal->bits[3] = 0;
  }
}

int get_bit_my(unsigned long value, int num) {
  unsigned long check = 0;
  int result = 0;
  check = 1u << num;
  value &= check;
  result = value >> num;
  return result;
}

void set_0_bit(unsigned int *value, int num) {
  unsigned int set = 0;
  set = 1 << num;
  *value &= ~set;
}

void set_1_bit_my(unsigned int *value, int num) {
  unsigned int set = 0;
  set = 1 << num;
  *value |= set;
}

int get_scale_my(s21_decimal value) {
  unsigned int result = 0;
  for (int i = 0; i < 8; i++) {
    if (get_bit_my(value.bits[3], 16 + i)) set_1_bit_my(&result, i);
  }
  return result;
}

void set_scale_my(unsigned int *value, unsigned int num) {
  if (num < 29) {
    for (int i = 0; i < 8; i++) {
      if (get_bit_my(num, i))
        set_1_bit_my(value, 16 + i);
      else
        set_0_bit(value, 16 + i);
    }
  }
}

int check_sign_my(s21_decimal value) {
  int result = 0;
  result = value.bits[3] >> 31;
  return result;
}

void correction_decimal(s21_decimal *dst) {
  for (int i = 0; i < 15; i++) {
    set_0_bit(&dst->bits[3], i);
  }
  for (int i = 22; i < 31; i++) {
    set_0_bit(&dst->bits[3], i);
  }
}

int s21_bits_is_greater(const s21_decimal dst, const s21_decimal src,
                        int num_bit) {
  int result = 0;
  if (dst.bits[num_bit] > src.bits[num_bit]) {
    result = 1;
  } else if (dst.bits[num_bit] == src.bits[num_bit]) {
    result = 2;
  }

  return result;
}

int Multiply_by_ten(s21_decimal *value, unsigned int scale) {
  int scale_of_v = 0;
  scale_of_v = get_scale(*value);
  uint64_t number = 0;
  unsigned int remainder = 0;
  uint64_t max = MaxUint;
  int check = 0;
  unsigned int tmp = 0;
  uint64_t bits = 0;
  while ((scale > 0) && (scale_of_v < 29)) {
    for (int i = 0; i < 3; i++) {
      bits += value->bits[i];
      bits *= 10;
      bits += number;
      remainder += bits >> 32;
      bits &= max;
      value->bits[i] = bits;
      bits = 0;
      number = remainder;
      remainder = 0;
    }
    if (remainder != 0) {
      check = 1;
      break;
    } else {
      scale_of_v++;
      tmp = value->bits[3];
      set_scale_my(&tmp, scale_of_v);
      value->bits[3] = tmp;
      scale--;
    }
  }
  return check;
}

int equalize_scale(s21_decimal *value_1, s21_decimal *value_2) {
  int scale_of_v1 = 0;
  int scale_of_v2 = 0;
  scale_of_v1 = get_scale_my(*value_1);
  scale_of_v2 = get_scale_my(*value_2);
  unsigned int result_scale = 0;
  int check = 0;
  s21_decimal tmp = {0};
  if (scale_of_v1 > scale_of_v2) {
    result_scale = scale_of_v1 - scale_of_v2;
    tmp = *value_2;
    check = Multiply_by_ten(&tmp, result_scale);
    if (!check) *value_2 = tmp;
  } else {
    result_scale = scale_of_v2 - scale_of_v1;
    tmp = *value_1;
    check = Multiply_by_ten(&tmp, result_scale);
    if (!check) *value_1 = tmp;
  }
  return check;
}

void free_mas(char *string) {
  for (size_t i = 0; i < strlen(string); i++) {
    string[i] = '\0';
  }
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  void *p = NULL;

  static insert_strings a = {0};
  if (start_index == strlen(src)) {
    strcpy(a.buf[a.pointer], src);
  } else if (start_index & 1 << 31) {
    start_index *= -1;
    a.buf[a.pointer][0] = '0';
    a.buf[a.pointer][1] = '.';
    strcat(a.buf[a.pointer], src);
  } else {
    for (size_t i = 0; i < start_index; i++) {
      a.buf[a.pointer][i] = src[i];
    }
    strcat(a.buf[a.pointer], str);
    for (size_t i = start_index, j = strlen(a.buf[a.pointer]); i < strlen(src);
         i++, j++) {
      a.buf[a.pointer][j] = src[i];
    }
  }

  return p = &a.buf[a.pointer++];
}

void *decimal_to_str(s21_decimal src) {
  int degree = 0;
  long double buf = 0;
  static char decimal_string[37] = {0};
  free_mas(decimal_string);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      if (get_bit_my(src.bits[i], j)) {
        buf += pow(2, degree);
      }
      degree++;
    }
  }

  sprintf(decimal_string, "%Lf", buf);

  for (size_t i = 0; i < strlen(decimal_string); i++) {
    if (decimal_string[i] == '.') {
      for (size_t j = i; j < strlen(decimal_string); j++) {
        decimal_string[j] = '\0';
      }
    }
  }

  void *p = NULL;

  p = s21_insert(decimal_string, ".", strlen(decimal_string) - get_scale_my(src));

  return p;
}