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

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	return_value;
	long int	check;

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
		check = return_value;
		return_value = return_value * 10 + (*str - 48) * sign;
		if (return_value > check && sign < 0)
			return (0);
		if (return_value < check && sign > 0)
			return (-1);
		str++;
	}
	return (return_value);
}
