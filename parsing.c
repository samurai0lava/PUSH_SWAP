#include "push_swap.h"

void error_quit(char *str)
{
	ft_putendl_fd(str, 2);
	return;
}
int check_inputs(int argc, char **argv) 
{
    int i; 
	int j;

	i = 1;
    while (i < argc) 
	{
        j = 0;
        while (argv[i][j]) 
		{
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-')
                return(1);
            j++;
        }
		i++;
    }

	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] == '-' && argv[i][j+1] == '-')
				return (1);
			else if (argv[i][j] == '-' && argv[i][j + 1] == '+')
				return (1);
			else if (argv[i][j] == '+' && argv[i][j + 1] == '+')
				return (1);
			else if (argv[i][j] == '+' && argv[i][j + 1] == '-')
				return (1);
			j++;
		}
		i++;
	}
}

// char **split_args(int argc, char **argv)
// {
// 	int i;
// 	int j;
// 	static char *arg;
// 	char **splitted;
// 	i = 1;

// 	while (argv[i] != NULL)
// 	{
// 		arg = ft_strjoin(argv[1], argv[i]);
// 		i++;
// 	}
// 	splitted = ft_split(arg, ' ');
// 	return (splitted);
// }



char **split_args(int argc, char **argv)
{
    if (argc < 2 || argv == NULL) // Check for valid arguments
        return NULL;

    int i;
    char *arg;
    char **splitted;

	arg = NULL;
	splitted = NULL;
    // Calculate total length of arguments
    size_t total_length = 0;
	i = 1;
    while(i < argc) 
	{
        total_length += strlen(argv[i]);
		i++;
    }
    // Allocate memory for concatenated arguments
    arg = (char *)malloc(total_length + argc - 1); // + argc - 1 for space characters
    if (arg == NULL) 
        return NULL; // Memory allocation failed

    // Concatenate all arguments into arg
    arg[0] = '\0'; // Ensure arg is an empty string
	i = 1;
    while(i < argc) 
	{
        strcat(arg, argv[i]);
        if (i < argc - 1) 
            strcat(arg, " "); // Add space between arguments
		i++;
    }

    // Split the concatenated string into separate arguments
    splitted = ft_split(arg, ' ');

    // Free the memory allocated for the concatenated string
    free(arg);

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

void check_duplicate(int *array, int size)
{
	int i;
	int j;

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
}

int main(int argc, char **argv)
{
	char **splitted;
	int *array;
	int i;

	if(check_inputs(argc, argv) == 1)
		error_quit("Invalid set of arguments: <usage>");
		
	splitted = split_args(argc, argv);
	// while (i < 7)
	// {
	// 	printf("%s\n", splitted[i]);
	// 	i++;
	// }
	// for (i = 0; splitted[i]; i++)
	// 	ft_printf("%s\n", splitted[i]);
	array = atoi_ad(argc, splitted);
	i = 0;
	while (i < 5)
	{
		printf("%d\n", array[i]);
		i++;
	}
	check_duplicate(array, 5);
	// for (i = 0; i < size; i++)
	// 	ft_printf("%d\n", array[i]);
	// return (0);
}