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

int main(void) {
  char *a1 = "abss";
  char *a2 = "aabs";
  printf("My = %d, real = %d\n", s21_memcmp(a1, a2, 4), memcmp(a1, a2, 4));
  a1 = "aabs";
  a2 = "abss";
  printf("My = %d, real = %d\n", s21_memcmp(a1, a2, 4), memcmp(a1, a2, 4));
  a1 = "aabs";
  a2 = "aabs";
  printf("My cmp = %d\n", s21_memcmp(a1, a2, 4));
  printf("Real cmp = %d\n", memcmp(a1, a2, 4));
  printf("Numbers\n");
  int n1[] = {1, 2, 6, 4};
  int n2[] = {1, 2, 3, 4};
  printf("My cmp = %d\n", s21_memcmp(n1, n2, sizeof(int)*3));
  printf("Real cmp = %d\n", memcmp(n1, n2, sizeof(int)*3));
  int n3[] = {1, 2, 6, 4};
  int n4[] = {1, 2, 3, 4};
  printf("My = %d real = %d\n", s21_memcmp(n1, n2, sizeof(int)*2),  memcmp(n1, n2, sizeof(int)*2));
  int n5[] = {1, 2, 6, 4};
  int n6[] = {1, 2, 3, 4};
  printf("My cmp = %d\n", s21_memcmp(n1, n2, sizeof(int)*4));
  printf("Real cmp = %d\n", memcmp(n1, n2, sizeof(int)*4));
  int s1[] = {1, 2, 3, 4};
  int s2[] = {1, 2, 6, 4};
  printf("My cmp = %d\n", s21_memcmp(s1, s2, sizeof(int)*3));
  printf("Real cmp = %d\n", memcmp(s1, s2, sizeof(int)*3));
  int g1[] = {1, 2, 3, 4};
  int g2[] = {1, 2, 3, 4};
  printf("My cmp = %d\n", s21_memcmp(g1, g2, sizeof(int)*2));
  printf("Real cmp = %d", memcmp(g1, g2, sizeof(int)*2));
  exit(0);
}
