// 9. Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.

#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  for (; i < s21_strlen(str1); i++)
    if (s21_strchr(str2, str1[i])) break;
  return i;
}
