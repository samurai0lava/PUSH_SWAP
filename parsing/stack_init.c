/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:52:47 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/04 16:53:43 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void init(stack_i **a, array_s *re) 
// {
//     int i;

// 	*a = createStack();
// 	if (a == NULL)
// 	{
// 		ft_putendl_fd("Error: Failed to initialize stack\n", 2);
// 		return;
// 	}
// 	i = 0;
// 	while (i < re->size) 
// 	{
// 		push(*a, re->array[i]);
// 		i++;
// 	}
// }

// void init(stack_i **a, array_s *re) 
// {
//     int i;

//     *a = createStack();
//     if (*a == NULL)
//     {
//         ft_putendl_fd("Error: Failed to initialize stack\n", 2);
//         return;
//     }

//     i = 0;
//     while (i < re->size) 
//     {
//         push(a, re->array[i]);  // Pass the address of the stack pointer 'a'
//         i++;
//     }
// }


static stack_i	*find_last_node(stack_i *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

// static void	append_node(stack_i **stack, int nbr)
// {
// 	stack_i	*node;
// 	stack_i	*last_node;

// 	if (stack == NULL)
// 		return ;
// 	node = malloc(sizeof(stack_i));
// 	if (node == NULL)
// 		return ;
// 	node->next = NULL;
// 	node->data = nbr;
// 	if (*stack == NULL)
// 	{
// 		*stack = node;
// 		node->prev = NULL;
// 	}
// 	else
// 	{
// 		last_node = find_last_node(*stack);
// 		last_node->next = node;
// 		node->prev = last_node;
// 	}
// }
static void append_node(stack_i **stack, int nbr)
{
    stack_i *node;
    stack_i *last_node;

    if (stack == NULL)
        return;

    node = malloc(sizeof(stack_i));
    if (node == NULL)
        return;

    node->next = NULL;
    node->data = nbr;

    if (*stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        node->prev = last_node;
        last_node->next = node;
    }
}
// void init(stack_i **a, array_s *re) 
// {
//     int i;

//     *a = createStack();
//     if (*a == NULL)
//     {
//         ft_putendl_fd("Error: Failed to initialize stack\n", 2);
//         return;
//     }

//     i = 0;
//     while (i < re->size) 
//     {
//         append_node(a, re->array[i]);
//         i++;
//     }
// }
void init(stack_i **a, array_s *re) 
{
    int i;

    *a = createStack(re->array[0]);


    if (*a == NULL)
    {
        ft_putendl_fd("Error: Failed to initialize stack\n", 2);
        return;
    }

    printf("Before initialization:\n");
    print_stack(*a);

    i = 1;
    while (i < re->size) 
    {
        append_node(a, re->array[i]);
        i++;
    }

    printf("After initialization:\n");
    print_stack(*a);
}
