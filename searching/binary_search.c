#include "binary_search.h"

/*
 * Binary Search
 *
 * Requires a sorted array.
 *
 * Time Complexity:
 * Best Case: O(1)
 * Average Case: O(log n)
 * Worst Case: O(log n)
 *
 * Space Complexity: O(1)
 */
int binary_search(const int values[], size_t length, int target)
{
    size_t left = 0;
    size_t right = length;

    if (values == NULL) {
        return -1;
    }

    while (left < right) {
        size_t middle = left + (right - left) / 2;

        if (values[middle] == target) {
            return (int)middle;
        }

        if (values[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return -1;
}
