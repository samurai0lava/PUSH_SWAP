#include "push_swap.h"

// int main(int argc, char **argv)
// {
//     //if argc is empty than return error(!)
//     //if argc equal 2 and the string is null u should end my life (return 1)
//     //wn need to split that shit in argument "13 -9 -7 189" like this and splited with " "
//     //WHAT ABOUT DUPLICATED
//     //and what if i did not put the argument as as a string ./push_swap 13 12 0 98 1
//     //                                                       argv[0]    argv[1]...argv[n]
//     //                                                                  ft_atoi
// 	//how to handle that shit db 
// 	//if the the stack was a form of one string (if the argc == 2)
//     //if the stack was of form of multiple strings ./push_swap 13 12 0 98 1 (if the argc > 2)
//     //hmmmmm
//     //
//     //wait where is my stack
//     //
// 	stack_i *a;
// 	stack_i *b;
//     array_s *re;

//     a = NULL;
//     b = NULL;
//     re = NULL;
//     if (argc <= 1 || (argc == 2 && argv[1][0] == '\0'))
//     {
//         ft_putendl_fd("Error: Invalid set of arguments", 2);
//         return (1);
//     }
//     else
//     {
//         re = parsing(argc,argv);
//         init(a, re);
//         if(!isEmpty(a))
//         {
//             printf("Elements of the stack after pushing:\n");
//             struct stack_node *current = a->top;
//             while (current != NULL) 
//             {
//                 ft_printf("%d\n", current->data);
//                 current = current->next;
//             }
//         }
//         else
//             printf("Stack is empty or not initialized properly\n");
//     }
//     return(0);
//     //./push_swap "13 89 89"
// }

int main(int argc, char *argv[]) 
{
    stack_i *a = malloc(sizeof(stack_i));
    if (a == NULL) {
        // Error handling for failed memory allocation
        ft_printf("Error: Memory allocation failed\n");
        return 1;
    }
    a->top = NULL;

    stack_i *b = malloc(sizeof(stack_i));
    if (b == NULL) {
        // Error handling for failed memory allocation
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(a); // Free previously allocated memory
        return 1;
    }
    b->top = NULL;

    array_s *re = NULL;

    if (argc <= 1 || (argc == 2 && argv[1][0] == '\0')) {
        ft_putendl_fd("Error: Invalid set of arguments", 2);
        free(a); // Free allocated memory before returning
        free(b);
        return 1;
    }
    else 
    {
        re = parsing(argc, argv);
        if (re == NULL) 
        {
            // Error handling for parsing failure
            ft_putendl_fd("Error: Parsing failed", 2);
            free(a); // Free allocated memory before returning
            free(b);
            return 1;
        }
        init(a, re);
        if (!isEmpty(a)) {
            printf("Elements of the stack after pushing:\n");
            struct stack_node *current = a->top;
            while (current != NULL) 
            {
                ft_printf("%d\n", current->data);
                current = current->next;
            }
        }
        else 
            printf("Stack is empty or not initialized properly\n");
        // Free allocated memory before returning
        free(re);
        free(a);
        free(b);
    }
    return 0;
}