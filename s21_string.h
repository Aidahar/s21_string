#ifndef SRC_s21_string_H_
#define SRC_s21_string_H_

#include <stdlib.h>
#include <stdio.h>

void *s21_memchr(const void *str, int c, size_t n);
//void *s21_memcpy(void *dest, void const *src, size_t n);
//void *s21_memmove(void *dest, void const *src, size_t n);
//void *s21_memset(void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
//size_t s21_strlen(const char *str);

#endif  // SRC_s21_string_H_
