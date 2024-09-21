#ifndef ALIGNED_ALLOC_H
#define ALIGNED_ALLOC_H

void *aligned_malloc(size_t size, size_t alignment);
void aligned_free(void *ptr);

#endif /* ALIGNED_ALLOC_H */
