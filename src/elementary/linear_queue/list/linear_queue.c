#include "linear_queue.h"


Queue * new_queue(){
    Queue * queue = malloc(sizeof(Queue));
    if (!queue) return NULL;

    *queue = (Queue){NULL, NULL, 0};

    return queue;
}


void free_queue(Queue * queue){
    if (!queue) return;

    Node * to_delete = NULL;

    while(queue->head){
        to_delete = queue->head;
        queue->head = queue->head->next;
        free(to_delete);
    }

    free(queue);
}


void print_queue(const Queue * queue){
    if (!queue) return;

    if (queue->size == 0){
        printf("Очередь пустая\n");
        return;
    }

    Node * tmp = queue->head;

    printf("Начало -> ");
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("<- Конец\n");

}


Error enqueue(Queue * queue, const int data){
    if (!queue) return MEMORY_ERROR;

    Node * new_node = malloc(sizeof(Node));
    *new_node = (Node){data, NULL};

    if (queue->head == 0) queue->head = new_node;
    else queue->tail->next = new_node;

    queue->tail = new_node;
    queue->size++;

    return ALL_GOOD;
}


Error dequeue(Queue * queue, int * output){
    if (!queue || !output) return MEMORY_ERROR;

    if (queue->size == 0) return EMPTY_STRUCTURE;

    Node * to_delete = queue->head;
    *output = to_delete->data;
    queue->head = queue->head->next;
    if (!queue->head) queue->tail = NULL;

    free(to_delete);
    queue->size--;

    return ALL_GOOD;
}