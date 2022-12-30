#ifndef SRC_s21_string_H_
#define SRC_s21_string_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

void *s21_memchr(const void *str, int c, s21_size_t n);
// void *s21_memcpy(void *dest, void const *src, s21_size_t n);
// void *s21_memmove(void *dest, void const *src, s21_size_t n);
// void *s21_memset(void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
size_t s21_strlen(const char *str);
char *s21_strcat(char *dest, const char *str);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_s21_string_H_
