/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:12:41 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 17:12:43 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	final_move(t_stack **a)
{
	while ((*a)->data != find_min_node(*a)->data)
	{
		if (find_min_node(*a)->median_top)
			rotate(a, 'a');
		else
			reverserotate(a, 'a');
	}
}

int	get_index(t_stack *stack, int data)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->data == data)
			return (index);
		index++;
		stack = stack->next;
	}
	return (index);
}

int	stack_sorted(t_stack *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	isempty(t_stack	*stack)
{
	return ((stack -> top) == NULL);
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
