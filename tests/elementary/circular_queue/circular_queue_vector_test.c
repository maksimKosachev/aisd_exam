#include "../../../src/elementary/circular_queue/vector/circular_queue.h"
#include <assert.h>


int main() {
    Queue *q = new_queue(3);
    assert(q != NULL);

    assert(enqueue(q, 10) == ALL_GOOD);
    assert(enqueue(q, 20) == ALL_GOOD);
    assert(enqueue(q, 30) == ALL_GOOD);
    assert(enqueue(q, 40) == FULL_STRUCTURE); // очередь полная

    int x;
    assert(dequeue(q, &x) == ALL_GOOD);
    assert(x == 10);

    assert(dequeue(q, &x) == ALL_GOOD);
    assert(x == 20);

    assert(dequeue(q, &x) == ALL_GOOD);
    assert(x == 30);

    assert(dequeue(q, &x) == EMPTY_STRUCTURE); // очередь пустая

    free_queue(q);

    printf("🎉 Все тесты были успешно пройдены\n");

    return 0;
}