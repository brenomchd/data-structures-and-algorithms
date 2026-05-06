#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

typedef struct SinglyListNode SinglyListNode;

typedef struct {
    SinglyListNode *head;
    size_t size;
} SinglyLinkedList;

void list_init(SinglyLinkedList *list);
int list_push_front(SinglyLinkedList *list, int value);
int list_push_back(SinglyLinkedList *list, int value);
int list_remove(SinglyLinkedList *list, int value);
int list_contains(const SinglyLinkedList *list, int value);
size_t list_size(const SinglyLinkedList *list);
void list_clear(SinglyLinkedList *list);

#endif
