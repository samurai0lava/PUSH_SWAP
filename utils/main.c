#include "../push_swap.h"
int	main(int argc, char **argv)
{
	stack_i	*a;
	stack_i	*b;
    array_s *re;
    int size;

    re = NULL; 
	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	// else if (2 == argc)
	// 	argv = ft_split(argv[1], ' ');
	// stack_init(&a, argv + 1, 2 == argc);
	// if (!stack_sorted(a))
	// {
	// 	if (stack_len(a) == 2)
	// 		sa(&a, false);
	// 	else if (stack_len(a) == 3)
	// 		tiny_sort(&a);
	// 	else
	// 		push_swap(&a, &b);
	// }
	// free_stack(&a);
    else
    {
        re = parsing(argc,argv);
        if (re == NULL)
            return (1);
        for (int j = 0; j < re->size; j++)
            printf("%d\n", re->array[j]);
        init(&a, re);
        size = re->size;
        if(!stack_sorted(a) || !isEmpty(a))
        {
            if (size == 2)
            {
                print_stack(a);
                swap(&a, "sa");
                print_stack(a);
            }
            else if (size == 3)
            {
                print_stack(a);
                sort_3(&a);
                print_stack(a);
            }
            else if (size > 3 && size <= 5)
                sort_5(&a, &b, size);
            else
                printf("Array too large for this implementation.\n");
        }
        else
            ft_printf("stack already sorted or empty\n");
    }
    
    //free_stack(&a);
}