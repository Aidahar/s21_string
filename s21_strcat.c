#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

char *s21_strcat(char *dest, const char *str) {
  char *tmp = dest;
  s21_size_t idx = s21_strlen(dest);
  s21_size_t last = idx + s21_strlen(str);
  for (; idx < last; idx++, str++) {
    tmp[idx] = *str;
  }
  return tmp;
}

int main(void) {
  char dest[90] = "Learning C++ is fun";
  char src[90] = " and easy";
  char *nums = " 20";
  s21_strcat(dest, src);
  printf("%s\n", dest);
  s21_strcat(dest, nums);
  printf("%s\n", dest);
  exit(0);
}