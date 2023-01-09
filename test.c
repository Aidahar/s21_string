#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_memchr_my) {
  char data[] = {'q', 'r', 's', 't', 'p', 'a', 'x'};
  char *my_ans = s21_memchr(data, 'r', 5);
  char *real_ans = memchr(data, 'r', 5);
  ck_assert_msg(my_ans, real_ans, 0, 0);
  ck_assert_msg(s21_memchr(data, 'r', 1), memchr(data, 'r', 1), 0, 0);
  ck_assert_msg(s21_memchr(data, 'z', 1), memchr(data, 'z', 1), 0, 0);
  ck_assert_ptr_null(s21_memchr(data, 'z', 0));
}
END_TEST

START_TEST(s21_memcmp_my) {
  /* test string */
  char *memcmp_a1 = "abss";
  char *memcmp_a2 = "aabs";
  ck_assert_int_ge(s21_memcmp(memcmp_a1, memcmp_a2, 4),
                   memcmp(memcmp_a1, memcmp_a2, 4));
  ck_assert_int_eq(s21_memcmp(memcmp_a1, memcmp_a2, 1),
                   memcmp(memcmp_a1, memcmp_a2, 1));
  ck_assert_int_ge(s21_memcmp(memcmp_a1, memcmp_a2, 2),
                   memcmp(memcmp_a1, memcmp_a2, 2));
  ck_assert_int_ge(s21_memcmp(memcmp_a1, memcmp_a2, 5),
                   memcmp(memcmp_a1, memcmp_a2, 5));
  memcmp_a1 = "aabs";
  memcmp_a2 = "abss";
  ck_assert_int_le(s21_memcmp(memcmp_a1, memcmp_a2, 4),
                   memcmp(memcmp_a1, memcmp_a2, 4));
  ck_assert_int_eq(s21_memcmp(memcmp_a1, memcmp_a2, 1),
                   memcmp(memcmp_a1, memcmp_a2, 1));
  ck_assert_int_le(s21_memcmp(memcmp_a1, memcmp_a2, 2),
                   memcmp(memcmp_a1, memcmp_a2, 2));
  ck_assert_int_le(s21_memcmp(memcmp_a1, memcmp_a2, 5),
                   memcmp(memcmp_a1, memcmp_a2, 5));
  memcmp_a1 = "aaaaa";
  memcmp_a2 = "aaaaa";
  ck_assert_int_eq(s21_memcmp(memcmp_a1, memcmp_a2, 4),
                   memcmp(memcmp_a1, memcmp_a2, 4));
  ck_assert_int_eq(s21_memcmp(memcmp_a1, memcmp_a2, 1),
                   memcmp(memcmp_a1, memcmp_a2, 1));
  ck_assert_int_eq(s21_memcmp(memcmp_a1, memcmp_a2, 2),
                   memcmp(memcmp_a1, memcmp_a2, 2));
  ck_assert_int_eq(s21_memcmp(memcmp_a1, memcmp_a2, 6),
                   memcmp(memcmp_a1, memcmp_a2, sizeof(char) * 6));
  /* test numbers array */
  int s1[] = {1, 2, 3, 4};
  int s2[] = {1, 2, 6, 4};
  ck_assert_int_ge(s21_memcmp(s1, s2, sizeof(int) * 3),
                   memcmp(s1, s2, sizeof(int) * 3));
  ck_assert_int_eq(s21_memcmp(s1, s2, sizeof(int) * 2),
                   memcmp(s1, s2, sizeof(int) * 2));
  ck_assert_int_ge(s21_memcmp(s1, s2, sizeof(int) * 4),
                   memcmp(s1, s2, sizeof(int) * 4));
  int s3[] = {1, 2, 6, 4};
  int s4[] = {1, 2, 3, 4};
  ck_assert_int_le(s21_memcmp(s3, s4, sizeof(int) * 3),
                   memcmp(s3, s4, sizeof(int) * 3));
  ck_assert_int_eq(s21_memcmp(s3, s4, sizeof(int) * 2),
                   memcmp(s3, s4, sizeof(int) * 2));
  ck_assert_int_le(s21_memcmp(s3, s4, sizeof(int) * 4),
                   memcmp(s3, s4, sizeof(int) * 4));
}
END_TEST

