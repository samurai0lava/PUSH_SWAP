/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:12:13 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 16:16:58 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	reverserotate(t_stack **head, char type)
{
	t_stack	*temp;
	t_stack	*newlast;

	temp = *head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	newlast = temp->next;
	newlast->next = *head;
	(*head)->prev = newlast;
	temp->next = NULL;
	newlast->prev = NULL;
	*head = newlast;
	if (type == 'a')
		ft_printf("rra\n");
	else if (type == 'b')
		ft_printf("rrb\n");
}

void	rotate(t_stack **stack, char type)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (type == 'a')
		ft_printf("ra\n");
	else if (type == 'b')
		ft_printf("rb\n");
}

void	swap(t_stack **head, char type)
{
	t_stack	*first;
	t_stack	*second;

	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	*head = second;
	if (type == 'a')
		ft_printf("sa\n");
	else if (type == 'b')
		ft_printf("sb\n");
}

void	push(t_stack **a, t_stack **b, char type)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (type == 'a')
		ft_printf("pa\n");
	else if (type == 'b')
		ft_printf("pb\n");
}
