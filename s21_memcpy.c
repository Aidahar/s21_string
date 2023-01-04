#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, S21_SIZE_T n) {
  S21_SIZE_T idx;
  char *targ = (char *)dest;
  char *from = (char *)src;
  for (idx = 0; idx < n; idx++, targ++, from++) {
    *targ = *from;
  }
  return (void *)dest;
}
/*
int main(void) {
  // char a1[] = "abss";
  // char a2[] = "tabs";
  // printf("dest %s  from src %s ", a1, a2);
  // s21_memcpy(a1, a2, 3);
  // printf("after dest %s from src %s\n", a1, a2);
  int arr2[10] = {8,3,11,61,-22,7,-6,2,13,47};
  int new_arr2[5] = {0};
  printf("Before copying\n");
    for (int i=0; i<5; i++)
    printf("%d ", new_arr2[i]);
  printf("\n");
  s21_memcpy(new_arr2,arr2,sizeof(int)*5);
  printf("After copying\n");
  for (int i=0; i<5; i++)
    printf("%d ", new_arr2[i]);
  printf("\n");

  exit(0);
}
*/