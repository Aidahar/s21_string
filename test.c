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
  char *a1 = "abss";
  char *a2 = "aabs";
  ck_assert_int_ge(s21_memcmp(a1, a2, 4), memcmp(a1, a2, 4));
  ck_assert_int_eq(s21_memcmp(a1, a2, 1), memcmp(a1, a2,1));
  ck_assert_int_ge(s21_memcmp(a1, a2, 2), memcmp(a1, a2, 2));
  ck_assert_int_ge(s21_memcmp(a1, a2, 5), memcmp(a1, a2, 5));
  a1 = "aabs";
  a2 = "abss";
  ck_assert_int_le(s21_memcmp(a1, a2, 4), memcmp(a1, a2, 4));
  ck_assert_int_eq(s21_memcmp(a1, a2, 1), memcmp(a1, a2,1));
  ck_assert_int_le(s21_memcmp(a1, a2, 2), memcmp(a1, a2, 2));
  ck_assert_int_le(s21_memcmp(a1, a2, 5), memcmp(a1, a2, 5));
  a1 = "aaaaa";
  a2 = "aaaaa";
  ck_assert_int_eq(s21_memcmp(a1, a2, 4), memcmp(a1, a2, 4));
  ck_assert_int_eq(s21_memcmp(a1, a2, 1), memcmp(a1, a2,1));
  ck_assert_int_eq(s21_memcmp(a1, a2, 2), memcmp(a1, a2, 2));
  ck_assert_int_eq(s21_memcmp(a1, a2, 6), memcmp(a1, a2, sizeof(char)*6));
  /* test numbers array */
  int s1[] = {1, 2, 3, 4};
  int s2[] = {1, 2, 6, 4};
  ck_assert_int_ge(s21_memcmp(s1, s2, sizeof(int)*3), memcmp(s1, s2, sizeof(int)*3));
  ck_assert_int_eq(s21_memcmp(s1, s2, sizeof(int)*2), memcmp(s1, s2, sizeof(int)*2));
  ck_assert_int_ge(s21_memcmp(s1, s2, sizeof(int)*4), memcmp(s1, s2, sizeof(int)*4));
  int s3[] = {1, 2, 6, 4};
  int s4[] = {1, 2, 3, 4};
  ck_assert_int_le(s21_memcmp(s3, s4, sizeof(int)*3), memcmp(s3, s4, sizeof(int)*3));
  ck_assert_int_eq(s21_memcmp(s3, s4, sizeof(int)*2), memcmp(s3, s4, sizeof(int)*2));
  ck_assert_int_le(s21_memcmp(s3, s4, sizeof(int)*4), memcmp(s3, s4, sizeof(int)*4));
}
END_TEST

START_TEST(s21_memcpy_my) {
  char a1[] = "abss";
  char a2[] = "tabs";
  ck_assert_msg(s21_memcpy(a1, a2, 3), memcpy(a1, a2, 3));
}
END_TEST

START_TEST(s21_memmove_my) {
  char a1[] = "abss";
  char a2[] = "tabs";
  ck_assert_msg(s21_memmove(a1, a2, 3), memmove(a1, a2, 3));
  char a3[] = "******************************";
  char a4[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  ck_assert_msg(s21_memmove(a3, a4, 26), memmove(a3, a4, 26));

}
END_TEST

START_TEST(s21_memset_my) {
  char a1[] = "This is a test of the memset function";
  ck_assert_msg(s21_memset(a1, '*', 4), memset(a1, '*', 4));
  char a2[] = "tabs";
  ck_assert_msg(s21_memset(a1, 'a', 1), memset(a1, 'a', 1));
  char a3[] = "******************************";
  ck_assert_msg(s21_memset(a3, 'g', 20), memset(a3, 'g', 20));

}
END_TEST

START_TEST(s21_strlen_my) {
  char a1[] = "This is a test of the memset function";
  ck_assert_int_eq(s21_strlen(a1), strlen(a1));
  char a2[] = "tabs";
  ck_assert_int_eq(s21_strlen(a1), strlen(a1));
  char a3[] = "******************************";
  ck_assert_int_eq(s21_strlen(a3), strlen(a3));

}
END_TEST


Suite *s21_string_suit(void) {
  Suite *s;
  s = suite_create("String.h functions");

  TCase *tc_memchr;
  TCase *tc_memcmp;
  TCase *tc_memcpy;
  TCase *tc_memmove;
  TCase *tc_memset;
  TCase *tc_strlen;

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

  tc_memset= tcase_create("memset");
  suite_add_tcase(s, tc_memset);
  tcase_add_test(tc_memset, s21_memset_my);

  tc_strlen = tcase_create("strlen");
  suite_add_tcase(s, tc_strlen);
  tcase_add_test(tc_strlen, s21_strlen_my);


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
