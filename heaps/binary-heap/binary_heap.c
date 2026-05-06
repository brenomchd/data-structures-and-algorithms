#include "binary_heap.h"

#include <stdlib.h>

static void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*
 * Binary Max Heap
 *
 * Peek: O(1)
 * Push/pop: O(log n)
 * Space Complexity: O(n)
 */
void heap_init(BinaryMaxHeap *heap)
{
    if (heap == NULL) {
        return;
    }

    heap->values = NULL;
    heap->size = 0;
    heap->capacity = 0;
}

static int heap_reserve(BinaryMaxHeap *heap)
{
    if (heap->size < heap->capacity) {
        return 1;
    }

    size_t new_capacity = heap->capacity == 0 ? 8 : heap->capacity * 2;
    int *values = realloc(heap->values, new_capacity * sizeof(*values));
    if (values == NULL) {
        return 0;
    }

    heap->values = values;
    heap->capacity = new_capacity;
    return 1;
}

int heap_push(BinaryMaxHeap *heap, int value)
{
    if (heap == NULL || !heap_reserve(heap)) {
        return 0;
    }

    size_t index = heap->size++;
    heap->values[index] = value;

    while (index > 0) {
        size_t parent = (index - 1) / 2;
        if (heap->values[parent] >= heap->values[index]) {
            break;
        }

        swap(&heap->values[parent], &heap->values[index]);
        index = parent;
    }

    return 1;
}

int heap_peek(const BinaryMaxHeap *heap, int *value)
{
    if (heap == NULL || heap->size == 0 || value == NULL) {
        return 0;
    }

    *value = heap->values[0];
    return 1;
}

int heap_pop(BinaryMaxHeap *heap, int *value)
{
    if (heap == NULL || heap->size == 0 || value == NULL) {
        return 0;
    }

    *value = heap->values[0];
    heap->values[0] = heap->values[--heap->size];

    for (size_t index = 0;;) {
        size_t left = index * 2 + 1;
        size_t right = left + 1;
        size_t largest = index;

        if (left < heap->size && heap->values[left] > heap->values[largest]) {
            largest = left;
        }

        if (right < heap->size && heap->values[right] > heap->values[largest]) {
            largest = right;
        }

        if (largest == index) {
            break;
        }

        swap(&heap->values[index], &heap->values[largest]);
        index = largest;
    }

    return 1;
}

size_t heap_size(const BinaryMaxHeap *heap)
{
    return heap == NULL ? 0 : heap->size;
}

void heap_destroy(BinaryMaxHeap *heap)
{
    if (heap == NULL) {
        return;
    }

    free(heap->values);
    heap_init(heap);
}
