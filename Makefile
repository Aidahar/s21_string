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
	gcc $(CFLAGS) $(TEST_FLAGS) $(GCOV) s21_string.a s21_strcmp.c s21_strchr.c s21_strcat.c s21_itoa.c s21_strlen.c s21_memset.c s21_memmove.c s21_memcmp.c s21_memchr.c s21_memcpy.c s21_strerror.c s21_strpbrk.c test.o -o test
	./test

s21_string.a: s21_string.o
	ar rc libs21_string.a s21_memchr.o s21_memcmp.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_itoa.o s21_memmove.o s21_memset.o s21_strlen.o s21_strcat.o s21_strchr.o s21_strcmp.o s21_strerror.o s21_strpbrk.o
	ranlib libs21_string.a
	cp libs21_string.a ls21_string.a
	cp libs21_string.a s21_string.a

s21_string.o: s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_strlen.c s21_itoa.c s21_strcat.c s21_strchr.c s21_strcmp.c s21_strerror.c s21_strpbrk.c
	gcc $(CFLAGS) -c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_strlen.c s21_itoa.c s21_strcat.c s21_strchr.c s21_strcmp.c s21_strerror.c s21_strpbrk.c

.PHONY: all build clean rebuild

rebuild: clean s21_string.a

rebuild_test: clean test

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a test *.css *.html vgcore* main

