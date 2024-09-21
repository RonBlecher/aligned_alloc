#define _GNU_SOURCE // for aligned_alloc()

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "aligned_alloc.h"

int main(void) {
    uintptr_t p;
    int *a = aligned_malloc(sizeof(*a) * 10, 4);
    if (!a) {
        printf("aligned_malloc failed\n");
    } else {
        p = (uintptr_t)a;
        printf("aligned_malloc addr=%p, %d\n", a, p % 4 == 0);
        aligned_free(a);
    }

    a = aligned_alloc(sizeof(*a) * 2, 4);
    if (!a) {
        printf("aligned_alloc failed\n");
    } else {
        p = (uintptr_t)a;
        printf("aligned_alloc addr=%p, %d\n", a, p % 4 == 0);
        free(a);
    }

    return 0;
}
