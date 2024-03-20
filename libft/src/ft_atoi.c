/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:37:41 by iouhssei          #+#    #+#             */
/*   Updated: 2023/11/23 12:44:50 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

long double	ft_atoi(char *str, char **array, int *arr)
{
	int			sign;
	long double	return_value;

	sign = 1;
	return_value = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		return_value = return_value * 10 + (*str - 48);
		str++;
	}
	if (return_value > INT_MAX || return_value < INT_MIN)
	{
		free_arr(array);
		free(arr);
		ft_putendl_fd("Error", 2);
		exit (1);
	}
	return (return_value * sign);
}
