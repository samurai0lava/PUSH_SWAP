#include "../push_swap.h"

void reverseRotate(stack_i **head, char type) 
{
	stack_i *temp;
    stack_i *newLast;

    temp = *head;
    while (temp->next->next != NULL) 
	{
        temp = temp->next;
    }
    newLast = temp->next;
    newLast->next = *head;
    (*head)->prev = newLast;
    temp->next = NULL;
    newLast->prev = NULL;
    *head = newLast;
    if(type == 'a')
        ft_printf("rra\n");
    else if (type == 'b')
        ft_printf("rrb\n");
}

void	rotate(stack_i **stack, char type) 
{
	stack_i	*last_node; 

	if (!*stack || !(*stack)->next) 
		return ;
	last_node = find_last_node(*stack); 
	last_node->next = *stack; 
	*stack = (*stack)->next; 
	(*stack)->prev = NULL; 
	last_node->next->prev = last_node; 
	last_node->next->next = NULL; 
    if(type == 'a')
        ft_printf("ra\n");
    else if (type == 'b')
        ft_printf("rb\n");
}

void swap(stack_i **head, char type)
{
    stack_i *first = *head;
    stack_i *second = first->next;

    first->next = second->next;
    first->prev = second;
    if (second->next != NULL)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;

    *head = second;
    if(type == 'a')
        ft_printf("sa\n");
    else if (type == 'b')
        ft_printf("sb\n");
}

void push(stack_i **a, stack_i **b, char type)
{
    stack_i *tmp;
    if(!*a)
        return ;
    tmp = *a;
    (*a) = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    if(type == 'a')
        ft_printf("pa\n");
    else if (type == 'b')
        ft_printf("pb\n");
}