#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, S21_SIZE_T n) {
  S21_SIZE_T idx;
//  if (S21_NULL == dest) dest = S21_NULL;
  char *targ = (char *)malloc(n * sizeof(char));
  const char *from = src;
  for (idx = 0; idx < n; idx++, targ++, from++) {
    *targ = *from;
  }
  dest = targ;
  return (void *)dest;
}

// int main(void) {
//   char src[] = "******************************";
//   char dest[] = "abcdefghijklmnopqrstuvwxyz0123456789";
//   printf("Строка назначения перед копированием: %s\n", dest);
//   memmove(dest, src, 26);
//   printf("Строка назначения после копирования:  %s\n", dest);
//   exit(0);
// }
