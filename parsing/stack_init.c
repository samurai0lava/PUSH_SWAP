/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:52:47 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/04 16:53:43 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stack_i	*find_last_node(stack_i *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void append_node(stack_i **stack, int nbr)
{
    stack_i *node;
    stack_i *last_node;

    if (stack == NULL)
        return;

    node = malloc(sizeof(stack_i));
    if (node == NULL)
        return;

    node->next = NULL;
    node->data = nbr;
    if (*stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        node->prev = last_node;
        last_node->next = node;
    }
}

void init(stack_i **a, array_s *re) 
{
    int i;

    *a = createStack(re->array[0]);
    if (*a == NULL)
    {
        ft_putendl_fd("Error\n", 2);
        return;
    }
    i = 1;
    while (i < re->size) 
    {
        append_node(a, re->array[i]);
        i++;
    } 
    free (re->array);
    free (re);
}
