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
void split_args(int argc,char **argv)
{
	int i;
	int j;
	static char *arg;
	i = 2;

	while(argv[i] != '\0')
	{
		arg = ft_strjoin(argv[1], argv[i]);
		i++;
	}
	free(argv);
	argv = ft_split(arg, ' ');
}

int sizeof_argv(char **argv)
{
	int size;

	return (size);
}
int *atoi_ad(int argc, char **argv)
{
	int *array;
	int i;

	array = (int *)malloc(argc * sizeof(int));
	if(!array)
		error_quit("Error : Malloc Failed!");
	while (argv[i])
	{
		
	}
}



int main(int argc, char **argv)
{
	check_inputs(argc ,argv);
}