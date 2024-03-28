/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:33:17 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 15:33:19 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	check_int_max(long double return_value, char **array, int *arr,
														t_array *re)
{
	if (return_value > INT_MAX || return_value < INT_MIN)
	{
		free_array(array);
		free(arr);
		free(re);
		ft_putendl_fd("Error", 2);
		exit (1);
	}
}

long double	ft_atoiv2(char *str, char **array, int *arr, t_array *re)
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
	check_int_max(return_value, array, arr, re);
	return (return_value * sign);
}
