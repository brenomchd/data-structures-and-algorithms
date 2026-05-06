#include "linked_queue.h"

#include <stdlib.h>

struct QueueNode {
    int value;
    struct QueueNode *next;
};

/*
 * Linked Queue
 *
 * Enqueue, dequeue and peek: O(1)
 * Space Complexity: O(n)
 */
void queue_init(LinkedQueue *queue)
{
    if (queue == NULL) {
        return;
    }

    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
}

int queue_enqueue(LinkedQueue *queue, int value)
{
    if (queue == NULL) {
        return 0;
    }

    QueueNode *node = malloc(sizeof(*node));
    if (node == NULL) {
        return 0;
    }

    node->value = value;
    node->next = NULL;

    if (queue->back == NULL) {
        queue->front = node;
    } else {
        queue->back->next = node;
    }

    queue->back = node;
    queue->size++;
    return 1;
}

int queue_dequeue(LinkedQueue *queue, int *value)
{
    if (queue == NULL || queue->front == NULL || value == NULL) {
        return 0;
    }

    QueueNode *removed = queue->front;
    *value = removed->value;
    queue->front = removed->next;

    if (queue->front == NULL) {
        queue->back = NULL;
    }

    free(removed);
    queue->size--;
    return 1;
}

int queue_peek(const LinkedQueue *queue, int *value)
{
    if (queue == NULL || queue->front == NULL || value == NULL) {
        return 0;
    }

    *value = queue->front->value;
    return 1;
}

int queue_is_empty(const LinkedQueue *queue)
{
    return queue == NULL || queue->size == 0;
}

size_t queue_size(const LinkedQueue *queue)
{
    return queue == NULL ? 0 : queue->size;
}

void queue_clear(LinkedQueue *queue)
{
    if (queue == NULL) {
        return;
    }

    while (queue->front != NULL) {
        QueueNode *removed = queue->front;
        queue->front = removed->next;
        free(removed);
    }

    queue->back = NULL;
    queue->size = 0;
}
