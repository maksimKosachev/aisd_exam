#include "../../../src/elementary/deque/vector/deque.h"
#include <assert.h>

int main() {
    Deque * dq = new_deque(-142);
    assert(!dq);

    Deque *deque = new_deque(5);
    assert(deque != NULL);
    assert(deque->size == 0);
    assert(deque->capacity == 5);

    // 1. push_tail: вставка в конец
    assert(push_tail(deque, 10) == ALL_GOOD);
    assert(push_tail(deque, 20) == ALL_GOOD);
    assert(push_tail(deque, 30) == ALL_GOOD);
    assert(deque->size == 3);

    // 2. pop_head: удаление с начала
    int value = -1;
    assert(pop_head(deque, &value) == ALL_GOOD);
    assert(value == 10);
    assert(deque->size == 2);

    // 3. push_head: вставка в начало
    assert(push_head(deque, 5) == ALL_GOOD);
    assert(deque->size == 3);

    // 4. pop_tail: удаление с конца
    assert(pop_tail(deque, &value) == ALL_GOOD);
    assert(value == 30);
    assert(deque->size == 2);

    // 5. Проверка порядка: должно остаться [5, 20]
    assert(pop_head(deque, &value) == ALL_GOOD);
    assert(value == 5);
    assert(pop_head(deque, &value) == ALL_GOOD);
    assert(value == 20);
    assert(deque->size == 0);

    // 6. Проверка на пустоту
    assert(pop_head(deque, &value) == EMPTY_STRUCTURE);
    assert(pop_tail(deque, &value) == EMPTY_STRUCTURE);

    // 7. Переполнение дека
    assert(push_tail(deque, 1) == ALL_GOOD);
    assert(push_tail(deque, 2) == ALL_GOOD);
    assert(push_tail(deque, 3) == ALL_GOOD);
    assert(push_tail(deque, 4) == ALL_GOOD);
    assert(push_tail(deque, 5) == ALL_GOOD);
    assert(push_tail(deque, 6) == FULL_STRUCTURE);

    // 8. Освобождение памяти
    free_deque(deque);

    printf("✅ Все тесты пройдены успешно!\n");
    return 0;
}
