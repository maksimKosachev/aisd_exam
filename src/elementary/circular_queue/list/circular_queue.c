#include "circular_queue.h"


Queue * new_queue(){
    Queue * queue = malloc(sizeof(Queue));
    if (!queue) return NULL;

    *queue = (Queue){NULL, NULL, 0};
    
    return queue;
}


void free_queue(Queue * queue){
    if (!queue) return;

    if (queue->head){
        Node * to_delete = NULL;
        Node * tmp = queue->head;

        do {
            to_delete = tmp;    
            tmp = tmp->next;
            free(to_delete);
        } while(tmp != queue->head);
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
    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while(tmp != queue->head);
    printf("<- Конец\n");
}


Error enqueue(Queue * queue, const int data){
    if (!queue) return MEMORY_ERROR;

    Node * new_node = malloc(sizeof(Node));
    *new_node = (Node){data, NULL};

    if (queue->size == 0){
        new_node->next = new_node;
        queue->head = new_node;
    }
    else {
        new_node->next = queue->tail->next;
        queue->tail->next = new_node;
    }

    queue->tail = new_node;
    queue->size++;

    return ALL_GOOD;
}


Error dequeue(Queue * queue, int * output){
    if (!queue || !output) return MEMORY_ERROR;

    if (queue->size == 0) return EMPTY_STRUCTURE;

    Node * to_delete = queue->head;
    *output = to_delete->data;

    if (queue->head == queue->head->next){
        queue->head = NULL;
        queue->tail = NULL;
    }
    else {
        queue->head = queue->head->next;
        queue->tail->next = queue->head;
    }

    free(to_delete);
    queue->size--;

    return ALL_GOOD;
}