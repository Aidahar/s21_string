#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result;
  if ('\0' == (char)c) {
    while (*str != '\0') {
      str++;
    }
    result = (char *)str;
  } else {
    int flag = 0;
    while (*str != '\0') {
      if (*str == (char)c) {
        result = (char *)str;
        flag = 1;
        break;
      }
      str++;
    }
    if (!flag) {
      result = S21_NULL;
    }
  }
  return result;
}
/*
int main(void) {
  char str[] = "My name is Ayush Belbek";
  char *ch = s21_strchr(str, 'a');
  printf("%ld\n", ch - str + 1);

  char ch1 = 'A', ch2 = 'z', ch3 = '\0';

  char *ans_my = s21_strchr(str, ch1);
  char *ans_real = strchr(str, ch1);
  printf("%c find in %s result %s\n", ch1, str, ans_my);
  printf("%c find in %s result %s\n", ch1, str, ans_real);

  char *ans_my_2 = s21_strchr(str, ch2);
  char *ans_real_2 = strchr(str, ch2);
  printf("%c find in %s\n", ch2, ans_my_2);
  printf("%c find in %s\n", ch2, ans_real_2);

  char *ans_my_3 = s21_strchr(str, ch3);
  char *ans_real_3 = strchr(str, ch3);
  printf("%c find in %s\n", ch3, ans_my_3);
  printf("%c find in %s\n", ch3, ans_real_3);

  exit(0);
}
*/