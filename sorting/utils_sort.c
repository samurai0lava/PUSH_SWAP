#include "../push_swap.h"

static void set_target(stack_i *a, stack_i *b)
{
    stack_i *current;
    stack_i *target;
    long    best_match;

    while (b)
    {
        current = a;
        best_match = LONG_MAX;
        while(current)
        {
            if(current->data < best_match && current->data > b->data)
            {
                best_match = current->data;
                target = current;
            }
            current = current->next;
        }
        if(best_match == LONG_MAX)
            b->target = find_min(a);
        else
            b->target = target;
        b = b->next;
    }
}
static void set_cheapest(stack_i *b)
{

}

static void set_index(stack_i *a)
{

}
static void set_price(stack_i *a, stack_i *b)
{

}
void init_param(stack_i *a, stack_i *b)
{
	set_index(a);
	set_index(b);
	set_target(a ,b);
	set_price(a,b);
	set_cheapest(b);
}