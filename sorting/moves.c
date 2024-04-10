/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:20:06 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 16:20:07 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rr(t_stack **a, t_stack **b, char c)
{
	rotate(a, '1');
	rotate(b, '1');
	if (c == '1')
		ft_printf("rr\n");
}
void rrr(t_stack **a, t_stack **b, char c)
{
	reverserotate(a, '1');
	reverserotate(b, '1');
	if (c == '1')
		ft_printf("rrr\n");

}
static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*b) != cheapest_node->target && (*a) != cheapest_node)
	{
		rr(a, b,'1');
		set_index(*a);
		set_index(*b);
	}
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*b) != cheapest_node->target && (*a) != cheapest_node)
	{
		rrr(a ,b, '1');
		set_index(*a);
		set_index(*b);
	}
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (!(top_node->median_top))
				reverserotate(stack, 'a');
			else
				rotate(stack, 'a');
		}
		else if (stack_name == 'b')
		{
			if (top_node->median_top)
				rotate(stack, 'b');
			else
				reverserotate(stack, 'b');
		}
	}
}

void	moves_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if ((cheapest->median_top) && (cheapest->target->median_top))
		{rotate_both(a, b, cheapest);}
	else if (!(cheapest->median_top) && !(cheapest->target->median_top))
		{rev_rotate_both(a, b, cheapest);}
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target, 'b');
	push(a, b, 'b');
}

void	moves_b(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	push(b, a, 'a');
}
