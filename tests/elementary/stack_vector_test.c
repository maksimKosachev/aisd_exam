#include "../../src/elementary/stack/vector/stack.h"


int main(){
    size_t capacity = 10;
    Stack * stack = new_stack(capacity);
    if (!stack) return 1;

    push_stack(stack, 1);
    push_stack(stack, 2);
    
    print_stack(stack);

    int result = 0;
    pop_stack(stack, &result);

    print_stack(stack);

    pop_stack(stack, &result);
    print_stack(stack);

    free_stack(stack);

    return 0;
}