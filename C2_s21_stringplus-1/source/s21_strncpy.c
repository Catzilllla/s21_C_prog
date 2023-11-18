// 8. Копирует до n символов из строки, на которую указывает src, в dest.

#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t copy_len = n <= src_len ? n : (src_len + 1);

  for (s21_size_t i = 0; i < copy_len; i++) {
    dest[i] = src[i];
  }
  return dest;
}
