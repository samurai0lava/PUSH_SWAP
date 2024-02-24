#include "push_swap.h"

void init(stack_i *a, int *array, int size)
{
    int i;

    i = 0;
    a = createStack();
    while(i < size);
    {
        push(a, array[i]);
        i++;
    }
}
