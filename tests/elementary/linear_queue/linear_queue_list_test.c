#include "../../../src/elementary/linear_queue/list/linear_queue.h"
#include "assert.h"

int main(){
    Queue * queue = new_queue();

    assert(enqueue(queue, 2) == ALL_GOOD);
    assert(enqueue(queue, 3) == ALL_GOOD);
    assert(enqueue(queue, 4) == ALL_GOOD);
    assert(enqueue(queue, 5) == ALL_GOOD);
    assert(enqueue(queue, 6) == ALL_GOOD);
    assert(enqueue(queue, 7) == ALL_GOOD);

    print_queue(queue);
    int dummy;
    assert(dequeue(queue, &dummy) == ALL_GOOD);
    assert(dequeue(queue, &dummy) == ALL_GOOD); 
    assert(dequeue(queue, &dummy) == ALL_GOOD);
    assert(dequeue(queue, &dummy) == ALL_GOOD);
    assert(dequeue(queue, &dummy) == ALL_GOOD);
    assert(dequeue(queue, &dummy) == ALL_GOOD);

    print_queue(queue);

    assert(enqueue(queue, 1) == ALL_GOOD);
    print_queue(queue);

    free_queue(queue);

    return 0;
}