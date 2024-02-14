// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#define N 500

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i = 0;
	while (i != len + 1) {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i = 0;
	while (destination[i] != '\0') {
		i++;
	}
	int j = 0;
	while (source[j] != '\0') {
		destination[i] = source[j];
		j++;
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int i = 0;
	while (destination[i] != '\0') {
		i++;
	}
	size_t j = 0;
	while (j != len) {
		destination[i] = source[j];
		j++;
		i++;
	}
	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0;
	int ok = 0;
	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] < str2[i]) {
			return -1;
		} else if (str1[i] > str2[i]) {
			return 1;
		}
		i++;
	}
	if (str1[i] != '\0') {
		return 1;
	} else if (str2[i] != '\0') {
		return -1;
	} else {
		int j = 0;
		while (j != i) {
			if (str1[i] > str2[i]) {
				return 1;
			} else if (str1[i] < str2[i]) {
				ok = 1;
			}
			j++;
		}
	}
	if (ok == 0)
		return 0;

	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	size_t i = 0;
	int ok = 0;
	while (i != len) {
		if (str1[i] < str2[i]) {
			ok = 1;
		} else if (str1[i] > str2[i]) {
			return 1;
		}
		i++;
	}
	if (ok == 0)
		return 0;
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int i = 0;
	while (str[i] != c && str[i] != '\0') {
		str++;
	}

	if (str[i] != '\0')
		return (char *)str;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	i--;
	while (str[i] != c && i != -1) {
		i--;
	}

	if (i != -1)
		return (char *)(str + i);

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	int len = strlen(needle);
	int i = 0;
	int ret;
	while (haystack[i] != '\0' && ret != 0) {
		ret = strncmp(haystack, needle, len);
		i++;
		haystack++;
	}

	haystack--;
	if (ret == 0)
		return (char *)haystack;
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	int len_h = strlen(haystack);
	int len_n = strlen(needle);
	int ret;

	haystack = haystack + len_h;
	while(len_h != -1 && ret != 0) {
		ret = strncmp(haystack, needle, len_n);
		len_h--;
		haystack--;
	}

	haystack++;
	if (ret == 0)
		return (char *)haystack;

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	const char *src = (char *)source;
	size_t i = 0;
	while (i != num + 1) {
		dest[i] = src[i];
		i++;
	}
	destination = (void *)dest;

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	const char *src = (char *)source;
	char aux[N];

	size_t i = 0;

	while (i != num) {
		aux[i] = src[i];
		i++;
	}

	i = 0;

	while (i != num) {
		dest[i] = aux[i];
		i++;
	}

	destination = (void *)dest;

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *ptr1_aux = (char *)ptr1;
	const char *ptr2_aux = (char *)ptr2;
	size_t i = 0;
	int ok = 0;

	while (i != num) {
		if (ptr1_aux[i] > ptr2_aux[i]) {
			return 1;
		} else if (ptr1_aux[i] < ptr2_aux[i]) {
			ok = 1;
		}
		i++;
	}
	if (ok == 0)
		return 0;
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	char c = (char)value;
	size_t i = 0;
	while (i != num) {
		src[i] = c;
		i++;
	}
	source = (void *)src;
	return source;
}
