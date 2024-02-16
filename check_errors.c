#include "push_swap.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}
int check_errors_if_string(char *str)
{
	//i itterate the whole string finding other tahn spaces and numbers
	//if the itteration gone to the end means that th eitterator == size of the string and its point at '\0;
	//then return 0;
	//else return 1;
	int i;
	int size;

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
            if(array[j] == array[j + 1])
                return(1);
            j++;
        }
        i++;
    }
}

int check_errors_if_args(char **argv)
{
	
}
int main(int argc, char **argv)
{

}