#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int ans = 0;
  S21_SIZE_T idx;
  const unsigned char *lh = (unsigned char *)str1;
  const unsigned char *rh = (unsigned char *)str2;
  for (idx = 0; idx < s21_strlen(str1); idx++, lh++, rh++) {
    if (*lh < *rh) {
      ans = *lh - *rh;
      break;
    } else if (*lh > *rh) {
      ans = *lh - *rh;
      break;
    }
  }
  return ans;
}

// int main(void) {
//   char *s1 = "Hello";
//   char *s2 = "Aticleworld";
//   int ans = s21_strcmp(s1, s2), real_ans = strcmp(s1, s2);
//   printf("ans = %d real_ans = %d\n", ans, real_ans);
//   char *a1 = "Aticleworld";
//   char *a2 = "Aticleworld";
//   ans = s21_strcmp(a1, a2), real_ans = strcmp(a1, a2);
//   printf("ans = %d real-ans = %d\n", ans, real_ans);
//   char *b1 = "Aticleworld";
//   char *b2 = "Hello";
//   ans = s21_strcmp(b1, b2), real_ans = strcmp(b1, b2);
//   printf("ans = %d real-ans = %d\n", ans, real_ans);

//   exit(0);
// }