#include "push_swap.h"

void error_quit(char *str)
{
	ft_putendl_fd(str, 2);
	return;
}
void check_inputs(int argc, char **argv) 
{
    int i; 
	int j;

    for (i = 1; i < argc; i++) {
        j = 0;
        while (argv[i][j]) {
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-')
                error_quit("Invalid set of arguments: <usage>");
            j++;
        }
    }
}

char **split_args(int argc, char **argv)
{
	int i;
	int j;
	static char *arg;
	char **splitted;
	i = 2;

	while (argv[i] != NULL)
	{
		arg = ft_strjoin(argv[1], argv[i]);
		i++;
	}
	splitted = ft_split(arg, ' ');
	return (splitted);
}

int *atoi_ad(int argc, char **splitted)
{
	int i;
	int *array;

	i = 0;
	array = (int *)malloc(sizeof(*splitted) * sizeof(int));
	while (splitted[i])
	{
		array[i] = ft_atoi(splitted[i]);
		i++;
	}
	return (array);
}

int check_duplicate(int *array)
{
	int i;
	int size;
	int j;

	size = sizeof(*array) / sizeof(int);
	printf("%d", size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] == array[j + 1])
				error_quit("Error : Duplicate");
			j++;
		}
		i++;
	}
	return (size);
}

int main(int argc, char **argv)
{
	char **splitted;
	int *array;
	int i;

	check_inputs(argc, argv);
	splitted = split_args(argc, argv);
	// for (i = 0; splitted[i]; i++)
	// 	ft_printf("%s\n", splitted[i]);
	// array = atoi_ad(argc, splitted);

	// int size = check_duplicate(array);
	// for (i = 0; i < size; i++)
	// 	ft_printf("%d\n", array[i]);
	// return (0);
}