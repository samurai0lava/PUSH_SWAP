/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:16:58 by iouhssei          #+#    #+#             */
/*   Updated: 2024/03/28 17:17:00 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <string.h>
# include <limits.h>
# include <stdbool.h>

typedef struct t_arrayize
{
	int	*array;
	int	size;
}	t_array;

typedef struct stack_node
{
	int					current_position;
	int					data;
	int					cost;
	bool				median_top;
	bool				cheapest;
	struct stack_node	*target;
	struct stack_node	*top;
	struct stack_node	*next;
	struct stack_node	*prev;
}	t_stack;

void		free_array(char **str);
void		freestack(t_stack *stack);
int			check_duplicate(int *array, size_t size);
t_array		*parsing(int argc, char **argv);
void		error_quit(char *str);
int			check_inputs(int argc, char **argv);
int			check_inputs2(int argc, char **argv);
char		**split_args(int argc, char **argv);
int			*atoi_ad(char **splitted);
void		init(t_stack **stack, t_array *re);
t_stack		*find_last_node(t_stack *head);
t_stack		*createstack(int content);
int			isempty(t_stack	*stack);
void		push(t_stack **a, t_stack **b, char type);
int			size_sp(char **splited);
int			stack_len(t_stack *stack);
void		sort_3(t_stack **a);
void		reverserotate(t_stack **head, char type);
void		rotate(t_stack **stack, char type);
void		swap(t_stack **head, char type);
void		print_stack(t_stack *stack);
void		push_swap(t_stack **a, t_stack **b);
int			stack_sorted(t_stack *stack);
void		sort_5(t_stack **a, t_stack **b, int size);
int			empty(char *str);
t_stack		*find_min_node(t_stack *a);
int			get_index(t_stack *stack, int nbr);
void		init_param_a(t_stack *a, t_stack *b);
void		init_param_b(t_stack *a, t_stack *b);
void		set_cheapest(t_stack *stack);
void		set_index(t_stack *a);
void		set_price_a(t_stack *a, t_stack *b);
long double	ft_atoiv2(char *str, char **array, int *arr);
void		moves_a(t_stack **a, t_stack **b);
t_stack		*get_cheapest(t_stack *stack);
void		moves_b(t_stack **a, t_stack **b);
int			find_min(t_stack *a);
void		final_move(t_stack **a);
t_stack		*find_max(t_stack *a);
#endif
