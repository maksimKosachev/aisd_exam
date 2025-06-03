#include "index.h"


Table * new_table(const size_t capacity){
    if (capacity == 0) return NULL;

    Table * table = calloc(1, sizeof(Table));
    if (!table) return NULL;

    table->capacity = capacity;
    table->vector = calloc(table->capacity, sizeof(Node));
    if (!table->vector) return NULL;

    return table;
}


void free_table(Table * table){
    if (!table || !table->vector) return;

    free(table->vector);
    free(table);
}


void print_table(const Table * table){
    if (!table || !table->vector) return;

    if (table->size == 0){
        printf("Таблица пустая\n");
        return;
    }

    for (size_t i = 0; i < table->size; i++){
        printf("%zu: %d\n", table->vector[i].key, table->vector[i].info);
    }
    printf("\n");
}


ssize_t find_node(const Table * table, const size_t key){
    if (!table || !table->vector) return -1;

    ssize_t high = table->size - 1;
    ssize_t low = 0;

    while (low <= high){
        ssize_t mid = (low + high) / 2;
        size_t elm_key = table->vector[mid].key;

        if (key == elm_key) return mid;
        else if (key < elm_key) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}


Error insert_node(Table * table, const size_t key, const size_t info){
    if (!table || !table->vector) return MEMORY_ERROR;

    if (find_node(table, key) != -1) return KEY_ALREADY_EXISTS;
    if (table->size == table->capacity) return FULL_STRUCTURE;

    int i = (int)(table->size - 1);
    while (i >= 0 && table->vector[i].key > key){
        table->vector[i+1] = table->vector[i];
        i--;
    }

    table->vector[i+1] = (Node){key, info};
    table->size++;

    return ALL_GOOD;
}


Error erase_node(Table * table, const size_t key){
    if (!table || !table->vector) return MEMORY_ERROR;

    ssize_t index = find_node(table, key);
    if (index == -1) return KEY_NOT_FOUND;

    table->vector[index] = (Node){0, 0};

    for (size_t i = (size_t)index; i < table->size - 1; i++){
        table->vector[i] = table->vector[i+1];
    }

    table->size--;

    return ALL_GOOD;
}