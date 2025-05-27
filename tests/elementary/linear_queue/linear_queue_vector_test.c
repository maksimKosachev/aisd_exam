#include "../../../src/elementary/linear_queue/vector/linear_queue.h"
#include <assert.h>

int main(){
    size_t capacity = 2;
    Queue * queue = new_queue(capacity);

    print_queue(queue);
    int d;
    assert(dequeue(queue, &d) == EMPTY_STRUCTURE);
    assert(enqueue(queue, 1) == ALL_GOOD);
    assert(enqueue(queue, 2) == ALL_GOOD);
    print_queue(queue);
   
    int dummy = 0;
    assert(dequeue(queue, &dummy) == ALL_GOOD);
    assert(dummy == 1);
    assert(dequeue(queue, &dummy) == ALL_GOOD);
    assert(dummy == 2);
    free_queue(queue);

    return 0;
}


