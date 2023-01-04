#include "s21_string.h"

void *s21_memset(void *str, int c, S21_SIZE_T n) {
  S21_SIZE_T idx;
  unsigned char *dest = str;
  for (idx = 0; idx < n; idx++, dest++) {
    *dest = (unsigned char)c;
  }
  return (void *)str;
}
/*
int main(void) {
  // char src[] = "******************************";
  // char dest[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  // char dest2[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  // printf("Строка назначения перед копированием: %s\n", dest2);
  // memmove(dest, src, 26);
  // s21_memmove(dest2, src, 26);
  // printf("Строка назначения после копирования оригинал:  %s\n", dest);
  // printf("Строка назначения после копирования мой:       %s\n", dest2);
  char buffer[] = "Hello world\n";
printf("Буфер перед использованием функции memset:%s\n",buffer);
s21_memset(buffer,'*',strlen(buffer) - 1);
printf("Буфер после использования функции memset:%s\n",buffer);
  exit(0);
}
*/