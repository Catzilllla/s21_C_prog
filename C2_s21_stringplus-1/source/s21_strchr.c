// 6. Выполняет поиск первого вхождения символа c(беззнаковый тип) в строке,
//     на которую указывает аргумент str.

#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = (char *)s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
    if (*((char *)str + i) == c) {
      res = (char *)str + i;
      break;
    }
  }
  return res;
}