START_TEST(s21_memcpy_my) {
  char memcpy_my1[] = "abss";
  char memcpy_my2[] = "tabs";
  char memcpy_real1[] = "abss";
  char memcpy_real2[] = "tabs";
  ck_assert_str_eq(s21_memcpy(memcpy_my1, memcpy_my2, 3),
                   memcpy(memcpy_real1, memcpy_real2, 3));
  /* test number array */
  int my_arr[10] = {8, 3, 11, 61, -22, 7, -6, 2, 13, 47};
  int new_arr_my[5] = {0};
  int new_arr_origin[5] = {0};
  s21_memcpy(new_arr_my, my_arr, 5);
  memcpy(new_arr_origin, my_arr, 5);
  for (int idx = 0; idx < 5; idx++) {
    ck_assert_int_eq(new_arr_my[idx], new_arr_origin[idx]);
  }
}
END_TEST

START_TEST(s21_memmove_my) {
  char a_my[] = "abss";
  char a_origin[] = "abss";
  char memmov_a2[] = "tabs";
  s21_memmove(a_my, memmov_a2, 3);
  memmove(a_origin, memmov_a2, 3);
  ck_assert_str_eq(a_my, a_origin);
  char a_my_2[] = "******************************";
  char a_origin_2[] = "******************************";
  char memmove_a4[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  s21_memmove(a_my_2, memmove_a4, 26);
  memmove(a_origin_2, memmove_a4, 26);
  ck_assert_str_eq(a_my, a_origin);
}
END_TEST

START_TEST(s21_memset_my) {
  char str_my[] = "This is a test of the memset function";
  char str_origin[] = "This is a test of the memset function";
  s21_memset(str_my, '*', 5);
  memset(str_origin, '*', 5);
  ck_assert_str_eq(str_my, str_origin);
  char str_my_2[] = "tabs";
  char str_origin_2[] = "tabs";
  s21_memset(str_my_2, 'a', 1);
  memset(str_origin_2, 'a', 1);
  char str_my_3[] = "******************************";
  char str_origin_3[] = "******************************";
  ck_assert_str_eq(s21_memset(str_my_3, 'g', 20),
                   memset(str_origin_3, 'g', 20));
}
END_TEST

START_TEST(s21_strlen_my) {
  char my_strlen_a1[] = "This is a test of the memset function";
  ck_assert_int_eq(s21_strlen(my_strlen_a1), strlen(my_strlen_a1));
  char my_strlen_a2[] = "tabs";
  ck_assert_int_eq(s21_strlen(my_strlen_a2), strlen(my_strlen_a2));
  char my_strlen_a3[] = "******************************";
  ck_assert_int_eq(s21_strlen(my_strlen_a3), strlen(my_strlen_a3));
}
END_TEST

START_TEST(s21_itoa_my) {
  char *itoa_a1 = calloc(sizeof(char), 12);
  char *itoa_a2 = "2093923010";
  int i = 2093923010;
  s21_itoa(i, itoa_a1);
  ck_assert_str_eq(itoa_a1, itoa_a2);
  free(itoa_a1);
  itoa_a1 = calloc(sizeof(char), 12);
  i = 0;
  itoa_a2 = "0";
  s21_itoa(i, itoa_a1);
  ck_assert_str_eq(itoa_a1, itoa_a2);
  free(itoa_a1);
  itoa_a1 = calloc(sizeof(char), 12);
  i = 8;
  itoa_a2 = "8";
  s21_itoa(i, itoa_a1);
  ck_assert_str_eq(itoa_a1, itoa_a2);
  free(itoa_a1);
  itoa_a1 = calloc(sizeof(char), 12);
  i = -5;
  itoa_a2 = "-5";
  s21_itoa(i, itoa_a1);
  ck_assert_str_eq(itoa_a1, itoa_a2);
  free(itoa_a1);
  itoa_a1 = calloc(sizeof(char), 12);
  i = -583746278;
  itoa_a2 = "-583746278";
  s21_itoa(i, itoa_a1);
  ck_assert_str_eq(itoa_a1, itoa_a2);
  free(itoa_a1);
  itoa_a1 = calloc(sizeof(char), 12);
  i = -5;
  itoa_a2 = "-5";
  s21_itoa(i, itoa_a1);
  ck_assert_str_eq(itoa_a1, itoa_a2);
  free(itoa_a1);
}
END_TEST

START_TEST(s21_strcat_my) {
  // char *my_cat_a1 = (char *)calloc(100, sizeof(char));
  // my_cat_a1 = "This is a test of the memset function";
  // char *my_cat_a2 = (char *)calloc(7, sizeof(char));
  // my_cat_a2 = " lalala";
  // char *real_cat_a1 = (char *)calloc(100, sizeof(char));
  // real_cat_a1 = "This is a test of the memset function";
  // char *real_cat_a2 = (char *)calloc(7, sizeof(char));
  // real_cat_a2 = " lalala";
  // // char real_cat_a1[40] = "This is a test of the memset function";
  // // char real_cat_a2[10] = " lalala";
  // s21_strcat(my_cat_a1, my_cat_a2);
  // strcat(real_cat_a1, real_cat_a2);
  // ck_assert_str_eq(my_cat_a1, real_cat_a1);
  char my_cat_b1[256] = " lalala";
  char my_cat_b2[] = "This is a test of the memset function";
  char real_cat_b1[256] = " lalala";
  char real_cat_b2[] = "This is a test of the memset function";
  s21_strcat(my_cat_b1, my_cat_b2);
  strcat(real_cat_b1, real_cat_b2);
  ck_assert_str_eq(my_cat_b1, real_cat_b1);
  char my_cat_a1[50] = " lalala";
  char my_cat_a2[] = "This is a test of the memset function";
  char real_cat_a1[50] = " lalala";
  char real_cat_a2[] = "This is a test of the memset function";
  s21_strcat(my_cat_a1, my_cat_a2);
  strcat(real_cat_a1, real_cat_a2);
  ck_assert_str_eq(my_cat_a1, real_cat_a1);
}
END_TEST

START_TEST(s21_strchr_my) {
  char str[] = "My name is Ayush Belbek";
  char *my_ch = s21_strchr(str, 'a');
  char *real_ch = strchr(str, 'a');
  ck_assert_int_eq((my_ch - str + 1), (real_ch - str + 1));
  char ch1 = 'A', ch2 = 'z', ch3 = '\0';
  char *ans_my = s21_strchr(str, ch1);
  char *ans_real = strchr(str, ch1);
  ck_assert_str_eq(ans_my, ans_real);
  char *ans_my_2 = s21_strchr(str, ch2);
  char *ans_real_2 = strchr(str, ch2);
  ck_assert_ptr_null(ans_my_2);
  ck_assert_ptr_null(ans_real_2);
  char *ans_my_3 = s21_strchr(str, ch3);
  char *ans_real_3 = strchr(str, ch3);
  ck_assert_str_eq(ans_my_3, ans_real_3);
}
END_TEST

START_TEST(s21_strcmp_my) {
  char *strcmp_s1 = "Hello";
  char *strcmp_s2 = "Aticleworld";
  ck_assert_int_eq(s21_strcmp(strcmp_s1, strcmp_s2),
                   strcmp(strcmp_s1, strcmp_s2));
  char *strcmp_a1 = "Aticleworld";
  char *strcmp_a2 = "Aticleworld";
  ck_assert_int_eq(s21_strcmp(strcmp_a1, strcmp_a2),
                   strcmp(strcmp_a1, strcmp_a2));
  char *strcmp_b1 = "Aticleworld";
  char *strcmp_b2 = "Hello";
  ck_assert_int_eq(s21_strcmp(strcmp_b1, strcmp_b2),
                   strcmp(strcmp_b1, strcmp_b2));
  char *strcmp_c1 = "";
  char *strcmp_c2 = "";
  ck_assert_int_eq(s21_strcmp(strcmp_c1, strcmp_c2),
                   strcmp(strcmp_c1, strcmp_c2));
}
END_TEST

START_TEST(s21_strerror_my) {
#ifdef __APPLE__
  ck_assert_str_eq(strerror(0), s21_strerror(0));
  ck_assert_str_eq(strerror(-11), s21_strerror(-11));
  ck_assert_pstr_eq(strerror(106), s21_strerror(106));
  ck_assert_pstr_eq(strerror(109), s21_strerror(109));
#elif __linux__  
  int idx = 0;
  for (int idx = -11; idx < 159; idx++) {
    ck_assert_str_eq(strerror(idx), s21_strerror(idx));
  }
#endif
}
END_TEST

START_TEST(s21_strpbrk_my) {
  char pbrk_str1[] = "abcde2fghi3jk4lasd";
  char pbrk_str2[] = "34";
  char pbrk_str3[] = "d";
  char pbrk_str4[] = "";
  char pbrk_str5[] = "";
  char *pbrk_ret;
  char *pbrk_my_ret;

  pbrk_ret = strpbrk(pbrk_str1, pbrk_str2);
  pbrk_my_ret = s21_strpbrk(pbrk_str1, pbrk_str2);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str2, pbrk_str1);
  pbrk_my_ret = s21_strpbrk(pbrk_str2, pbrk_str1);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str1, pbrk_str3);
  pbrk_my_ret = s21_strpbrk(pbrk_str1, pbrk_str3);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str3, pbrk_str1);
  pbrk_my_ret = s21_strpbrk(pbrk_str3, pbrk_str1);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str1, pbrk_str4);
  pbrk_my_ret = s21_strpbrk(pbrk_str1, pbrk_str4);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str4, pbrk_str5);
  pbrk_my_ret = s21_strpbrk(pbrk_str4, pbrk_str5);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str4, pbrk_str1);
  pbrk_my_ret = s21_strpbrk(pbrk_str4, pbrk_str1);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
}
END_TEST

