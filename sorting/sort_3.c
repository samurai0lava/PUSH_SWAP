#include "../push_swap.h"

stack_i	*find_max(stack_i *stack) 
{
	long			max; 
	stack_i	*max_node; 

	if (!stack)
		return (NULL);
	max = LONG_MIN; 
	while (stack) 
	{
		if (stack->data > max) 
		{
			max = stack->data; 
			max_node = stack; 
		}
		stack = stack->next; 
	}
	return (max_node);
}

void	sort_3(stack_i **a) 
{
	stack_i	*biggest_node; 

	biggest_node = find_max(*a);
	if (biggest_node == *a) 
		rotate(a, 'a'); 
	else if ((*a)->next == biggest_node) 
		reverseRotate(a, 'a'); 
	if ((*a)->data > (*a)->next->data) 
		swap(a, 'a');
}

