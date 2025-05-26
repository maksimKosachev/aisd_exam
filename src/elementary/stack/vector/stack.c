#include "stack.h"


Stack * new_stack(const size_t capacity){
    Stack * stack = malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->size = 0;
    stack->capacity = capacity;

    stack->vector = calloc(capacity, sizeof(int));
    if (!stack->vector){
        free(stack);
        return NULL;
    }

    return stack;
}


void free_stack(Stack * stack){
    if (!stack || !stack->vector) return;

    free(stack->vector);
    free(stack);
}


void print_stack(const Stack * stack){
    if (!stack) return;

    if (stack->size == 0){
        printf("Стек пустой\n");
        return;
    }

    for (size_t i = 0; i < stack->size; i++){
        printf("%d ", stack->vector[i]);
    }

    printf("\n");
}


Error push_stack(Stack * stack, const int data){
    if (!stack) return MEMORY_ERROR;

    if (stack->size >= stack->capacity){
        stack->vector = realloc(stack->vector, sizeof(int) * (stack->capacity + 1));
        if (!stack->vector) return MEMORY_ERROR;

        stack->capacity++;
    }

    stack->vector[stack->size] = data;

    stack->size++;

    return ALL_GOOD;
}


Error pop_stack(Stack * stack, int * output){
    if (!stack || !output) return MEMORY_ERROR;

    if (stack->size == 0) return EMPTY_STRUCTURE;

    stack->size--;
    *output = stack->vector[stack->size];

    return ALL_GOOD;

}


Error peek_stack(Stack * stack, int * output){
    if (!stack || !output) return MEMORY_ERROR;

    if (stack->size == 0) return EMPTY_STRUCTURE;

    *output = stack->vector[stack->size-1];

    return ALL_GOOD;
}