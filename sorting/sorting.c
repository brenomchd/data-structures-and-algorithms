#include "sorting.h"

#include <stdlib.h>

static void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*
 * Bubble Sort
 *
 * Time Complexity:
 * Best Case: O(n)
 * Average Case: O(n^2)
 * Worst Case: O(n^2)
 *
 * Space Complexity: O(1)
 */
void bubble_sort(int values[], size_t length)
{
    if (values == NULL || length < 2) {
        return;
    }

    for (size_t pass = 0; pass < length - 1; pass++) {
        int swapped = 0;

        for (size_t index = 0; index < length - pass - 1; index++) {
            if (values[index] > values[index + 1]) {
                swap(&values[index], &values[index + 1]);
                swapped = 1;
            }
        }

        if (!swapped) {
            return;
        }
    }
}

/*
 * Selection Sort
 *
 * Time Complexity:
 * Best Case: O(n^2)
 * Average Case: O(n^2)
 * Worst Case: O(n^2)
 *
 * Space Complexity: O(1)
 */
void selection_sort(int values[], size_t length)
{
    if (values == NULL || length < 2) {
        return;
    }

    for (size_t current = 0; current < length - 1; current++) {
        size_t min_index = current;

        for (size_t candidate = current + 1; candidate < length; candidate++) {
            if (values[candidate] < values[min_index]) {
                min_index = candidate;
            }
        }

        if (min_index != current) {
            swap(&values[current], &values[min_index]);
        }
    }
}

static void merge(int values[], int buffer[], size_t left, size_t middle, size_t right)
{
    size_t left_index = left;
    size_t right_index = middle;
    size_t buffer_index = left;

    while (left_index < middle && right_index < right) {
        if (values[left_index] <= values[right_index]) {
            buffer[buffer_index++] = values[left_index++];
        } else {
            buffer[buffer_index++] = values[right_index++];
        }
    }

    while (left_index < middle) {
        buffer[buffer_index++] = values[left_index++];
    }

    while (right_index < right) {
        buffer[buffer_index++] = values[right_index++];
    }

    for (size_t index = left; index < right; index++) {
        values[index] = buffer[index];
    }
}

static void merge_sort_range(int values[], int buffer[], size_t left, size_t right)
{
    if (right - left < 2) {
        return;
    }

    size_t middle = left + (right - left) / 2;
    merge_sort_range(values, buffer, left, middle);
    merge_sort_range(values, buffer, middle, right);
    merge(values, buffer, left, middle, right);
}

/*
 * Merge Sort
 *
 * Time Complexity:
 * Best Case: O(n log n)
 * Average Case: O(n log n)
 * Worst Case: O(n log n)
 *
 * Space Complexity: O(n)
 */
int merge_sort(int values[], size_t length)
{
    if (values == NULL || length < 2) {
        return 1;
    }

    int *buffer = malloc(length * sizeof(*buffer));
    if (buffer == NULL) {
        return 0;
    }

    merge_sort_range(values, buffer, 0, length);
    free(buffer);
    return 1;
}

static size_t partition(int values[], size_t low, size_t high)
{
    int pivot = values[high];
    size_t store_index = low;

    for (size_t index = low; index < high; index++) {
        if (values[index] <= pivot) {
            swap(&values[index], &values[store_index]);
            store_index++;
        }
    }

    swap(&values[store_index], &values[high]);
    return store_index;
}

static void quick_sort_range(int values[], size_t low, size_t high)
{
    if (low >= high) {
        return;
    }

    size_t pivot_index = partition(values, low, high);

    if (pivot_index > 0) {
        quick_sort_range(values, low, pivot_index - 1);
    }

    quick_sort_range(values, pivot_index + 1, high);
}

/*
 * Quick Sort
 *
 * Time Complexity:
 * Best Case: O(n log n)
 * Average Case: O(n log n)
 * Worst Case: O(n^2)
 *
 * Space Complexity: O(log n)
 */
void quick_sort(int values[], size_t length)
{
    if (values != NULL && length > 1) {
        quick_sort_range(values, 0, length - 1);
    }
}
