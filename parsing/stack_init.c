/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stacknit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:52:47 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/04 16:53:43 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->data = nbr;
	if (*stack == NULL)
	{
		(*stack) = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		node->prev = last_node;
		last_node->next = node;
	}
}

void	init(t_stack **a, t_array *re)
{
	int	i;

	*a = createstack(re->array[0]);
	if (*a == NULL)
	{
		ft_putendl_fd("Error\n", 2);
		return ;
	}
	i = 1;
	while (i < re->size)
	{
		append_node(a, re->array[i]);
		i++;
	}
}
