#include "../../../src/elementary/stack/list/stack.h"
#include <assert.h>


int main() {
    Stack * stack = new_stack();
    assert(stack != NULL);

    
    assert(push_stack(stack, 1) == ALL_GOOD);
    assert(push_stack(stack, 2) == ALL_GOOD);

    print_stack(stack); 

    int result = 0;

    
    assert(pop_stack(stack, &result) == ALL_GOOD);
    assert(result == 2);

    print_stack(stack);


    assert(pop_stack(stack, &result) == ALL_GOOD);
    assert(result == 1);

    print_stack(stack);

    assert(pop_stack(stack, &result) == EMPTY_STRUCTURE);

    free_stack(stack);

    return 0;
}