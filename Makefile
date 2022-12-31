CFLAGS=-Wall -Wextra -Werror -std=c11
GCOV=-fprofile-arcs -ftest-coverage -fPIC
OS=$(shell uname)
ifeq (${OS}, Linux)
    TEST_FLAGS = -lcheck -pthread -lrt -lm -L. -ls21_string
else
    TEST_FLAGS = -lcheck
endif

all: s21_string.a

gcov_report: test
	gcov *.gcda
	gcovr --html-details -o report.html

test: s21_string.a
	gcc test.c -c
	gcc $(CFLAGS) $(TEST_FLAGS) $(GCOV) s21_string.a s21_memset.c s21_memmove.c s21_memcmp.c s21_memchr.c s21_memcpy.c test.o -o test
	./test

s21_string.a: s21_string.o
	ar rc libs21_string.a s21_memchr.o s21_memcmp.o
	ranlib libs21_string.a
	cp libs21_string.a ls21_string.a
	cp libs21_string.a s21_string.a

s21_string.o: s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c
	gcc $(CFLAGS) -c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c

.PHONY: all build clean rebuild

rebuild: clean s21_string.a

rebuild_test: clean test

clean:
	rm -rf *.o *.gch *.dSYM *.gcov *.gcda *.gcno *.a test *.css *.html

