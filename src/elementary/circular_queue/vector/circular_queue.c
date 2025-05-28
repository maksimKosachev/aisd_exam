#include "circular_queue.h"


Queue * new_queue(const ssize_t capacity){
    if (capacity <= 0) return NULL;

    Queue * queue = malloc(sizeof(Queue));
    if (!queue) return NULL;

    *queue = (Queue){0, 0, 0, (size_t)capacity, NULL};

    queue->vector = calloc(queue->capacity, sizeof(int));
    if (!queue->vector){
        free(queue);
        return NULL;
    }

    return queue;
}


void free_queue(Queue * queue){
    if (!queue) return;

    free(queue->vector);
    free(queue);
}


void print_queue(const Queue * queue){
    if (!queue) return;

    if (queue->size == 0){
        printf("Очередь пуста\n");
        return;
    }

    printf("Начало -> ");
    for (size_t i = 0; i < queue->size; i++){
        printf("%d ", queue->vector[(queue->head + i) % queue->capacity]);
    }
    printf("<- Конец\n");
}


Error enqueue(Queue * queue, const int data){
    if (!queue) return MEMORY_ERROR;

    if (queue->size >= queue->capacity) return FULL_STRUCTURE;

    queue->vector[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;

    return ALL_GOOD;
}


Error dequeue(Queue * queue, int * output){
    if (!queue || !output) return MEMORY_ERROR;

    if (queue->size == 0) return EMPTY_STRUCTURE;
    
    *output = queue->vector[queue->head];
    
    queue->head = (queue->head + 1) % queue->capacity;

    queue->size--;
    
    return ALL_GOOD;
}
