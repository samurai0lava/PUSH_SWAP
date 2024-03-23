
#include "../push_swap.h"

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	stack_i	*current_b;
	stack_i	*target_node;
	long	best_match;

    target_node = NULL;
	while (a)
	{
		best_match= LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr 
				&& current_b->nbr > best_match_index) 
			{
				best_match= current_b->data; 
				target_node = current_b; 
			}
			current_b = current_b->next; 
		}
		if (best_match == LONG_MIN) 
			a->target= find_min_node(b); 
		else
			a->target= target_node; 
		a = a->next; 
	}
}

void set_cheapest(stack_i *stack)
{
	stack_i	*current;
	stack_i	*cheapest;
    
	if (!stack)
        return;

    current = stack;
    cheapest = stack;
    while (current) 
	{
        if (current->cost < cheapest->cost) 
            cheapest = current;
        current = current->next;
    }
    cheapest->cheapest = 1;
    current = stack;
    while (current) 
	{
        if (current != cheapest) 
            current->cheapest = 0;
        current = current->next;
    }
}

void set_index(stack_i *a)
{
	int index_S;
	int size;

    if (!a)
        return;
	size = stack_len(a);
	while(a)
	{
		index_S = get_index(a, a->data);
		a->current_position = index_S;
		if(index_S > size/2)
			a->median_top = 0;
		else
			a->median_top = 1;
		a = a->next
	}
}

void set_price_a(stack_i *a, stack_i *b)
{
    int len_stack_a;
	int	len_stack_b;
	
	len_stack_a = stack_len(a);
    len_stack_b = stack_len(b);

    while (a)
    {
        a->cost = a->current_position;
        if (a->median_top == 1)
            a->cost = len_stack_a - a->current_position;
        else if (a->median_top == 0)
            a->cost += a->target->current_position;
        else
            a->cost += len_stack_a - a->target->current_position;
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