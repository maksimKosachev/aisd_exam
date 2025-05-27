#include "linear_queue.h"


Queue * new_queue(const size_t capacity){
    Queue * queue = malloc(sizeof(Queue));
    if (!queue) return NULL;

    *queue = (Queue){0, 0, 0, capacity, NULL};
    queue->vector = calloc(capacity, sizeof(int));

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
        printf("Очередь пустая\n");
        return;
    }

    printf("Начало -> ");

    for (size_t i = 0; i < queue->size; i++){
        printf("%d ", queue->vector[queue->head + i]);
    }

    printf("<- Конец\n");
}


Error enqueue(Queue * queue, const int data){
    if (!queue) return MEMORY_ERROR;

    if (queue->size >= queue->capacity){
        // здесь конечно желательно бы написать чтобы элементы сдвигались
        // и таким образом место не пропадало, но мне лень
        queue->vector = realloc(queue->vector, sizeof(int) * (queue->capacity + 1));
        if (!queue->vector) return MEMORY_ERROR;

        queue->capacity++;
    }

    queue->vector[queue->tail] = data;

    queue->tail++;
    queue->size++;

    return ALL_GOOD;
}


Error dequeue(Queue * queue, int * output){
    if (!queue || !output) return MEMORY_ERROR;

    if (queue->size == 0) return EMPTY_STRUCTURE;

    *output = queue->vector[queue->head];
    queue->head++;
    queue->size--;

    return ALL_GOOD;
}