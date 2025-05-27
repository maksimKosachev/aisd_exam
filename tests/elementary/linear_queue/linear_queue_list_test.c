#include "../../../src/elementary/linear_queue/list/linear_queue.h"


int main(){
    Queue * queue = new_queue();

    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);

    print_queue(queue);
    int dummy;
    dequeue(queue, &dummy);
    dequeue(queue, &dummy); 
    dequeue(queue, &dummy);
    dequeue(queue, &dummy);
    dequeue(queue, &dummy);
    dequeue(queue, &dummy);

    print_queue(queue);

    enqueue(queue, 1);
    print_queue(queue);

    free_queue(queue);

    return 0;
}