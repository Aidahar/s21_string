#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t idx;
  const char *pt = str;
  if (0 == n) {
    pt = s21_NULL;
  } else {
    for (idx = 0; idx < n; idx++, pt++) {
      if (c == *pt) {
        break;
      }
    }
  }
  return (void *)pt;
}
