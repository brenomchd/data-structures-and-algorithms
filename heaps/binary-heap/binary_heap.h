#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stddef.h>

typedef struct {
    int *values;
    size_t size;
    size_t capacity;
} BinaryMaxHeap;

void heap_init(BinaryMaxHeap *heap);
int heap_push(BinaryMaxHeap *heap, int value);
int heap_peek(const BinaryMaxHeap *heap, int *value);
int heap_pop(BinaryMaxHeap *heap, int *value);
size_t heap_size(const BinaryMaxHeap *heap);
void heap_destroy(BinaryMaxHeap *heap);

#endif
