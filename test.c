#include <stdio.h>
#include <stdlib.h>

int check_duplicate(int *array, int size)
{
	// int i;
	// int j;

	// i = 0;
	// while (i < size)
	// {
	// 	j = 0;
	// 	while (j < size - i - 1)
	// 	{
	// 		if (array[j] == array[j + 1])
	// 			return (1);
	// 		j++;
	// 	}
	// 	i++;
	// }
    // int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (array[i] == array[j]) 
            {
               return(1);
            }
        }
    }
	return (0);
}

int main()
{
    int array[] = {1,1,3,4,7,99,0,1};
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d\n", size);
    if(check_duplicate(array, 8) == 1)
        printf("error");
    else
        printf("all good");
    return (0);
}