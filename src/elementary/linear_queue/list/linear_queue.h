#ifndef LINEAR_QUEUE_H
#define LINEAR_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#include "../../../include/error.h"


typedef struct Node {
    int data;
    struct Node * next;
} Node;

typedef struct Queue {
    Node * head;
    Node * tail;
    size_t size;
} Queue;


Queue * new_queue();
void free_queue(Queue * queue);
void print_queue(const Queue * queue);
Error enqueue(Queue * queue, const int data);
Error dequeue(Queue * queue, int * output);

#endif