#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, S21_SIZE_T n) {
  S21_SIZE_T idx;
  char *targ = dest;
  const char *from = src;
  for (idx = 0; idx < n; idx++, targ++, from++) {
    *targ = *from;
  }
  return (void *)dest;
}
/*
int main(void) {
  char src[] = "******************************";
  char dest[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  char dest2[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  printf("Строка назначения перед копированием: %s\n", dest2);
  memmove(dest, src, 26);
  s21_memmove(dest2, src, 26);
  printf("Строка назначения после копирования оригинал:  %s\n", dest);
  printf("Строка назначения после копирования мой:       %s\n", dest2);
  exit(0);
}
*/