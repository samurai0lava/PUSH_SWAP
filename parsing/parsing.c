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
		if (empty(argv[i]) == 1)
			return (1);
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-') \
							&& (ft_isdigit(argv[i][j - 1])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_inputs2(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' \
							&& argv[i][j] != '+' && argv[i][j] != '-')
				return (1);
			if ((argv[i][j] == '+' || argv[i][j] == '-') \
					&& (argv[i][j + 1] == '+' || argv[i][j + 1] == '-' \
					|| argv[i][j + 1] == '\0' || argv[i][j + 1] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	total_l(int argc, char **argv)
{
	int		i;
	size_t	total_length;

	total_length = 0;
	i = 1;
	while (i < argc)
	{
		total_length += ft_strlen(argv[i]);
		i++;
	}
	return (total_length);
}

static void	split_arg(int argc, char **argv, char *arg)
{
	int		i;
	size_t	total_length;

	total_length = total_l(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_strlcat(arg, argv[i], total_length + argc - 1);
		if (i < argc - 1)
			ft_strlcat(arg, " ", total_length + argc - 1);
		i++;
	}
}

char	**split_args(int argc, char **argv)
{
	char	*arg;
	char	**splitted;
	size_t	total_length;

	if (argc < 2 || argv == NULL)
		return (NULL);
	arg = NULL;
	splitted = NULL;
	total_length = total_l(argc, argv);
	arg = (char *)malloc(total_length + argc - 1);
	if (!arg)
		return (NULL);
	arg[0] = '\0';
	split_arg(argc, argv, arg);
	splitted = ft_split(arg, ' ');
	free(arg);
	return (splitted);
}
