#include "push_swap.h"

void init(stack_i *a, array_s *re)
{
    int i;

    i = 0;
    a = createStack();
    
    while(i < re->size)
    {
        push(a, re->array[i]);
        i++;
    }
}
