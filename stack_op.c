#include "push_swap.h"

//sa Swap the first 2 elements at the top of stack a.
//sb ... same
//ss both of them at the same time
//pa Take the first element at the top of b and put it at the top of a.
//pb ... same
//ra top of the satck a go to the bottom of the stack
//rb same as a..
//rr rotate the both of them
//rra reverse rotate a
//rrb reverse rotate b
//rrr reverse rotate both of them at the same time

void reverseRotate(stack_i **head) 
{
	stack_i *temp;
    stack_i *newLast;

	if (isEmpty(head)) 
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
}

void rotate(stack_i **head) 
{
    stack_i *temp;
    stack_i *newLast;

    if (isEmpty(head)) 
    {
        printf("Not enough elements to rotate!\n");
        return;
    }
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
}
void swap(stack_i **head) 
{
    stack_i *temp;
    stack_i *newLast;

    if (isEmpty(head)) 
    {
        printf("Not enough elements to swap!\n");
        return;
    }
    temp = *head;
    newLast = temp->next;
    temp->next = newLast->next;
    newLast->next = temp;
    newLast->prev = NULL;
    temp->prev = newLast;
    *head = newLast;
}

void printStack(stack_i **head) 
{
    stack_i* temp = *head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
