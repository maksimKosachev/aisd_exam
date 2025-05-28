#include "../../../src/elementary/matrix/rectangular/matrix.h"
#include "assert.h"


int main() {
    Matrix *a = new_matrix(-2, -2);
    assert(!a);
    a = new_matrix(2, 2);
    Matrix *b = new_matrix(2, 2);
    assert(a && b);
    assert(a->m == 2 && a->n == 2);
    assert(b->m == 2 && b->n == 2);

    // Заполнение матриц A и B
    assert(insert_elm(a, 1, 1, 1) == ALL_GOOD);
    assert(insert_elm(a, 1, 2, 2) == ALL_GOOD);
    assert(insert_elm(a, 2, 1, 3) == ALL_GOOD);
    assert(insert_elm(a, 2, 2, 4) == ALL_GOOD);

    assert(insert_elm(b, 1, 1, 1) == ALL_GOOD);
    assert(insert_elm(b, 1, 2, 2) == ALL_GOOD);
    assert(insert_elm(b, 2, 1, 3) == ALL_GOOD);
    assert(insert_elm(b, 2, 2, 4) == ALL_GOOD);

    // Проверка суммы
    Matrix *c = find_sum(a, b);
    assert(c);
    assert(c->data[0][0] == 2);
    assert(c->data[0][1] == 4);
    assert(c->data[1][0] == 6);
    assert(c->data[1][1] == 8);

    // Умножение суммы на число
    Matrix *d = multiply_by_number(c, 2);
    assert(d);
    assert(d->data[0][0] == 4);
    assert(d->data[0][1] == 8);
    assert(d->data[1][0] == 12);
    assert(d->data[1][1] == 16);
    print_matrix(d);  // Опционально

    // Проверка произведения матриц
    Matrix *e = find_product(a, b);
    assert(e);
    assert(e->m == 2 && e->n == 2);
    // Проверка конкретных значений произведения
    assert(e->data[0][0] == 7);   // 1*1 + 2*3
    assert(e->data[0][1] == 10);  // 1*2 + 2*4
    assert(e->data[1][0] == 15);  // 3*1 + 4*3
    assert(e->data[1][1] == 22);  // 3*2 + 4*4
    print_matrix(e);  // Опционально

    // Транспонирование A
    Matrix *at = transpose(a);
    assert(at);
    assert(at->m == 2 && at->n == 2);
    assert(at->data[0][0] == 1);  // (1,1) -> (1,1)
    assert(at->data[0][1] == 3);  // (2,1) -> (1,2)
    assert(at->data[1][0] == 2);  // (1,2) -> (2,1)
    assert(at->data[1][1] == 4);  // (2,2) -> (2,2)
    print_matrix(at);  // Опционально

    // Освобождение памяти
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
    free_matrix(d);
    free_matrix(e);
    free_matrix(at);

    return 0;
}
