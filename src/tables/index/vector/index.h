#ifndef INDEX_H
#define INDEX_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "../../../include/error.h"


typedef struct Node {
    size_t key;
    int info;
} Node;

typedef struct Table {
    size_t size;
    size_t capacity;
    Node * vector;
} Table;


Table * new_table(const size_t capacity);
void free_table(Table * table);
void print_table(const Table * table);
ssize_t find_node(const Table * table, const size_t key);
Error insert_node(Table * table, const size_t key, const size_t info);
Error erase_node(Table * table, const size_t key);


#endif