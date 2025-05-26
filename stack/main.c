#include "vector/stack.h"


int main(){
    Stack * stack = new_stack(4);
    
    // push_stack(stack, 1);
    // push_stack(stack, 2);
    // push_stack(stack, 3);
    // push_stack(stack, 4);
    // push_stack(stack, 5);
    int result;
    pop_stack(stack, &result);
    // push_stack(stack, 5);
    print_stack(stack);
    free_stack(stack);
    return 0;
}