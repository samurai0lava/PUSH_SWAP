#include "../push_swap.h"

int empty(char *str)
{
	int i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void error_quit(char *str)
{
	ft_putendl_fd(str, 2);
	return;
}