#ifndef STACK_LIST_H
#define STACK_LIST_H


#include <stdlib.h>
#include <stdio.h>

#include "../../../include/error.h"


typedef struct Node {
    int data;
    struct Node * next;
} Node;

typedef struct Stack {
    size_t size;
    Node * head;
} Stack;

typedef struct Stack Stack;

Stack * new_stack();
void free_stack(Stack * stack);
void print_stack(const Stack * stack);
Error push_stack(Stack * stack, const int data);
Error pop_stack(Stack * stack, int * output);
Error peek_stack(Stack * stack, int * output);

#endif