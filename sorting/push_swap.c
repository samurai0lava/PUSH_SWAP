
#include "../push_swap.h"

void	push_swap(stack_i **a, stack_i **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		push(a, b, "pb\n");
	if (len_a-- > 3 && !stack_sorted(*a))
		push(a, b, "pb\n");
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_param_a(*a, *b);
		moves_a(a, b);
	}
	sort_3(a);
	while (*b)
	{
		printf("allo111\n");
		init_param_b(*a, *b);
		moves_b(a, b);
	}
	set_index(*a);
	final_move(a);
}