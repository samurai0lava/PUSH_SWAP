#include "push_swap.h"

void init(stack_i **a, array_s *re) 
{
    *a = createStack();
    if (*a == NULL) {
        fprintf(stderr, "Error: Failed to initialize stack\n");
        return;
    }

    for (int i = 0; i < re->size; i++) {
        push(*a, re->array[i]);
    }
}

