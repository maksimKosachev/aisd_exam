#ifndef REGULAR_H
#define REGULAR_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "../../../include/error.h"

// Дублирование ключей запрещено
typedef struct Node {
    size_t key;
    int info;
    struct Node * next;
} Node;

typedef struct Table {
    Node * head;
} Table;


Table * new_table();
void free_table(Table * table);
void print_table(const Table * table);
Node * find_node(const Table * table, const ssize_t key);
Error insert_node(Table * table, const ssize_t key, const int info);
Error erase_node(Table * table, const ssize_t key);


#endif