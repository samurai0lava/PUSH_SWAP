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
	i = 1 ;
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
			else if (argv[i][j] == '+' && argv[i][j + 1] == '\0')
				return (1);
			else if (argv[i][j] == '-' && argv[i][j + 1] == '\0')
				return (1);
			else if (argv[i][j] == '+' && argv[i][j + 1] == ' ')
				return (1);
			else if (argv[i][j] == '-' && argv[i][j + 1] == ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char **split_args(int argc, char **argv) 
{
    int i;
    char *arg;
    char **splitted;
    size_t total_length;

    if (argc < 2 || argv == NULL)
        return NULL;
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

int *atoi_ad(int argc, char **splitted)
{
	int i;
	int *array;

	i = 0;
	array = (int *)malloc(sizeof(*splitted) * sizeof(int));
	if (!array)
		return(NULL);
	while (splitted[i])
	{
		array[i] = ft_atoi(splitted[i]);
		i++;
	}
	return (array);
}

// int main(int argc, char **argv)
// {
// 	int *array = parsing(argc, argv);
// 	if (array == NULL)
// 	{
// 		error_quit("error ?");
// 		return 1;	
// 	}
// 	return 0;
// }