#include "../../../src/elementary/deque/list/deque.h"
#include <assert.h>

int main(){
    Deque *dq = new_deque();
    assert(dq != NULL);
    assert(dq->size == 0);

    // Тест push_head
    assert(push_head(dq, 10) == ALL_GOOD);
    assert(dq->size == 1);
    assert(dq->head == dq->tail);
    assert(dq->head->data == 10);

    assert(push_head(dq, 20) == ALL_GOOD);
    assert(dq->size == 2);
    assert(dq->head->data == 20);
    assert(dq->tail->data == 10);

    // Тест push_tail
    assert(push_tail(dq, 30) == ALL_GOOD);
    assert(dq->size == 3);
    assert(dq->tail->data == 30);
    assert(dq->head->data == 20);

    assert(push_tail(dq, 40) == ALL_GOOD);
    assert(dq->size == 4);
    assert(dq->tail->data == 40);

    // Тест pop_head
    int val;
    assert(pop_head(dq, &val) == ALL_GOOD);
    assert(val == 20);
    assert(dq->size == 3);
    assert(dq->head->data == 10);

    assert(pop_head(dq, &val) == ALL_GOOD);
    assert(val == 10);
    assert(dq->size == 2);
    assert(dq->head->data == 30);

    // Тест pop_tail
    assert(pop_tail(dq, &val) == ALL_GOOD);
    assert(val == 40);
    assert(dq->size == 1);
    assert(dq->tail->data == 30);

    assert(pop_tail(dq, &val) == ALL_GOOD);
    assert(val == 30);
    assert(dq->size == 0);
    assert(dq->head == NULL && dq->tail == NULL);

    // Попытка удалить из пустого дека
    assert(pop_tail(dq, &val) == EMPTY_STRUCTURE);
    assert(pop_head(dq, &val) == EMPTY_STRUCTURE);

    free_deque(dq);
    printf("✅ Все тесты прошли успешно\n");

    return 0;
}