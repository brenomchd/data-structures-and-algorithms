#include "linked_stack.h"

#include <stdlib.h>

struct StackNode {
    int value;
    struct StackNode *next;
};

/*
 * Linked Stack
 *
 * Push, pop and peek: O(1)
 * Space Complexity: O(n)
 */
void stack_init(LinkedStack *stack)
{
    if (stack == NULL) {
        return;
    }

    stack->top = NULL;
    stack->size = 0;
}

int stack_push(LinkedStack *stack, int value)
{
    if (stack == NULL) {
        return 0;
    }

    StackNode *node = malloc(sizeof(*node));
    if (node == NULL) {
        return 0;
    }

    node->value = value;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    return 1;
}

int stack_pop(LinkedStack *stack, int *value)
{
    if (stack == NULL || stack->top == NULL || value == NULL) {
        return 0;
    }

    StackNode *removed = stack->top;
    *value = removed->value;
    stack->top = removed->next;
    free(removed);
    stack->size--;
    return 1;
}

int stack_peek(const LinkedStack *stack, int *value)
{
    if (stack == NULL || stack->top == NULL || value == NULL) {
        return 0;
    }

    *value = stack->top->value;
    return 1;
}

int stack_is_empty(const LinkedStack *stack)
{
    return stack == NULL || stack->size == 0;
}

size_t stack_size(const LinkedStack *stack)
{
    return stack == NULL ? 0 : stack->size;
}

void stack_clear(LinkedStack *stack)
{
    if (stack == NULL) {
        return;
    }

    while (stack->top != NULL) {
        StackNode *removed = stack->top;
        stack->top = removed->next;
        free(removed);
    }

    stack->size = 0;
}
