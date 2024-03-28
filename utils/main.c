/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:40:03 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 15:40:08 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	sort_all(t_stack *a, t_stack *b, int size)
{
	if (!stack_sorted(a) || !isempty(a))
	{
		if (size == 2)
			swap(&a, 'a');
		else if (size == 3)
			sort_3(&a);
		else if (size > 3 && size <= 5)
			sort_5(&a, &b, size);
		else
			push_swap(&a, &b);
		freestack(a);
	}
	else
		freestack(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_array	*re;
	int		size;

	re = NULL;
	a = NULL;
	b = NULL;
	if (1 == argc)
		return (0);
	else
	{
		re = parsing(argc, argv);
		if (re == NULL)
			return (1);
		init(&a, re);
		size = re->size;
		free (re->array);
		free (re);
		sort_all(a, b, size);
	}
	return (0);
}
