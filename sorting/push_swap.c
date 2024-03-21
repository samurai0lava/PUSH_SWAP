#include "../push_swap.h"

static void set_target(stack_i *a, stack_i *b)
{
    stack_i *current;
    stack_i *target;

    long best_match;

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
        
    }
}
void push_swap(stack_i **a, stack_i **b, array_s *re)
{
    int size;
    int *array;

    size = re->size;
    array = re->array;

    //quick_sort this array
    
}



