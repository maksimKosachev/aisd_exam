#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include <stdio.h>

#include "../../../include/error.h"

// да-да это кольцевой двусвязный список
typedef struct Node {
    struct Node * prev;
    struct Node * next;
    int data;
} Node;

typedef struct Deque {
    Node * head;
    Node * tail;
    size_t size;
} Deque;


Deque * new_deque();
void free_deque(Deque * deque);
void print_deque(const Deque * deque);
Error push_head(Deque * deque, const int data);
Error push_tail(Deque * deque, const int data);
Error pop_head(Deque * deque, int * output);
Error pop_tail(Deque * deque, int * output);

#endif