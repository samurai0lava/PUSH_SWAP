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

void error_quit(char *str)
{
	ft_putendl_fd(str, 2);
	return;
}

int check_duplicate(int *array, size_t size)
{
	size_t i;
	size_t j;

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

array_s *parsing(int argc, char **argv) 
{
    array_s *re;
    char **splitted;

    re = (array_s *)malloc(sizeof(array_s));
    if (re == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }    
    if (argc < 2 || argv == NULL) 
    {
        free(re);
        return NULL;
    }
    if (check_inputs(argc, argv) == 1) 
    {
        error_quit("Invalid set of arguments: <usage>");
        free(re);
        return NULL;
    }
    splitted = split_args(argc, argv);
    if (splitted == NULL) 
    {
        free(re);
        return NULL;
    }
    re->array = atoi_ad(splitted);
    re->size = size_sp(splitted);
    if (check_duplicate(re->array, re->size) == 1) 
    {
        error_quit("Error : Duplicate");
        free(re->array);
        free(re);
        return NULL;
    }
    return re;
}