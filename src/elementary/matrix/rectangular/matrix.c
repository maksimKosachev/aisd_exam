#include "matrix.h"


Matrix * new_matrix(const size_t m, const size_t n){
    Matrix * matrix = malloc(sizeof(Matrix));
    if (!matrix) return NULL;

    matrix->m = m;
    matrix->n = n;

    matrix->data = calloc(m, sizeof(int *));
    if (!matrix->data){
        free(matrix);
        return NULL;
    }

    for (size_t i = 0; i < m; i++){
        matrix->data[i] = calloc(n, sizeof(int));
    }

    return matrix;
}


void free_matrix(Matrix * matrix){
    if (!matrix) return;

    for (size_t i = 0; i < matrix->m; i++)
        free(matrix->data[i]);

    free(matrix->data);
    free(matrix);
}


void print_matrix(const Matrix * matrix){
    if (!matrix) return;

    for (size_t i = 0; i < matrix->m; i++){
        printf("( ");
        for (size_t j = 0; j < matrix->n; j++){
            printf("%d ", matrix->data[i][j]);
        }
        printf(")\n");
    }
}


Error insert_elm(Matrix * matrix, const size_t i, const size_t j, const int value){
    if (!matrix) return MEMORY_ERROR;

    matrix->data[i-1][j-1] = value;

    return ALL_GOOD;
}


Error delete_elm(Matrix * matrix, const size_t i, const size_t j){
    if (!matrix) return MEMORY_ERROR;

    matrix->data[i-1][j-1] = 0;

    return ALL_GOOD;
}


Matrix * find_sum(const Matrix * a, const Matrix * b){
    if (!a || !b) return NULL;


    if (a->m != b->m || a->n != b->n) return NULL;

    Matrix * c = new_matrix(a->m, a->n);
    if (!c) return NULL;

    for (size_t i = 0; i < c->m; i++){
        for (size_t j = 0; j < c->n; j++){
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return c;
}


Matrix * multiply_by_number(const Matrix * a, const int constant){
    if (!a) return NULL;

    Matrix * b = new_matrix(a->m, a->n);
    if (!b) return NULL;

    for (size_t i = 0; i < a->m;i++){
        for (size_t j = 0; j < a->n; j++){
            b->data[i][j] = constant * a->data[i][j];
        }
    }

    return b;
}


Matrix * find_product(const Matrix * a, const Matrix * b){
    if (!a || !b) return NULL;

    if (a->n != b->m) return NULL;

    Matrix * c = new_matrix(a->m, b->n);

    for (size_t i = 0; i < c->m; i++){
        for (size_t j = 0; j < c->n; j++){
            int sum = 0;
            for (size_t k = 0; k < a->n; k++){
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }


    return c;
}


Matrix * transpose(const Matrix * a){
    if (!a) return NULL;

    Matrix * at = new_matrix(a->n, a->m);
    if (!at) return NULL;

    for (size_t i = 0; i < at->m; i++){
        for (size_t j = 0; j < at->n; j++){
            at->data[i][j] = a->data[j][i];
        }
    }

    return at;
}
