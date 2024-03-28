#include "../push_swap.h"

void	final_move(stack_i **a) 
{
	while ((*a)->data != find_min_node(*a)->data)
	{
		if (find_min_node(*a)->median_top)
			rotate(a, 'a');
		else
			reverseRotate(a, 'a');
	}
}

int	get_index(stack_i *stack, int data)
{
    int	index;

	index = 0;
    while (stack)
    {
        if (stack->data == data)
            return index;
        index++;
        stack = stack->next;
    }
    return (index);
}

int	stack_sorted(stack_i *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int isEmpty(stack_i* stack)
{
    return((stack -> top) == NULL);
}

int stack_len(stack_i *stack)
{
    int len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return len;
}