#ifndef REGULAR_H
#define REGULAR_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdbool.h>

#include "../../../include/error.h"


typedef struct Node {
    size_t key;
    int info;
    char busy;
} Node;

typedef struct Table {
    size_t size;
    size_t capacity;
    Node * vector;
} Table;


Table * new_table(const ssize_t capacity);
void free_table(Table * table);
void print_table(const Table * table);
ssize_t find_node(const Table * table, const ssize_t key);
Error insert_node(Table * table, const ssize_t key, const int info);
Error erase_node(Table * table, const ssize_t key);

#endif