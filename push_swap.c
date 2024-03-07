//algo that will do it all
//MNIN ANBDAHAA

#include "push_swap.h"

void push_swap(stack_i **a, stack_i **b, int size)
{

    while(is_it_sorted(*a) == 1)
    {
        if (size == 2)
            swap(a, "sa");
        else if (size == 3)
            sort_3(a);
        else if(size > 3 && size <= 5)
            sort_5(a ,b, size);
        else
            ft_printf("mzl massybna dakshi lakher shtt");
    }
}

int is_it_sorted(stack_i *a) 
{
    stack_i *tmp 
    
    tmp = a;
    while (tmp->next) 
    {
        if (tmp->data > tmp->next->data)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}
void print_stack(stack_i *stack) 
{
    stack_i *current 
    
    current = stack;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

