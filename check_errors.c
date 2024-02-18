#include "push_swap.h"
#include "libft/libft.h"

int check_errors_if_string(char *str)
{
	//i itterate the whole string finding other tahn spaces and numbers
	//if the itteration gone to the end means that th eitterator == size of the string and its point at '\0;
	//then return 0;
	//else return 1;
	int i;
	int size;
	int j;

	size = ft_strlen(str);
	i = 0;
	while((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
	{
		i++;
	}
	if(i == size)
		return(0);
	else
		return(1);

	// then we check the duplicate...i mean where i even start maybe a search algorithm maybeee...
	//its bubble sort but not for storting its for search
	i = 0;
	while (i < size)
    {
        j = 0;
        while(j < size - i - 1)
        {
            if(str[j] == str[j + 1])
                return(1);
            j++;
        }
        i++;
    }
}

// int check_errors_if_args(char **argv)
// {
	
// }
int main(int argc, char **argv)
{
	int i;

	i = 0;
	if(check_errors_if_string(argv[1]) == 0)
	{
		ft_printf("NO ERRORS");
	}
	else
	{
		"invalid input");
	}
}