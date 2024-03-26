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

void sort_3(stack_i **a)
{
    stack_i *maxNode;
    stack_i *lastNode;
    
    lastNode = find_last_node(*a);
    maxNode = find_max(*a);

    if(maxNode->data == (*a)->data)
    {
        rotate(a, 'a');
        if(!stack_sorted(*a))
            swap(a, 'a');
    }
    else if (maxNode->data == lastNode->data)                
        swap(a, 'a');
    else
    {
        reverseRotate(a, 'a');
        if(!stack_sorted(*a))
            swap(a, 'a');
    }
}
