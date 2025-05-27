#include "../../../src/elementary/circular_queue/list/circular_queue.h"
#include <assert.h>

int main(void) {
    Queue * queue = new_queue();
    assert(queue != NULL);

    assert(enqueue(queue, 1) == ALL_GOOD);
    assert(enqueue(queue, 2) == ALL_GOOD);
    assert(enqueue(queue, 3) == ALL_GOOD);
    assert(enqueue(queue, 4) == ALL_GOOD);
    assert(enqueue(queue, 5) == ALL_GOOD);

    print_queue(queue);

    int value;
    assert(dequeue(queue, &value) == ALL_GOOD);
    assert(value == 1);

    assert(dequeue(queue, &value) == ALL_GOOD);
    assert(value == 2);

    assert(dequeue(queue, &value) == ALL_GOOD);
    assert(value == 3);

    assert(dequeue(queue, &value) == ALL_GOOD);
    assert(value == 4);

    assert(dequeue(queue, &value) == ALL_GOOD);
    assert(value == 5);

    assert(queue->size == 0);
    print_queue(queue);

    assert(enqueue(queue, 100) == ALL_GOOD);
    assert(queue->size == 1);
    print_queue(queue);

    free_queue(queue);

    return 0;
}