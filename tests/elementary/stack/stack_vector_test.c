#include "../../../src/elementary/stack/vector/stack.h"
#include <assert.h>


int main(void) {
    Stack * s = new_stack(-10);
    assert(!s);
    Stack *stack = new_stack(10);
    assert(stack != NULL);
    assert(stack->capacity == 10);
    assert(stack->size == 0);

    assert(push_stack(stack, 1) == ALL_GOOD);
    assert(push_stack(stack, 21231232) == ALL_GOOD);
    assert(stack->size == 2);

    print_stack(stack);

    int result = 0;

    assert(pop_stack(stack, &result) == ALL_GOOD);
    assert(result == 21231232);
    assert(stack->size == 1);

    print_stack(stack);

    assert(pop_stack(stack, &result) == ALL_GOOD);
    assert(result == 1);
    assert(stack->size == 0);

    print_stack(stack);

    assert(pop_stack(stack, &result) == EMPTY_STRUCTURE);

    free_stack(stack);

    return 0;
}