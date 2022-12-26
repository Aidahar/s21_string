#include <check.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	char *a1 = "abss";
	char *a2 = "tabs";
	ck_assert_int_ge(s21_memcmp(a1, a2, 3), memcmp(a1, a2, 3));
	a1 = "tabs";
	a2 = "abss";
	ck_assert_int_le(s21_memcmp(a1, a2, 3), memcmp(a1, a2, 3));
	a1 = "abss";
	a2 = "abss";
	ck_assert_int_le(s21_memcmp(a1, a2, 3), memcmp(a1, a2, 3));
}
END_TEST

Suite *s21_string_suit(void) {
	Suite *s;
	s = suite_create("String.h functions");

	TCase *tc_memchr;
	TCase *tc_memcmp;

	tc_memchr = tcase_create("memchr");
	suite_add_tcase(s, tc_memchr);
	tcase_add_test(tc_memchr, s21_memchr_my);

	tc_memcmp = tcase_create("memcmp");
	suite_add_tcase(s, tc_memcmp);
	tcase_add_test(tc_memcmp, s21_memcmp_my);


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
