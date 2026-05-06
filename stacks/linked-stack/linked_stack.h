#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stddef.h>

typedef struct StackNode StackNode;

typedef struct {
    StackNode *top;
    size_t size;
} LinkedStack;

void stack_init(LinkedStack *stack);
int stack_push(LinkedStack *stack, int value);
int stack_pop(LinkedStack *stack, int *value);
int stack_peek(const LinkedStack *stack, int *value);
int stack_is_empty(const LinkedStack *stack);
size_t stack_size(const LinkedStack *stack);
void stack_clear(LinkedStack *stack);

#endif
