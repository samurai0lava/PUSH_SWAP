#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <string.h>

typedef struct stack_node
{
    int current_position;
    int data;

    struct stack_node *top;
    struct stack_node *next;
    struct stack_node *prev;
} stack_i;

int		check_duplicate(int *array, size_t size);
int		*parsing(int argc, char **argv);
void	error_quit(char *str);
int		check_inputs(int argc, char **argv);
char	**split_args(int argc, char **argv);
int		*atoi_ad(int argc, char **splitted);
void    init(stack_i a, int *array);
stack_i *createStack();
int     isEmpty(struct stack_node* stack);
void    push(struct stack_node* stack, int data);
int     size_sp(char **splited);

#endif