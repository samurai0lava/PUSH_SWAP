#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <string.h>

typedef struct array_size
{
    int *array;
    int size;
} array_s;

typedef struct stack_node
{
    int     current_position;
    int     data;
    int     cost;
    int     median_top;
    int     cheapest;
    struct  stack_node *target;
    struct  stack_node *top;
    struct  stack_node *next;
    struct  stack_node *prev;
} stack_i;

int		check_duplicate(int *array, size_t size);
array_s *parsing(int argc, char **argv);
void	error_quit(char *str);
int		check_inputs(int argc, char **argv);
char	**split_args(int argc, char **argv);
int		*atoi_ad(char **splitted);
void    init(stack_i **stack, array_s *re);
stack_i	*find_last_node(stack_i *head);
stack_i *createStack(int content);
int     isEmpty(stack_i* stack);
void    push(stack_i **a, stack_i **b, char *str);
int     size_sp(char **splited);
int     stack_len(stack_i *stack);
void    sort_3(stack_i **a);
void    reverseRotate(stack_i **head, char *str); 
void    rotate(stack_i **head, char *str);
void    swap(stack_i **head, char *str);
void    print_stack(stack_i *stack);
void    push_swap(stack_i **a, stack_i **b);
int	    stack_sorted(stack_i *stack);
void    sort_5(stack_i **a, stack_i **b, int size);
int     empty(char *str);
int     find_min(stack_i *a);
int     get_index(stack_i *stack, int nbr);
void    init_param(stack_i *a, stack_i *b);
void    set_target(stack_i *a, stack_i *b);
void    set_cheapest(stack_i *b);
void    set_index(stack_i *a);
void    set_price(stack_i *a, stack_i *b);


#endif