#include "../push_swap.h"

void reverseRotate(stack_i **head, char *str) 
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
    ft_printf(str);
}

static void	rotate(stack_i **stack, char *str) 
{
	stack_i	*last_node; 

	if (!*stack || !(*stack)->next) 
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack; 
	*stack = (*stack)->next; 
	(*stack)->prev = NULL; 
	last_node->next->prev = last_node; 
	last_node->next->next = NULL; 
    ft_printf(str);
}

void swap(stack_i **head, char *str)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    stack_i *first = *head;
    stack_i *second = first->next;

    first->next = second->next;
    first->prev = second;
    if (second->next != NULL)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;

    *head = second;
    ft_printf(str); 
}

void push(stack_i **a, stack_i **b, char *str)
{
    stack_i *tmp;
    if(!*a)
        return ;
    tmp = *a;
    (*a) = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    ft_printf(str);
}