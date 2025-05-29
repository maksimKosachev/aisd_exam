#include "deque.h"


Deque * new_deque(const ssize_t capacity){
    if (capacity <= 0) return NULL;

    Deque * deque = calloc(1, sizeof(Deque));
    if (!deque) return NULL;

    deque->capacity = (size_t)capacity;
    deque->vector = calloc(deque->capacity, sizeof(int));
    if (!deque->vector){
        free(deque);
        return NULL;
    }

    return deque;
}


void free_deque(Deque * deque){
    if (!deque) return;

    free(deque->vector);
    free(deque);
}


void print_deque(const Deque * deque){
    if (!deque) return;

    if (deque->size == 0){
        printf("Дек пустой\n");
        return;
    }

    printf("Начало -> ");
    for (size_t i = 0; i < deque->size; i++){
        printf("%d ", deque->vector[(deque->head + i) % deque->capacity]);
    }
    printf("<- Конец\n");
}


Error push_head(Deque * deque, const int data){
    if (!deque) return MEMORY_ERROR;

    if (deque->size >= deque->capacity) return FULL_STRUCTURE;

    deque->head = (deque->head -1 + deque->capacity) % deque->capacity;
    deque->vector[deque->head] = data;

    deque->size++;

    return ALL_GOOD;
}


Error push_tail(Deque * deque, const int data){
    if (!deque) return MEMORY_ERROR;

    if (deque->size >= deque->capacity) return FULL_STRUCTURE;

    deque->vector[deque->tail] = data;
    deque->tail = (deque->tail + 1) % deque->capacity;

    deque->size++;

    return ALL_GOOD;
}


Error pop_head(Deque * deque, int * output){
    if (!deque || !output) return MEMORY_ERROR;

    if (deque->size == 0) return EMPTY_STRUCTURE;

    *output = deque->vector[deque->head];
    deque->head = (deque->head + 1) % deque->capacity;

    deque->size--;

    return ALL_GOOD;
}


Error pop_tail(Deque * deque, int * output){
    if (!deque || !output) return MEMORY_ERROR;

    if (deque->size == 0) return EMPTY_STRUCTURE;

    deque->tail = (deque->tail - 1 + deque->capacity) % deque->capacity;
    *output = deque->vector[deque->tail];

    deque->size--;

    return ALL_GOOD;
}