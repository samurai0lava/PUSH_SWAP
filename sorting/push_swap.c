#include "../push_swap.h"

void push_swap(stack_i **a, stack_i **b)
{
    int len_a;

    len_a = stack_len(*a);

    if(len_a-- > 3 && !stack_sorted(*a))
        push(a, b, "pb\n");
    if(len_a-- > 3 && !stack_sorted(*a))
        push(a, b, "pb\n");
	while(len_a-- > 3 && !stack_sorted(*a))
    {
        init_param_a(*a, *b);
        moves_a(a, b);
    }
    sort_3(a);
    while(*b)
    {
        init_param_a(*a, *b);
        moves_b(a, b);
    }
    set_index(*a);
    final_move(a);
    // stack_i *tmp2 = (*a);
    // while(tmp2)
    // {
    //     printf("a->next = %d\n", tmp2->data);
    //     tmp2 = tmp2->next;
    // }
}