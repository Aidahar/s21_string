#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strcat(char *dest, const char *str) {
  s21_size_t idx = s21_strlen(dest);
  s21_size_t last = idx + s21_strlen(str);
  for (; idx < last; idx++, str++) {
    dest[idx] = *str;
  }
  dest[idx] = '\0';
  return dest;
}
