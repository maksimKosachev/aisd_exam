#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

#include "../../include/error.h"

typedef struct Stack {
    size_t size;
    size_t capacity;
    int * vector;
} Stack;


Stack * new_stack(const size_t capacity);
void free_stack(Stack * stack);
void print_stack(const Stack * stack);
Error push_stack(Stack * stack, const int data);
Error pop_stack(Stack * stack, int * output);
Error peek_stack(Stack * stack, int * output);

#endif