#include "push_swap.h"

static int find_min(stack_i *a)
{
    int min;

    min = a->data;
    while (a)
    {
        if (a->data < min)
            min = a->data;
        a = a->next;
    }
    return (min);
}

void sort_5(stack_i **a, stack_i **b)
{
    int i;
    int min;
    int max;
    int size;

    i = 0;
    size = stack_size(*a);
    while (i < 2)
    {
        min = find_min(*a);
        if ((*a)->data == min)
            push(b, a);
        else
            rotate(a, "ra");
        i++;
    }
    sort_3(a);
    push(a, b);
    push(a, b);
}
