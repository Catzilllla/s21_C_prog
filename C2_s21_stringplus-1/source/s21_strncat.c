// 5. Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.

#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_len = s21_strlen(dest);
  for (s21_size_t i = 0; i < n && i < s21_strlen(src); i++, dest_len++) {
    dest[dest_len] = src[i];
  }
  dest[dest_len] = '\0';

  return dest;
}
