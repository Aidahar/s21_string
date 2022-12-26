#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, size_t n) {
	size_t idx;
	if (NULL == dest) dest = NULL;
	char *targ = (char *)dest;
	char *from = (char *)src;
	for(idx = 0; idx < n; idx++, targ++, from++) {
		*targ = *from;
	}
	return (void *)dest;
}
