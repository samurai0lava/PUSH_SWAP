#include "../push_swap.h"

void reverseRotate(stack_i **head, char *str) 
{
	stack_i *temp;
    stack_i *newLast;

	if (isEmpty(*head)) 
        return;
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
    ft_printf(str, 1);
}

void rotate(stack_i **head, char *str) 
{
    stack_i *temp;
    stack_i *newLast;

    if (isEmpty(*head)) 
        return;
    temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    newLast = *head;
    temp->next = newLast;
    newLast->prev = temp;
    *head = (*head)->next;
    (*head)->prev = NULL;
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

void    push(stack_i* stack, int data) 
{
    stack_i* newNode;
    
    newNode = (struct stack_node*)malloc(sizeof(struct stack_node));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = stack->top;
    newNode->prev = NULL;
    if (stack->top != NULL) 
        stack->top->prev = newNode;
    stack->top = newNode;
}