#ifndef SRC_s21_string_H_
#define SRC_s21_string_H_

#include <stdio.h>
#include <stdlib.h>

#define S21_SIZE_T unsigned long long
#define S21_NULL (void *)0

void *s21_memchr(const void *str, int c, S21_SIZE_T n);
int s21_memcmp(const void *str1, const void *str2, S21_SIZE_T n);
void *s21_memcpy(void *dest, void const *src, S21_SIZE_T n);
void *s21_memmove(void *dest, void const *src, S21_SIZE_T n);
void *s21_memset(void *str, int c, S21_SIZE_T n);
S21_SIZE_T s21_strlen(const char *str);
char *s21_strcat(char *dest, const char *str);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
S21_SIZE_T s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
void *s21_trim(const char *src, const char *trim_chars);
void s21_itoa(int num, char *buf);
void reverse(char *str);

#endif  // SRC_s21_string_H_
