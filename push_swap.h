#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <string.h>
# include <limits.h>
# include <stdbool.h>

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
    bool		median_top;
    bool     cheapest;
    struct  stack_node *target;
    struct  stack_node *top;
    struct  stack_node *next;
    struct  stack_node *prev;
} stack_i;

void        free_array(char **str);
void        freestack(stack_i *stack); 
int		    check_duplicate(int *array, size_t size);
array_s     *parsing(int argc, char **argv);
void	    error_quit(char *str);
int		    check_inputs(int argc, char **argv);
char	    **split_args(int argc, char **argv);
int		    *atoi_ad(char **splitted);
void        init(stack_i **stack, array_s *re);
stack_i	    *find_last_node(stack_i *head);
stack_i     *createStack(int content);
int         isEmpty(stack_i* stack);
void        push(stack_i **a, stack_i **b, char type);
int         size_sp(char **splited);
int         stack_len(stack_i *stack);
void        sort_3(stack_i **a);
void		reverseRotate(stack_i **head, char type);
void		rotate(stack_i **stack, char type);
void        swap(stack_i **head, char type);
void        print_stack(stack_i *stack);
void        push_swap(stack_i **a, stack_i **b);
int	        stack_sorted(stack_i *stack);
void        sort_5(stack_i **a, stack_i **b, int size);
int         empty(char *str);
stack_i     *find_min_node(stack_i *a);
int         get_index(stack_i *stack, int nbr);
void        init_param_a(stack_i *a, stack_i *b);
void        init_param_b(stack_i *a, stack_i *b);
void		set_cheapest(stack_i *stack);
void        set_index(stack_i *a);
void        set_price_a(stack_i *a, stack_i *b);
long double	ft_atoiv2(char *str, char **array, int *arr);
void    	moves_a(stack_i **a, stack_i **b);
stack_i		*get_cheapest(stack_i *stack); 
void    	moves_b(stack_i **a, stack_i **b);
int     	find_min(stack_i *a);
void		final_move(stack_i **a);
stack_i*    find_max(stack_i* a);
#endif
