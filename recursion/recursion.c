#include "recursion.h"

/*
 * Factorial
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n), due to recursive stack frames.
 */
unsigned long long factorial(unsigned int number)
{
    if (number < 2) {
        return 1;
    }

    return number * factorial(number - 1);
}

/*
 * Fibonacci
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
unsigned long long fibonacci(unsigned int position)
{
    unsigned long long previous = 0;
    unsigned long long current = 1;

    for (unsigned int index = 0; index < position; index++) {
        unsigned long long next = previous + current;
        previous = current;
        current = next;
    }

    return previous;
}
