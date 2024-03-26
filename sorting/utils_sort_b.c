#include "../push_swap.h"

static void	set_target_b(stack_i *a, stack_i *b) 
{
	stack_i	*current_a; 
	stack_i	*target; 
	long	best_match_index; 

	while (b)
	{
		best_match_index = LONG_MAX; 
		current_a = a; 
		while (current_a) 
		{
			if (current_a->data > b->data && current_a->data < best_match_index) 
			{
				best_match_index = current_a->data; 
				target = current_a; 
			}
			current_a = current_a->next; 
		}
		if (best_match_index == LONG_MAX) 
			b->target = find_min_node(a); 
		else
			b->target = target; 
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

void	init_param_b(stack_i *a, stack_i *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
