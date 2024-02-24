#include "push_swap.h"

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

int *parsing(int argc, char **argv)
{
    char **splitted;
    int *array;
    int i;
    int size;

    if (argc < 2 || argv == NULL)
        return (NULL);
    if(check_inputs(argc, argv) == 1)
        error_quit("Invalid set of arguments: <usage>");
    splitted = split_args(argc, argv);
    array = atoi_ad(argc, splitted);
    size = size_sp(splitted);
    // for (int i = 0; i < size; i++)
    //     ft_printf("%d", array[i]);
    // ft_printf("\n");
    if(check_duplicate(array, size) == 1)
    {
        error_quit("Error : Duplicate");
        free(array);
    }
    else
        return(array);
    return(NULL);   
}