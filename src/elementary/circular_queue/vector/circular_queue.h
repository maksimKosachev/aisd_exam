#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "stdlib.h"
#include "stdio.h"

#include "../../../include/error.h"

typedef struct Queue {
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
    int * vector;
} Queue;


Queue * new_queue(const size_t capacity);
void free_queue(Queue * queue);
void print_queue(const Queue * queue);
Error enqueue(Queue * queue, const int data);
Error dequeue(Queue * queue, int * output);

#endif