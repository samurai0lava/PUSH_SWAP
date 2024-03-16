//algo that will do it all
//MNIN ANBDAHAA

#include "../push_swap.h"

void push_swap(stack_i **a, stack_i **b, int size)
{
    if(isEmpty(*a) || *a == NULL)
    {   
        ft_putendl_fd("stack is Empty : <usage>", 2);
        return ;
    }
    // if(size == 1 || stack_sorted(*a))
    // {
    //     ft_printf("stack already sorted\n");
    //     return ;
    // }
    else if (size == 2)
    {
        printf("%d\n", size);
        print_stack(*a);
        swap(a, "sa");
    }
    else if (size == 3)
        sort_3(a);
    else if (size > 3 && size <= 5)
        sort_5(a, b, size);
    else
    {
        ft_printf("Array too large for this implementation.\n");
        return ;
    }
}

// int is_it_sorted(stack_i *a) 
// {
//     if (a == NULL || a->next == NULL)
//         return (1);

//     stack_i *tmp; 
    
//     tmp = a;
//     while (tmp->next)
//     {
//         if (tmp->data > tmp->next->data)
//             return (0);
//         tmp = tmp->next;
//     }
//     return (1);
// }

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

void print_stack(stack_i *stack) 
{
    stack_i *current ;
    
    current = stack;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

