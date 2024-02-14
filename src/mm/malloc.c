// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0)
		return NULL;

	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ptr == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(ptr, size) != 0) {
		munmap(ptr, size);
		return NULL;
	}

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ptr == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(ptr, size * nmemb) != 0) {
		munmap(ptr, size);
		return NULL;
	}
	memset(ptr, 0, sizeof(ptr));
	return ptr;
}

void free(void *ptr)
{
	struct mem_list *found = mem_list_find(ptr);
	if (found) {
		munmap(found->start, found->len);
		mem_list_del(found->start);
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL)
		return malloc(size);

	if (ptr && size == 0)
		free(ptr);

	free(ptr);
	return malloc(size);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (nmemb == 0 || size == 0) {
        free(ptr);
        return NULL;
    }
	return realloc(ptr, size * nmemb);
}
