#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"


void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  s21_size_t idx;
  if (s21_NULL == dest) dest = s21_NULL;
  char *targ = (char *)malloc(n * sizeof(char));
  const char *from = src;
  for (idx = 0; idx < n; idx++, targ++, from++) {
    *targ = *from;
  }
  dest = targ;
  free(targ);
  return (void *)dest;
}

int main(void) {
  char src[] = "******************************";
  char dest[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  printf("Строка назначения перед копированием: %s\n", dest);
  memmove(dest, src, 26);
  printf("Строка назначения после копирования:  %s\n", dest);
  exit(0);
}
