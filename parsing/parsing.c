/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:13 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/04 16:42:07 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_inputs(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc) 
	{
		if(empty(argv[i]) == 1)
			return 1;
		j = 0;
		while (argv[i][j])
		{	

			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-')
				return (1);
			if ((argv[i][j] == '+' || argv[i][j] == '-') && (argv[i][j + 1] == '+' || argv[i][j + 1] == '-' \
                                        || argv[i][j + 1] == '\0' || argv[i][j + 1] == ' '))
				return (1);
			if((argv[i][j] == '+' || argv[i][j] == '-') && (ft_isdigit(argv[i][j - 1])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


char	**split_args(int argc, char **argv) 
{
    int		i;
    char	*arg;
    char	**splitted;
    size_t	total_length;

    if (argc < 2 || argv == NULL)
	{
        return (NULL);
	}
	arg = NULL;
	splitted = NULL;
	total_length = 0;
	i = 1;
	while (i < argc)
	{
		total_length += ft_strlen(argv[i]);
		i++;
	}
	arg = (char *)malloc(total_length + argc - 1);
	if (!arg)
		return (NULL);
	arg[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strlcat(arg, argv[i], total_length + argc - 1); 
		if (i < argc - 1)
			ft_strlcat(arg, " ", total_length + argc - 1); 
		i++;
	}
	splitted = ft_split(arg, ' ');
	free(arg);
	return (splitted);
}

int	size_sp(char **splited)
{
	int	size;

	size = 0;
	while (splited[size] != NULL)
		size++;
	return (size);
}

int	*atoi_ad(char **splitted)
{
	int	i;
	int	*array;
	int size;

	array = NULL;
	i = 0;
	size = size_sp(splitted);
	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (splitted[i])
	{
		array[i] = ft_atoiv2(splitted[i], splitted, array);
		i++;
	}
	return (array);
}
