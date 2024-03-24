#include "../push_swap.h"

static void	rotate_both(stack_i **a, stack_i **b, stack_i *cheapest_node) 
{
	while ((*b) != cheapest_node->target && (*a) != cheapest_node) 
    {
		rotate(a, "rr");
        rotate(b, "\n");
    }
	set_index(*a);
	set_index(*b);
}

static void	rev_rotate_both(stack_i **a, stack_i **b, stack_i *cheapest_node) 
{
	while (*b != cheapest_node->target && *a != cheapest_node) 
	{
        reverseRotate(a, "rr");
        reverseRotate(b, "\n");
    }
	set_index(*a); 
	set_index(*b);
}
void	prep_for_push(stack_i **stack, stack_i *top_node, char stack_name) 
{
	while (*stack != top_node && (*stack)->next != NULL) 
	{
		if (stack_name == 'a') 
		{
			if (top_node->median_top)
				rotate(stack, "ra\n");
			else
				reverseRotate(stack, "rra\n");
		}
		else if (stack_name == 'b') 
		{
			if (top_node->median_top)
				rotate(stack, "rb\n");
			else
				reverseRotate(stack, "rrb\n");
		}
        (*stack) = (*stack)->next;	
	}
}
void	final_move(stack_i **a) 
{
	while ((*a)->data != find_min_node(*a)->data)
	{
		if (find_min_node(*a)->median_top) 
			rotate(a, "ra\n");
		else
			reverseRotate(a, "rra\n");
	}
}

void moves_a(stack_i **a, stack_i **b)
{
    stack_i *cheapest;

    cheapest = get_cheapest(*a);
    if(cheapest->median_top && cheapest->target->median_top)
        rotate_both(a, b, cheapest);
    else if (!(cheapest->median_top) && !(cheapest->target->median_top))
        rev_rotate_both(a, b, cheapest);
    prep_for_push(a, cheapest, 'a');
    prep_for_push(b, cheapest->target, 'b');
    push(a, b, "pb\n");
}

void moves_b(stack_i **a, stack_i **b)
{
    prep_for_push(a, (*b)->target, 'a');
    push(b, a, "pa\n");
}

