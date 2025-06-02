#include "regular.h"

static void collect_garbage(Table * table);

Table * new_table(const ssize_t capacity){
    if (capacity <= 0) return NULL;

    Table * table = calloc(1, sizeof(Table));
    if (!table) return NULL;

    table->capacity = (size_t)capacity;
    table->vector = calloc(table->capacity, sizeof(Node));
    
    if (!table->vector){
        free(table);
        return NULL;
    }

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
        printf("[%d] %zu: %d\n", table->vector[i].busy, table->vector[i].key, table->vector[i].info);
    }
    printf("\n");

}


ssize_t find_node(const Table * table, const ssize_t key){
    if (!table || !table->vector || key <= 0) return -1;

    for (size_t i = 0; i < table->size; i++){
        if (table->vector[i].busy == 1 && table->vector[i].key == (size_t)key){
            return i;
        }
    }

    return -1;
}


Error insert_node(Table * table, const ssize_t key, const int info){
    if (!table || !table->vector) return MEMORY_ERROR;

    if (find_node(table, key) != -1) return KEY_ALREADY_EXISTS;
  
    if (table->size == table->capacity) collect_garbage(table);

    if (table->size == table->capacity) return FULL_STRUCTURE;

    table->vector[table->size] = (Node){(size_t)key, info, 1};
    table->size++;

    return ALL_GOOD;
}


static void collect_garbage(Table * table){
    size_t j = 0;

    for (size_t i = 0; i < table->size; i++){
        if (table->vector[i].busy == 1){
            if (i != j){
                table->vector[j] = table->vector[i];
            }

            j++;
        }
    }
    table->size = j;
}


Error erase_node(Table * table, const ssize_t key){
    if (!table || !table->vector) return MEMORY_ERROR;

    if (table->size == 0) return EMPTY_STRUCTURE;

    ssize_t status = find_node(table, key);
    if (status == -1) return KEY_NOT_FOUND;

    table->vector[(size_t)status].busy = 0;

    return ALL_GOOD;
}