Suite *s21_string_suit(void) {
  Suite *s;
  s = suite_create("String.h functions");

  TCase *tc_itoa;
  TCase *tc_memchr;
  TCase *tc_memcmp;
  TCase *tc_memcpy;
  TCase *tc_memmove;
  TCase *tc_memset;
  TCase *tc_strlen;
  TCase *tc_strcat;
  TCase *tc_strchr;
  TCase *tc_strcmp;
  TCase *tc_strerror;
  TCase *tc_strpbrk;

  tc_memchr = tcase_create("memchr");
  suite_add_tcase(s, tc_memchr);
  tcase_add_test(tc_memchr, s21_memchr_my);

  tc_memcmp = tcase_create("memcmp");
  suite_add_tcase(s, tc_memcmp);
  tcase_add_test(tc_memcmp, s21_memcmp_my);

  tc_memcpy = tcase_create("memcpy");
  suite_add_tcase(s, tc_memcpy);
  tcase_add_test(tc_memcpy, s21_memcpy_my);

  tc_memmove = tcase_create("memmove");
  suite_add_tcase(s, tc_memmove);
  tcase_add_test(tc_memmove, s21_memmove_my);

  tc_memset = tcase_create("memset");
  suite_add_tcase(s, tc_memset);
  tcase_add_test(tc_memset, s21_memset_my);

  tc_strlen = tcase_create("strlen");
  suite_add_tcase(s, tc_strlen);
  tcase_add_test(tc_strlen, s21_strlen_my);

  tc_itoa = tcase_create("itoa");
  suite_add_tcase(s, tc_itoa);
  tcase_add_test(tc_itoa, s21_itoa_my);

  tc_strcat = tcase_create("strcat");
  suite_add_tcase(s, tc_strcat);
  tcase_add_test(tc_strcat, s21_strcat_my);

  tc_strchr = tcase_create("strchr");
  suite_add_tcase(s, tc_strchr);
  tcase_add_test(tc_strchr, s21_strchr_my);

  tc_strcmp = tcase_create("strcmp");
  suite_add_tcase(s, tc_strcmp);
  tcase_add_test(tc_strcmp, s21_strcmp_my);

  tc_strerror = tcase_create("strerror");
  suite_add_tcase(s, tc_strerror);
  tcase_add_test(tc_strerror, s21_strerror_my);

  tc_strpbrk = tcase_create("strpbrk");
  suite_add_tcase(s, tc_strpbrk);
  tcase_add_test(tc_strpbrk, s21_strpbrk_my);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_string_suit();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (0 == number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}
