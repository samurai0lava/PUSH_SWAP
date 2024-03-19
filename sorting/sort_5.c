#include "../push_swap.h"

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

void sort_5(stack_i **a, stack_i **b, int size)
{
    int i;
    int min;
    
    i = 0;
    while (i < 2 && size > 3)
    {
        min = find_min(*a);
        
        if ((*a)->data == min)
            push(a, b, "pb\n");
        else
            rotate(a, "ra\n");
        i++;
    }
    sort_3(a);
    push(b, a, "pa\n");
    push(b, a, "pa\n");
    print_stack(*a);
    print_stack(*b);
}