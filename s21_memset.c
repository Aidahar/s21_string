#include "s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
	size_t idx;
	unsigned char *dest = str;
	for(idx = 0; idx < n; idx++, dest++){
		*dest = (char)c;
	}
	return (void *)dest;
}
