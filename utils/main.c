#include "../push_swap.h"

int main(int argc, char **argv)
{
	stack_i *a;
    array_s *re;
    stack_i *b;
    int size;

    a = NULL;
    re = NULL;
    if (argc <= 1 || (argc == 2 && argv[1][0] == '\0'))
    {
        ft_putendl_fd("Error: Invalid set of arguments", 2);
        return (1);
    }
    else
    {
        re = parsing(argc,argv);
        init(&a, re);
        size = re->size;
        
        
        if(!isEmpty(a))
        {
            push_swap(&a, &b, size);
            // printf("%d\n", size);
            ft_printf("Elements of the stack after pushing: (sorted)\n");
            struct stack_node* current = a->top;
            while (current != NULL) 
            {
                printf("%d\n", current->data);
                current = current->next;
            }       
        }
        else
            ft_putendl_fd("Stack is empty or not initialized properly", 2);
    }
    return(0);
    //./push_swap "13 89 89"
}