#include "../push_swap.h"

void set_target(stack_i *a, stack_i *b)
{
    stack_i *current;
    stack_i *target;
    long    best_match;

    while (b)
    {
        current = a;
        best_match = LONG_MAX;
        while(current)
        {
            if(current->data < best_match && current->data > b->data)
            {
                best_match = current->data;
                target = current;
            }
            current = current->next;
        }
        if(best_match == LONG_MAX)
            b->target->data = find_min(a);
        else
            b->target = target;
        b = b->next;
    }
}

void set_cheapest(stack_i *b)
{
	stack_i	*current;
	stack_i	*cheapest;
    
	if (!b)
        return;

    current = b;
    cheapest = b;
    while (current) 
	{
        if (current->cost < cheapest->cost) 
            cheapest = current;
        current = current->next;
    }
    cheapest->cheapest = 1;
    current = b;
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
		a = a->next;
	}
}

void set_price(stack_i *a, stack_i *b)
{
    int len_stack_a;
	int	len_stack_b;
	
    if (!b)
        return;
	len_stack_a = stack_len(a);
    len_stack_b = stack_len(b);

    while (b)
    {
        b->cost = b->current_position;
        if (b->median_top == 1)
            b->cost = len_stack_b - b->current_position;
        else if (b->median_top == 0)
            b->cost += b->target->current_position;
        else
            b->cost += len_stack_a - b->target->current_position;
        b = b->next;
    }
}

void init_param(stack_i *a, stack_i *b)
{
	set_index(a);
	set_index(b);
	set_target(a ,b);
    printf("allo\n");
	set_price(a,b);
	set_cheapest(b);
}