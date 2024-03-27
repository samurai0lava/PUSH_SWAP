#include "../push_swap.h"
static void	set_target_a(stack_i *a, stack_i *b)
{
	stack_i	*current_b; 
	stack_i	*target; 
	long	best_match_index; 

	while (a) 
	{
		best_match_index = LONG_MIN; 
		current_b = b; 
		while (current_b) 
		{
			if (current_b->data < a->data 
				&& current_b->data > best_match_index) 
			{
				best_match_index = current_b->data; 
				target = current_b; 
			}
			current_b = current_b->next; 
		}
		if (best_match_index == LONG_MIN) 
			a->target = find_max(b); 
		else
			a->target = target; 
		a = a->next; 
	}
}

void	set_cheapest(stack_i *stack) 
{
	long			cheapest_value; 
	stack_i			*cheapest_node; 

	if (!stack) 
		return ;
	stack->cheapest = 0;
	cheapest_value = LONG_MAX;
	while (stack) 
	{
		if (stack->cost < cheapest_value) 
		{
			cheapest_value = stack->cost; 
			cheapest_node = stack; 
		}
		stack = stack->next; 
	}
	cheapest_node->cheapest = true;
}


void	set_index(stack_i *stack)
{
	int	i; 
	int	median; 

	i = 0; 
	if (!stack) 
		return ;
	median = stack_len(stack) / 2; 
	while (stack) 
	{
		stack->current_position = i; 
		if (i <= median)
			stack->median_top = true;
		else
			stack->median_top = false;
		stack = stack->next; 
		i++;
	}
}

void	set_price_a(stack_i *a, stack_i *b) 
{
	int	len_a; 
	int	len_b; 

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a) 
	{
		a->cost = a->current_position; 
		if (!(a->median_top)) 
			a->cost = len_a - (a->current_position); 
		if (a->target->median_top) 
			a->cost += a->target->current_position; 
		else 
			a->cost += len_b - (a->target->current_position); 
		a = a->next; 
	}
}

void init_param_a(stack_i *a, stack_i *b)
{
    set_index(a);
    set_index(b);
    set_target_a(a, b);
    set_price_a(a, b);
    set_cheapest(a);
}