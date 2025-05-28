#include "deque.h"


Deque * new_deque(){
    Deque * deque = calloc(1, sizeof(Deque));
    if (!deque) return NULL;

    return deque;
}


void free_deque(Deque * deque){
    if (!deque) return;

    if (deque->head){
        Node * tmp = deque->head;
        Node * to_delete = NULL;

        do {
            to_delete = tmp;
            tmp = tmp->next;
            free(to_delete);
        } while(tmp != deque->head);
    }

    free(deque);
}


void print_deque(const Deque * deque){
    if (!deque) return;

    if (deque->size == 0){
        printf("Дек пустой\n");
        return;
    }

    Node * tmp = deque->head;

    printf("Начало -> ");
    do {        
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while(tmp != deque->head);
    
    printf("<- Конец\n");
}


Error push_head(Deque * deque, const int data){
    if (!deque) return MEMORY_ERROR;

    Node * new_node = malloc(sizeof(Node));
    if (!new_node) return MEMORY_ERROR;

    *new_node = (Node){.prev=NULL, .next=NULL, .data=data};

    if (deque->size == 0){
        new_node->next = new_node->prev = new_node;
        deque->tail = deque->head = new_node;
    }
    else {
        new_node->next = deque->head;
        new_node->prev = deque->tail;

        deque->tail->next = new_node;
        deque->head->prev = new_node;
        
        deque->head = new_node;
    }

    deque->size++;

    return ALL_GOOD;
}


Error push_tail(Deque * deque, const int data){
    if (!deque) return MEMORY_ERROR;

    Node * new_node = malloc(sizeof(Node));
    if (!new_node) return MEMORY_ERROR;

    *new_node = (Node){.prev=NULL, .next=NULL, .data=data};

    if (deque->size == 0){
        new_node->next = new_node->prev = new_node;
        deque->head = deque->tail = new_node;
    }
    else {
        new_node->prev = deque->tail;
        new_node->next = deque->head;

        deque->tail->next = new_node;
        deque->head->prev = new_node;
        deque->tail = new_node;
    }

    deque->size++;

    return ALL_GOOD;
}


Error pop_head(Deque * deque, int * output){
    if (!deque || !output) return MEMORY_ERROR;

    if (deque->size == 0) return EMPTY_STRUCTURE;

    Node * to_delete = deque->head;
    *output = to_delete->data;

    if (deque->head == deque->tail){ // или deque->size == 1
        deque->head = deque->tail = NULL;
    } 
    else {
        deque->head = deque->head->next;
        deque->tail->next = deque->head;
        deque->head->prev = deque->tail;
    }

    free(to_delete);
    deque->size--;

    return ALL_GOOD;
}


Error pop_tail(Deque * deque, int * output){
    if (!deque || !output) return MEMORY_ERROR;

    if (deque->size == 0) return EMPTY_STRUCTURE;

    Node * to_delete = deque->tail;
    *output = to_delete->data;

    if (deque->head == deque->tail){
        deque->head = deque->tail = NULL;
    } 
    else {
        deque->tail = deque->tail->prev;
        deque->tail->next = deque->head;
        deque->head->prev = deque->tail;
    }

    free(to_delete);
    deque->size--;

    return ALL_GOOD;
}