/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:54:26 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/04 16:54:29 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stack_i *createStack(int content) 
{
    stack_i* stack; 
    
    stack = (stack_i*)malloc(sizeof(stack_i));
    if (!stack) 
        return (NULL);
    stack->top = NULL;
    stack->data = content;
    return (stack);
}

int isEmpty(stack_i* stack)
{
    return((stack -> top) == NULL);
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

int stack_len(stack_i *stack)
{    
    if(isEmpty(stack))
        return 0;
    int len = 0;
    stack_i *temp = stack;
    
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    
    return len;
}

// int pop(struct stack_node* stack) 
// {
//     if (isEmpty(stack)) 
//         return(1);
//     struct  stack_node* temp;
//     int     data;

//     temp = stack->top;
//     data = temp->data;
//     stack->top = temp->next;
//     if (stack->top != NULL) 
//         stack->top->prev = NULL;
//     free(temp);
//     return data;
// }


// int main(int argc, char **argv)
// {
//     int     i; 
//     stack_i *stack;

//     if (argc < 2) 
//     {
//         ft_printf("dumb ass bitch");
//         return 1;
//     }
//     if(argc == 2)
//     {   
//     }
//     i = 1;
//     stack = createStack();
//     while(argv[i])
//     {
//         push(stack, atoi(argv[i]));
//         i++;
//     }
//     printf("Elements of the stack after pushing:\n");
//     struct stack_node* current = stack->top;
//     while (current != NULL) 
//     {
//         printf("%d\n", current->data);
//         current = current->next;
//     }
//     return 0;
// }
