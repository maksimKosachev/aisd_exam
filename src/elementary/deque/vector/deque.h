#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "../../../include/error.h"

typedef struct Deque {
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
    int * vector;
} Deque;


Deque * new_deque(const ssize_t capacity);
void free_deque(Deque * deque);
void print_deque(const Deque * deque);
Error push_head(Deque * deque, const int data);
Error push_tail(Deque * deque, const int data);
Error pop_head(Deque * deque, int * output);
Error pop_tail(Deque * deque, int * output);

#endif