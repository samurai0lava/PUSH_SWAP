/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:19:47 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:55 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	error_quit(char *str)
{
	ft_putendl_fd(str, 2);
	return ;
}

int	size_sp(char **splited)
{
	int	size;

	size = 0;
	while (splited[size] != NULL)
		size++;
	return (size);
}

int	*atoi_ad(char **splitted, t_array *re)
{
	int	i;
	int	*array;
	int	size;

	array = NULL;
	i = 0;
	size = size_sp(splitted);
	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (splitted[i])
	{
		array[i] = ft_atoiv2(splitted[i], splitted, array, re);
		i++;
	}
	return (array);
}
