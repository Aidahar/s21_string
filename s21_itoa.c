#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

char *s21_itoa(int num, char *buf);
int cnt_number(int num);
void reverse(char *str);

// int main(void) {
//   int num = -123;
//   char *buf = (char *)malloc(11);
//   s21_itoa(num, buf);
//   printf("before = %d\n", num);
//   reverse(buf);
//   printf("answer = %s\n", buf);
//   num = -1879465020;
//   s21_itoa(num, buf);
//   printf("before = %d\n", num);
//   reverse(buf);
//   printf("answer = %s\n", buf);
//   num = 1879465020;
//   s21_itoa(num, buf);
//   printf("before = %d\n", num);
//   reverse(buf);
//   printf("answer = %s\n", buf);
//   num = 0;
//   s21_itoa(num, buf);
//   printf("before = %d\n", num);
//   reverse(buf);
//   printf("answer = %s\n", buf);
//   free(buf);
//   exit(0);
// }

int cnt_number(int num) {
  int ans = 0;
  if (0 > num) {
    num *= -1;
  }
  while (0 < num) {
    num /= 10;
    ans++;
  }
  return ans;
}

char *s21_itoa(int num, char *buf) {
  char *ans = buf;
  int flag = 0, idx = 0, cnt_n = cnt_number(num);
  char d;
  if (0 > num) {
    flag = 1;
    num *= -1;
  }
  if (0 <= num && 9 >= num) {
    ans[0] = num + 48;
  } else {
    while (cnt_n > idx) {
      d = num % 10;
      ans[idx] = d + 48;
      num /= 10;
      idx++;
    }
    if (flag) {
      ans[idx] = '-';
    }
  }
  return ans;
}

void reverse(char *str) {
  if (str) {
    char tmp;
    int idx = strlen(str) - 1;
    for (int i = 0; i <= idx / 2; i++) {
      tmp = str[i];
      str[i] = str[idx];
      str[idx] = tmp;
      idx--;
    }
  }
}