#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stddef.h>

typedef struct QueueNode QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *back;
    size_t size;
} LinkedQueue;

void queue_init(LinkedQueue *queue);
int queue_enqueue(LinkedQueue *queue, int value);
int queue_dequeue(LinkedQueue *queue, int *value);
int queue_peek(const LinkedQueue *queue, int *value);
int queue_is_empty(const LinkedQueue *queue);
size_t queue_size(const LinkedQueue *queue);
void queue_clear(LinkedQueue *queue);

#endif
