/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:26:46 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 16:26:48 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_min_node(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	find_min(t_stack *a)
{
	long	min;

	min = LONG_MAX;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	return (min);
}

void	sort_5(t_stack **a, t_stack **b, int size)
{
	int		min;
	t_stack	*tmp;
	int		index;

	index = get_index(*a, find_min(*a));
	while (stack_len(*a) > 3)
	{
		tmp = *a;
		min = find_min(*a);
		if (tmp->data == min)
			push(a, b, 'b');
		else
		{
			if (index <= size / 2)
				rotate(a, 'a');
			else
				reverserotate(a, 'a');
		}
	}
	if (!stack_sorted(*a))
		sort_3(a);
	while (*b != NULL)
		push(b, a, 'a');
}
