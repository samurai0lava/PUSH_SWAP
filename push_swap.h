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

#endif