#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "../../../include/error.h"

typedef struct Matrix {
    size_t m;
    size_t n;
    int ** data;
} Matrix;


Matrix * new_matrix(const ssize_t m, const ssize_t n);
void free_matrix(Matrix * matrix);
void print_matrix(const Matrix * matrix);
Error insert_elm(Matrix * matrix, const size_t i, const size_t j, const int value);
Error delete_elm(Matrix * matrix, const size_t i, const size_t j);
Matrix * find_sum(const Matrix * a, const Matrix * b);
Matrix * multiply_by_number(const Matrix * a, const int constant);
Matrix * find_product(const Matrix * a, const Matrix * b);
Matrix * transpose(const Matrix * a);


#endif