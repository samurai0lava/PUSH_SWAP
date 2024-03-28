/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:53:54 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/04 16:54:03 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	check_duplicate(int *array, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	validate_inputs(int argc, char **argv, t_array *re)
{
	if (check_inputs(argc, argv) == 1 || check_inputs2(argc, argv) == 1)
	{
		error_quit("Error");
		free(re);
		return (1);
	}
	return (0);
}

static int	check_for_duplicates(t_array *re, char **splitted)
{
	if (check_duplicate(re->array, re->size) == 1)
	{
		error_quit("Error");
		free(re->array);
		free(re);
		free_array(splitted);
		return (1);
	}
	return (0);
}

t_array	*parsing(int argc, char **argv)
{
	t_array	*re;
	char	**splitted;

	re = (t_array *)malloc(sizeof(t_array));
	if (re == (NULL))
		error_quit("Error");
	if (validate_inputs(argc, argv, re) == 1)
		return (NULL);
	splitted = split_args(argc, argv);
	if (splitted == (NULL))
	{
		free(re);
		return (NULL);
	}
	re->array = atoi_ad(splitted, re);
	re->size = size_sp(splitted);
	if (check_for_duplicates(re, splitted) == 1)
		return (NULL);
	free_array(splitted);
	return (re);
}
