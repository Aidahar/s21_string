#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

// int main(void) {
//   int num = -1;
//   char buf[13];
//   s21_itoa(num, buf);
//   printf("before = %d\n", num);
//   printf("answer = %s\n", buf);
//   num = -18;
//   s21_itoa(num, buf);
//   printf("before = %d\n", num);
//   printf("answer = %s\n", buf);
//   num = -123;
//   s21_itoa(num, buf);
//   printf("before = %d\n", num);
//   printf("answer = %s\n", buf);
//   num = -23;
//   s21_itoa(num, buf);
//   printf("before = %d\n", num);
//   printf("answer = %s\n", buf);
//   num = 0;
//   char new[12];
//   s21_itoa(num, new);
//   printf("before = %d\n", num);
//   printf("answer = %s\n", new);
//   exit(0);
// }

void s21_itoa(int num, char *buf) {
  int idx = 0, flag = 0;
  char d;
  if (0 == num) {
    buf[idx] = 48;
  } else {
    if (0 > num) {
      flag = 1;
      num = -num;
    }
    while (0 < num) {
      d = num % 10;
      buf[idx++] = d + 48;
      num /= 10;
    }
    if (flag) {
      buf[idx++] = '-';
    }
    buf[idx] = '\0';
  }
  reverse(buf);
}

void reverse(char *str) {
  if (str) {
    char tmp;
    int i, j;
    for (i = 0, j = s21_strlen(str) - 1; i < j; i++, j--) {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
    }
  }
}