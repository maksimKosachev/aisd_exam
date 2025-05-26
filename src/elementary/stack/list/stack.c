#include "stack.h"


Stack * new_stack(){
    Stack * stack = malloc(sizeof(Stack));
    if (!stack) return NULL;

    *stack = (Stack){0, NULL};

    return stack;
}


void free_stack(Stack * stack){
    if (!stack) return;

    Node * tmp = stack->head;
    Node * to_delete = NULL;

    while(tmp){
        to_delete = tmp;
        tmp = tmp->next;
        free(to_delete);
    }

    free(stack);
}


void print_stack(const Stack * stack){
    if (!stack) return;

    if (!stack->head){
        printf("Стек пустой\n");
        return;
    }

    Node * tmp = stack->head;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}


Error push_stack(Stack * stack, const int data){
    if (!stack) return MEMORY_ERROR;

    Node * new_node = malloc(sizeof(Node));
    if (!new_node) return MEMORY_ERROR;

    *new_node = (Node){data, NULL};

    new_node->next = stack->head;
    stack->head = new_node;

    stack->size++;

    return ALL_GOOD;
}


Error pop_stack(Stack * stack, int * output){
    if (!stack || !output) return MEMORY_ERROR;

    if (!stack->head) return EMPTY_STRUCTURE;
    
    Node * to_delete = stack->head;
    *output = stack->head->data;
    stack->head = stack->head->next;
    
    free(to_delete);

    stack->size--;

    return ALL_GOOD;
}


Error peek_stack(Stack * stack, int * output){
    if (!stack || !output) return MEMORY_ERROR;

    if (!stack->head) return EMPTY_STRUCTURE;

    *output = stack->head->data;

    return ALL_GOOD;
}