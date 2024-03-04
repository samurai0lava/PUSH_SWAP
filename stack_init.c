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

#include "push_swap.h"

void init(stack_i **a, array_s *re) 
{
    int i;

	*a = createStack();
	if (*a == NULL)
	{
		ft_putendl_fd("Error: Failed to initialize stack\n", 2);
		return;
	}
	i = 0;
	while (i < re->size) 
	{
		push(*a, re->array[i]);
		i++;
	}
}
