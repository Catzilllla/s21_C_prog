// 5.3. Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *result = s21_NULL;
  if (str != s21_NULL && src != s21_NULL) {
    s21_size_t size = s21_strlen(src) + s21_strlen(str);
    s21_size_t end_index = start_index + s21_strlen(str);
    result = (char *)calloc(size + 1, sizeof(char));
    if (result != s21_NULL && start_index < s21_strlen(src)) {
      for (s21_size_t i = 0; i < start_index; i++) result[i] = src[i];
      for (s21_size_t i = start_index, j = 0; i < end_index; i++, j++)
        result[i] = str[j];
      for (s21_size_t i = end_index, j = start_index; i < size; i++, j++)
        result[i] = src[j];
    } else
      result = s21_NULL;
  }
  return result;
  free(result);
}
