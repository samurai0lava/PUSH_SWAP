#include <stdio.h>

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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

int main(int ac, char **av)
{
    int r = check_inputs(ac, av);
    if (r == 0)
        printf("ok\n");
    else    
        printf("error\n");
}