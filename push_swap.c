//algo that will do it all
//MNIN ANBDAHAA

#include "push_swap.h"

int is_it_sorted (stack_i *a)
{
    stack_i *tmp;

    tmp = a;
    while (tmp->next)
    {
        if (tmp->data > tmp->next->data)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}
void push_swap(stack_i **a, stack_i **b)
{
    int size;

    while(!is_it_sorted(*a))
    {
        size = stack_len(*a);
        if (size == 2)
            swap(a, "sa");
        else if (size >= 3 && size <= 5)
            sort_5(a, b);
    }
}