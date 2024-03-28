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
    stack->next = NULL;
    stack->top = NULL;
    stack->data = content;
    return (stack);
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

void freestack(stack_i *stack) 
{
    stack_i *current;
    stack_i *temp;

    current = stack;
    while (current != NULL) 
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

void free_array(char **str)
{
    int i;

    i = 0;
    while(str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
}