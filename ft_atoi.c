#include "push_swap.h"

int ft_atoi(char *str)
{
    if(str == NULL)
        return (1);
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
		str++;
	}
	return (return_value);
}