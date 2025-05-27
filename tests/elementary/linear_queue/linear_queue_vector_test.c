#include "../../../src/elementary/linear_queue/vector/linear_queue.h"


int main(){
    size_t capacity = 2;
    Queue * queue = new_queue(capacity);

    print_queue(queue);
    int d;
    dequeue(queue, &d);
    enqueue(queue, 1);
    enqueue(queue, 2);
    print_queue(queue);
    // enqueue(queue, 3);
    // print_queue(queue);

    int dummy = 0;
    dequeue(queue, &dummy);
    printf("%d\n", dummy);
    print_queue(queue);
    dequeue(queue, &dummy);
    printf("%d\n", dummy);
    print_queue(queue);
    free_queue(queue);

    return 0;
}


