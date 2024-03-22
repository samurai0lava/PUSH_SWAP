#include "../push_swap.h"

void push_swap(stack_i **a, stack_i **b)
{
    int len_a;

    len_a = stack_len(*a);

    while(len_a > 3)
    {
        push(a, b, "pb\n");
    }
    sort_3(a);
	while(b)
    {
        init_param(*a, *b);
        printf("b: %d\n", (*b)->current_position);
        printf("len_a: %d\n", len_a);
        printf("len_b: %d\n", stack_len(*b));
        printf("%d\n", (*b)->cost);
        printf("%d\n", (*b)->median_top);
        printf("%d\n", (*b)->cheapest);
        print_stack((*a)->target);
        // moves(a, b);
    }
}



