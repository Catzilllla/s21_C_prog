// 12. Находит первый символ в строке str1, который соответствует любому
// символу, указанному в str2.

#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  for (; *str1 != '\0'; str1++) {
    if (s21_strchr(str2, *str1)) {
      res = (char *)str1;
      break;
    }
  }
  return res;
}
