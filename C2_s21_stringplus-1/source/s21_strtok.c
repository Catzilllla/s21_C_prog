// 15. Разбивает строку str на ряд токенов, разделенных delim

#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *nextToken = s21_NULL;
  static char *prevToken = s21_NULL;

  if (str != s21_NULL) {
    nextToken = str;
    prevToken = s21_NULL;
  }

  if (nextToken == s21_NULL || *nextToken == '\0') {
    return s21_NULL;
  }

  char *tokenStart = nextToken;

  while (*tokenStart && s21_strrchr(delim, *tokenStart) != s21_NULL) {
    tokenStart++;
  }

  if (*tokenStart == '\0') {
    nextToken = s21_NULL;
  } else {
    prevToken = tokenStart;
    nextToken = s21_strpbrk(tokenStart, delim);
    if (nextToken != s21_NULL) {
      *nextToken = '\0';
      nextToken++;
    }
  }

  return prevToken;
}
