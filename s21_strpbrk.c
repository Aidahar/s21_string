#include "s21_string.h"
#include <string.h>

char *s21_strpbrk(const char *str1, const char *str2) {
    int len1 = s21_strlen(str1), len2 = s21_strlen(str2), flag = 0;
    char *str;
    if ( 0 != len1 && 0 != len2) {
      flag = 1;
      int i;
      for (i = 0; i < len1; i++) {
        int j;
        for (j = 0; j < len2; j++) {
          if (str1[i] == str2[j]) break;
        }
        if (j < len2) break;
      }
      str = (char *)str1 + i;
    }
    return (flag) ? str : S21_NULL;
}

int main(void) {
  char str1[] = "abcde2fghi3jk4lasd";
  char str2[] = "34";
  char str3[] = "d";
  char str4[] = "";
  char str5[] = "";
  char *ret;
  char *my_ret;

  ret = strpbrk(str1, str2);
  my_ret = s21_strpbrk(str1, str2);
  if(ret) {
    printf("First    matching character: %c\n", *ret);
    printf("First my matching character: %c\n", *my_ret);
  } else {
    printf("Character not found");
  }
  ret = strpbrk(str1, str3);
  my_ret = s21_strpbrk(str1, str3);
  if(ret) {
    printf("First    matching character: %c\n", *ret);
    printf("First my matching character: %c\n", *my_ret);
  } else {
    printf("Character not found");
  }
  ret = strpbrk(str3, str1);
  my_ret = s21_strpbrk(str3, str1);
  if(ret) {
    printf("3. First    matching character: %c\n", *ret);
    printf("3. First my matching character: %c\n", *my_ret);
  } else {
    printf("Character not found");
  }

  ret = strpbrk(str1, str4);
  my_ret = s21_strpbrk(str1, str4);
  if(ret) {
    printf("First    matching character: %c\n", *ret);
    printf("First my matching character: %c\n", *my_ret);
  } else {
    printf("4.Character not found %s\n", ret);
    printf("4.Character not found %s\n", my_ret);
  } 
  ret = strpbrk(str4, str5);
  my_ret = s21_strpbrk(str4, str5);
  if(ret) {
    printf("First    matching character: %c\n", *ret);
    printf("First my matching character: %c\n", *my_ret);
  } else {
    printf("5.Character not found %s\n", ret);
    printf("5.Character not found %s\n", my_ret);
  }
  ret = strpbrk(str4, str1);
  my_ret = s21_strpbrk(str4, str1);
  if(ret) {
    printf("First    matching character: %c\n", *ret);
    printf("First my matching character: %c\n", *my_ret);
  } else {
    printf("6. Character not found %s\n", ret);
    printf("6. Character not found %s\n", my_ret);
  }
  exit(0);
}
