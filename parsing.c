#include "push_swap.h"

void error_quit(char *str)
{
	ft_putendl_fd(str, 2);
	return;
}
void check_inputs(int argc, char **str)
{
	//i itterate the whole string finding other tahn spaces and numbers
	//if the itteration gone to the end means that th eitterator == size of the string and its point at '\0;
	//then return 0;
	//else return 1;
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while(ft_isdigit(str[i][j]) || str[i][j] == ' ' || str[i][j] == '+' || str[i][j] == '-')
			j++;
		if(str[i][j] != '\0')
			error_quit("Invalid set of arguments: <usage>");
		i++;
	}
	// then we check the duplicate...i mean where i even start maybe a search algorithm maybeee...
	// its bubble sort but not for storting its for search
	// i = 0;
	// while (i < size)
    // {
    //     j = 0;
    //     while(j < size - i - 1)
    //     {
    //         if(str[j] == str[j + 1])
    //             error_quit("Error : Duplicate");
    //         j++;
    //     }
    //     i++;
    // }
}
//./push_swap " 1 2" "1 0" 1 3 77 9 "" = 
char **split_args(int argc,char **argv)
{
	int i;
	int j;
	static char *arg;
	char **splitted;
	i = 2;

	while(argv[i] != '\0')
	{
		arg = ft_strjoin(argv[1], argv[i]);
		i++;
	}
	free(argv);
	splitted = ft_split(arg, ' ');
}

int sizeof_argv(char **argv)
{
	int size;
	//calculate the size of the argv splited (how much integer need to be parsed)

	return (size);
}
int *atoi_ad(int argc, char **splitted)
{
	int i;
	int size;
	int *array;

	size = sizeof_argv(splitted);
	array = (int *)malloc(size * sizeof(int));
	if(!array)
		return(1);
	while (splitted[i])
	{
		array[i] = ft_atoi(splitted[i]);
		i++;
	}
	return(array);
}
void check_duplicate(int *array)
{
	int i;
	int size;

	i = 0;
	while (i < size)
    {
        j = 0;
        while(j < size - i - 1)
        {
            if(array[j] == array[j + 1])
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
	
	check_inputs(argc ,argv);
	splitted = split_args(argc, argv);
	array = atoi_ad(argc, splitted);
	check_duplicate(array);
	return (0);
}