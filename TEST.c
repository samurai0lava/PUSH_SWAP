// // Remove the incompatible language modes
// // #include "push_swap.h"
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct stack_node
// {
//     int current_position;
//     int data;

//     struct stack_node *top;
//     struct stack_node *next;
//     struct stack_node *prev;
// } stack_i;

// void	swap(stack_i **head, char *str)
// {
// 	if (NULL == *head || NULL == (*head)->next)
// 		return ;
// 	*head = (*head)->next;
// 	(*head)->prev->prev = *head;
// 	(*head)->prev->next = (*head)->next;
// 	if ((*head)->next)
// 		(*head)->next->prev = (*head)->prev;
// 	(*head)->next = (*head)->prev;
// 	(*head)->prev = NULL;
//     printf("%s",str);
// }
// void    push(stack_i* stack, int data) 
// {
//     stack_i* newNode;
    
//     newNode = (struct stack_node*)malloc(sizeof(struct stack_node));
//     if (!newNode)
//         return;
//     newNode->data = data;
//     newNode->next = stack->top;
//     newNode->prev = NULL;
//     if (stack->top != NULL) 
//         stack->top->prev = newNode;
//     stack->top = newNode;
// }
// void print_stack(stack_i *stack) 
// {
//     stack_i *current ;
    
//     current = stack;
//     while (current != NULL) 
//     {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// int main()
// {
//     stack_i *a;
//     a = NULL;

//     push(a, 1);
//     push(a, 2);
//     push(a, 3);
//     push(a, 4);
//     push(a, 5);

//     print_stack(a);

//     printf("after swap\n");
//     swap(&a, "sa");
//     print_stack(a);
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node
{
    int data;
    struct stack_node *next;
    struct stack_node *prev;
} stack_i;

void swap(stack_i **head, char *str)
{
    if (NULL == *head || NULL == (*head)->next)
        return;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
    printf("%s", str);
}

void push(stack_i **stack, int data)
{
    stack_i *newNode = (struct stack_node *)malloc(sizeof(struct stack_node));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = *stack;
    newNode->prev = NULL;
    if (*stack != NULL)
        (*stack)->prev = newNode;
    *stack = newNode;
}

void print_stack(stack_i *stack)
{
    stack_i *current = stack;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    stack_i *a = NULL;

    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    push(&a, 4);
    push(&a, 5);

    print_stack(a);

    printf("after swap\n");
    swap(&a, "sa");
    print_stack(a);

    return 0;
}
