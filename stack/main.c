#include "list/stack_list.h"


int main(){
    Stack * stack = new_stack();
    
    push_stack(stack, 1);
    push_stack(stack, 2);
    push_stack(stack, 3);
    push_stack(stack, 4);
    int result = 0;
    peek_stack(stack, &result);
    printf("%d\n", result);
    print_stack(stack);
    free_stack(stack);

    return 0;
}