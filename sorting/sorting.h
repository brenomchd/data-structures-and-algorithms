#ifndef SORTING_H
#define SORTING_H

#include <stddef.h>

/*
 * Sorting Algorithms
 *
 * All functions sort arrays of integers in ascending order.
 */
void bubble_sort(int values[], size_t length);
void selection_sort(int values[], size_t length);
int merge_sort(int values[], size_t length);
void quick_sort(int values[], size_t length);

#endif
