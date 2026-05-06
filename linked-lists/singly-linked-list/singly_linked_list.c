#include "singly_linked_list.h"

#include <stdlib.h>

struct SinglyListNode {
    int value;
    struct SinglyListNode *next;
};

/*
 * Singly Linked List
 *
 * Insertion at head: O(1)
 * Insertion at tail: O(n)
 * Search/removal by value: O(n)
 * Space Complexity: O(n)
 */
void list_init(SinglyLinkedList *list)
{
    if (list == NULL) {
        return;
    }

    list->head = NULL;
    list->size = 0;
}

int list_push_front(SinglyLinkedList *list, int value)
{
    if (list == NULL) {
        return 0;
    }

    SinglyListNode *node = malloc(sizeof(*node));
    if (node == NULL) {
        return 0;
    }

    node->value = value;
    node->next = list->head;
    list->head = node;
    list->size++;
    return 1;
}

int list_push_back(SinglyLinkedList *list, int value)
{
    if (list == NULL) {
        return 0;
    }

    SinglyListNode *node = malloc(sizeof(*node));
    if (node == NULL) {
        return 0;
    }

    node->value = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        SinglyListNode *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }

    list->size++;
    return 1;
}

int list_remove(SinglyLinkedList *list, int value)
{
    if (list == NULL) {
        return 0;
    }

    SinglyListNode **current = &list->head;

    while (*current != NULL) {
        if ((*current)->value == value) {
            SinglyListNode *removed = *current;
            *current = removed->next;
            free(removed);
            list->size--;
            return 1;
        }

        current = &(*current)->next;
    }

    return 0;
}

int list_contains(const SinglyLinkedList *list, int value)
{
    if (list == NULL) {
        return 0;
    }

    for (const SinglyListNode *node = list->head; node != NULL; node = node->next) {
        if (node->value == value) {
            return 1;
        }
    }

    return 0;
}

size_t list_size(const SinglyLinkedList *list)
{
    return list == NULL ? 0 : list->size;
}

void list_clear(SinglyLinkedList *list)
{
    if (list == NULL) {
        return;
    }

    while (list->head != NULL) {
        SinglyListNode *removed = list->head;
        list->head = removed->next;
        free(removed);
    }

    list->size = 0;
}
