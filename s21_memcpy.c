#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t idx;
  if (s21_NULL == dest) dest = s21_NULL;
  char *targ = (char *)dest;
  char *from = (char *)src;
  for (idx = 0; idx < n; idx++, targ++, from++) {
    *targ = *from;
  }
  return (void *)dest;
}

int main(void) { return 0; }