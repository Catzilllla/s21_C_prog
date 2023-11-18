// 13. Выполняет поиск последнего вхождения символа c (беззнаковый тип) в
// строке, на которую указывает аргумент str.

#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *res = s21_NULL;
  int len = 0;
  while (*str != '\0') {
    str++;
    len++;
  }
  while (len >= 0) {
    if (*str == c) {
      res = str;
      break;
    }
    str--;
    len--;
  }
  return (char *)res;
}
