#include "s21_string.h"

char *s21_strcat(char *dest, const char *str) {
  S21_SIZE_T idx = s21_strlen(dest);
  S21_SIZE_T last = idx + s21_strlen(str);
  for (; idx < last; idx++, str++) {
    dest[idx] = *str;
  }
  dest[idx] = '\0';
  return dest;
}
