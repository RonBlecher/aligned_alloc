/*
 * avoids portability problems with posix_memalign() and aligned_alloc()
*/

#include <stdlib.h>
#include <stdint.h>

#include "aligned_alloc.h"

void *aligned_malloc(size_t size, size_t alignment) {
    const uintptr_t mask = alignment - 1;
    char *ptr = NULL;
    char *raw_ptr;

    raw_ptr = malloc(mask + sizeof(size_t) + size);
    if (raw_ptr) {
        ptr = (char *)raw_ptr + sizeof(size_t);
        ptr = (void *)(((uintptr_t)ptr + mask) & ~mask);
        *((size_t *)ptr - 1) = ptr - raw_ptr;
    }
    return ptr;
}

void aligned_free(void *ptr) {
    if (ptr) {
        free((char *)ptr - *((size_t *)ptr - 1));
    }
}
