#include "push_swap.h"

int main(int argc, char **argv)
{
    //if argc is empty than return error(!)
    //if argc equal 2 and the string is null u should end my life (return 1)
    //wn need to split that shit in argument "13 -9 -7 189" like this and splited with " "
    //WHAT ABOUT DUPLICATED
    //and what if i did not put the argument as as a string ./push_swap 13 12 0 98 1
    //                                                       argv[0]    argv[1]...argv[n]
    //                                                                  ft_atoi
	//how to handle that shit db 
	//if the the stack was a form of one string (if the argc == 2)
    //if the stack was of form of multiple strings ./push_swap 13 12 0 98 1 (if the argc > 2)
    //hmmmmm
    //
    //wait where is my stack
    //
	stack_i *a;
    array_s *re;
    stack_i *b;
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

        if(!isEmpty(a))
        {
            push_swap(&a, &b);
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