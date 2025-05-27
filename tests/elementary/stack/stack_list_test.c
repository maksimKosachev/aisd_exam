#include "../../../src/elementary/stack/list/stack.h"


int main(){
    Stack * stack = new_stack();
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