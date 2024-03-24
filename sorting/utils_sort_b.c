#include "../push_swap.h"

void set_target_b(stack_i *a, stack_i *b)
{
    stack_i *current_a;
    stack_i *target_node;
    long    best_match;

    target_node = NULL;
    while (b)
    {
        current_a = a;
        best_match = LONG_MAX;
        while(current_a)
        {
            if(current_a->data < best_match && current_a->data > b->data)
            {
                best_match = current_a->data;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match == LONG_MAX)
            b->target = find_min_node(a);
        else
            b->target = target_node;
        b = b->next;
    }
}

stack_i	*get_cheapest(stack_i *stack) 
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void init_param_b(stack_i *a, stack_i *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a ,b);
}