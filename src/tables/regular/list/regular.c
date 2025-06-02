#include "regular.h"


Table * new_table(){
    Table * table = calloc(1, sizeof(Table));
    if (!table) return NULL;

    return table;
}


void free_table(Table * table){
    if (!table) return;

    Node * to_delete = NULL;
    while(table->head){
        to_delete = table->head;
        table->head = table->head->next;
        free(to_delete);
    }

    free(table);
}


void print_table(const Table * table){
    if (!table) return;

    if (!table->head){
        printf("Таблица пустая\n");
        return;
    }

    Node * tmp = table->head;
    while(tmp){
        printf("%zu: %d\n", tmp->key, tmp->info);
        tmp = tmp->next;
    }

    printf("\n");
}


Node * find_node(const Table * table, const ssize_t key){
    if (!table || key <= 0) return NULL;

    Node * tmp = table->head;
    while(tmp){
        if (tmp->key == (size_t)key) return tmp;
        tmp = tmp->next;
    }

    return NULL;
}


Error insert_node(Table * table, const ssize_t key, const int info){
    if (!table) return MEMORY_ERROR;

    if (key <= 0) return INCORRECT_KEY;

    Node * new_node = malloc(sizeof(Node));
    if (!new_node) return MEMORY_ERROR;

    *new_node = (Node){(size_t)key, info, NULL};

    if (!table->head) {
        table->head = new_node;
        return ALL_GOOD;
    }

    Node * head = table->head;
    while (head){
        if (head->key == new_node->key){
            free(new_node);
            return KEY_ALREADY_EXISTS;
        }

        if (!head->next) break;

        head = head->next;        
    }

    head->next = new_node;

    return ALL_GOOD;
}


Error erase_node(Table * table, const ssize_t key){
    if (!table || !table->head) return MEMORY_ERROR;

    if (key <= 0) return INCORRECT_KEY;

    Node * curr = table->head;
    Node * prev = NULL;
    
    while(curr){
        if (curr->key == (size_t)key){
            Node * to_delete = curr;
            
            if (curr == table->head) table->head = table->head->next;
            else prev->next = curr->next;

            free(to_delete);
            return ALL_GOOD;
        }

        prev = curr;
        curr = curr->next;
    }

    return KEY_NOT_FOUND;
}