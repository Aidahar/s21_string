#include "s21_string.h"

char *s21_strcat(char *dest, const char *str) {
  S21_SIZE_T idx = s21_strlen(dest);
  for (; *str != '\0'; idx++, str++) {
    dest[idx] = *str;
  }
  dest[idx] = '\0';
  return dest;
}

// int main(void) {
//   // char a1[40] = "This ";
//   // char a2[12] = "lalala";
//   // char my_cat_a1[] = "This is a test of the memset function";
//   // char my_cat_a2[] = " lalala";
//   // char real_cat_a1[] = "This is a test of the memset function";
//   // char real_cat_a2[] = " lalala";
//   // s21_strcat(my_cat_a1, my_cat_a2);
//   // strcat(real_cat_a1, real_cat_a2);
//   // printf("Real = %s\nMy   = %s\n", my_cat_a1, real_cat_a1);
//   char my_cat_b1[50] = " lalala";
//   char my_cat_b2[37] = "This is a test of the memset function";
//   char real_cat_b1[50] = " lalala";
//   char real_cat_b2[37] = "This is a test of the memset function";
//   s21_strcat(my_cat_b1, my_cat_b2);
//   strcat(real_cat_b1, real_cat_b2);
//   printf("Real = %s\nMy   = %s\n", my_cat_b1, real_cat_b1);
//   printf("my %ld real = %ld\n", strlen(my_cat_b1), strlen(real_cat_b1));

//   char my_cat_c1[256] = " lalala";
//   char my_cat_c2[50] = "This is a test of the memset function";
//   char real_cat_c1[256] = " lalala";
//   char real_cat_c2[50] = "This is a test of the memset function";
//   s21_strcat(my_cat_c1, my_cat_c2);
//   strcat(real_cat_c1, real_cat_c2);
//   printf("Real =%s\nMy   =%s\n", real_cat_c1, my_cat_c1);

//   char src[50], dest[50];

//   s21_memcpy(src, "This is source", 16);
//   s21_memcpy(dest, "This is destination, ", 22);

//   s21_strcat(dest, src);

//   printf("Final destination string : |%s|", dest);

//   char *str = (char *)calloc(100, 1);

//   s21_strcat(str, "Techie ");
//   s21_strcat(str, "Delight ");
//   s21_strcat(str, "– ");
//   s21_strcat(str, "Ace ");
//   s21_strcat(str, "the ");
//   s21_strcat(str, "Technical ");
//   s21_strcat(str, "Interviews");
//   printf("%s", str);
//   free(str);
//   exit(0);
// }