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

static int get_index(stack_i *stack, int nbr)
{
    int index = 0;
    while (stack)
    {
        if (stack->data == nbr)
            return index;
        index++;
        stack = stack->next;
    }
    return (index);
}


void sort_5(stack_i **a, stack_i **b, int size)
{
    int     min;
    stack_i *tmp;
    int     index;

    index = get_index(*a, find_min(*a));

    while (stack_len(*a) > 3)
    {
        tmp = *a;
        min = find_min(*a);
        if (tmp->data == min)
            push(a, b, "pb\n");
        else
        {
            if(index <= size/2)
                rotate(a, "ra\n");
            else
                reverseRotate(a, "rra\n");
        }
    }
    if (!stack_sorted(*a))
        sort_3(a);
    while (*b != NULL)
        push(b, a, "pa\n");
}