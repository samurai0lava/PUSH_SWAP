
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
    else
    {
        re = parsing(argc,argv);
        if (re == NULL)
            return (1);
        init(&a, re);
        size = re->size;
        if(!stack_sorted(a) || !isEmpty(a))
        {
            if (size == 2)
                swap(&a, "sa\n");
            else if (size == 3)
                sort_3(&a);
            else if (size > 3 && size <= 5)
                sort_5(&a, &b, size);
            else
                printf("Array too large for this implementation.\n");
        }
        else
            return (0);
    }
}