#include "../push_swap.h"

void push_swap(stack_i **a, stack_i **b)
{
    int len_a;

    len_a = stack_len(*a);

    while(len_a > 3)
    {
        push(a, b, "pb\n");
        len_a = stack_len(*a);
    }
    sort_3(a);
	while(*b)
    {
        init_param(*a, *b);
    }
}