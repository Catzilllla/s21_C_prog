// 5.1. Возвращает копию строки(str), преобразованной в верхний регистр.В случае
// какой-либо ошибки следует вернуть значение NULL

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = s21_NULL;
  result = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  s21_size_t i = 0;
  for (; i < s21_strlen(str); i++) {
    if (str[i] >= 97 && str[i] <= 122)
      result[i] = str[i] - 32;
    else
      result[i] = str[i];
  }
  result[i] = '\0';
  return (void *)result;
}
