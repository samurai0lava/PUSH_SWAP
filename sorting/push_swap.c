/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:21:35 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 16:21:41 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		push(a, b, 'b');
	if (len_a-- > 3 && !stack_sorted(*a))
		push(a, b, 'b');
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_param_a(*a, *b);
		moves_a(a, b);
	}
	sort_3(a);
	while (*b)
	{
		init_param_b(*a, *b);
		moves_b(a, b);
	}
	set_index(*a);
	final_move(a);
}
