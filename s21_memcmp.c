#include "s21_string.h"
#include <string.h>

int s21_memcmp(const void *str1, const void *str2, S21_SIZE_T n) {
  int ans = 0;
  S21_SIZE_T idx;
  const unsigned char *lh = str1;
  const unsigned char *rh = str2;
  for (idx = 0; idx < n; idx++, lh++, rh++) {
    if (*lh < *rh) {
      ans = -1;
      break;
    } else if (*lh > *rh) {
      ans = 1;
      break;
    }
  }
  return ans;
}
/*
int main(void) {
  // char *a1 = "abss";
  // char *a2 = "aabs";
  // // printf("CHECH string a1 = %s a2 = %s\n", a1, a2);
  // // printf("My = %d, real = %d num = 4\n", s21_memcmp(a1, a2, 4), memcmp(a1, a2, 4));
  // // printf("My = %d, real = %d num = 1\n", s21_memcmp(a1, a2, 1), memcmp(a1, a2, 1));
  // // printf("My = %d, real = %d num = 2\n", s21_memcmp(a1, a2, 2), memcmp(a1, a2, 2));
  // // printf("My = %d, real = %d num = 5\n", s21_memcmp(a1, a2, 5), memcmp(a1, a2, 5));
  // a1 = "aabs";
  // a2 = "abss";
  // printf("CHECH string a1 = %s a2 = %s\n", a1, a2);
  // printf("My = %d, real = %d num = 4\n", s21_memcmp(a1, a2, 4), memcmp(a1, a2, 4));
  // printf("My = %d, real = %d num = 1\n", s21_memcmp(a1, a2, 1), memcmp(a1, a2, 1));
  // printf("My = %d, real = %d num = 2\n", s21_memcmp(a1, a2, 2), memcmp(a1, a2, 2));
  // printf("My = %d, real = %d num = 5\n", s21_memcmp(a1, a2, 5), memcmp(a1, a2, 5));
  // a1 = "aabs";
  // a2 = "aabs";
  // printf("CHECH string a1 = %s a2 = %s\n", a1, a2);
  // printf("My = %d real = %d\n", s21_memcmp(a1, a2, 4), memcmp(a1, a2, 4));
  // printf("My = %d, real = %d num = 1\n", s21_memcmp(a1, a2, 1), memcmp(a1, a2, 1));
  // printf("My = %d, real = %d num = 2\n", s21_memcmp(a1, a2, 2), memcmp(a1, a2, 2));
  // printf("My = %d, real = %d num = 5\n", s21_memcmp(a1, a2, 5), memcmp(a1, a2, 5));
  printf("Numbers\n");
  int n1[] = {1, 2, 6, 4};
  int n2[] = {1, 2, 3, 4};
  printf("My = %d, real = %d\n", s21_memcmp(n1, n2, sizeof(int)*3), memcmp(n1, n2, sizeof(int)*3));
  printf("My = %d real = %d\n", s21_memcmp(n1, n2, sizeof(int)*2),  memcmp(n1, n2, sizeof(int)*2));
  printf("My = %d, real = %d\n", s21_memcmp(n1, n2, sizeof(int)*4), memcmp(n1, n2, sizeof(int)*4));
  int s1[] = {1, 2, 3, 4};
  int s2[] = {1, 2, 6, 4};
  printf("My = %d, real = %d\n", s21_memcmp(s1, s2, sizeof(int)*3), memcmp(s1, s2, sizeof(int)*3));
  printf("My = %d real = %d\n", s21_memcmp(s1, s2, sizeof(int)*2),  memcmp(s1, s2, sizeof(int)*2));
  printf("My = %d, real = %d\n", s21_memcmp(s1, s2, sizeof(int)*4), memcmp(s1, s2, sizeof(int)*4));
  // int g1[] = {1, 2, 3, 4};
  // int g2[] = {1, 2, 3, 4};
  // printf("My = %d, real = %d\n", s21_memcmp(g1, g2, sizeof(int)*2), memcmp(g1, g2, sizeof(int)*2));
  exit(0);
}
*/