#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
	 int ans = 0;
	 size_t idx;
   const char *lh = str1;
   const char *rh = str2;
	 for(idx = 0; idx <= n; idx++, lh++, rh++) {
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
