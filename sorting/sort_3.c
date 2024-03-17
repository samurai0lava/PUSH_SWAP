#include "../push_swap.h"

void sort_3(stack_i **a) 
{
    if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return;
    int first = (*a)->data;
    int second = (*a)->next->data;
    int third = (*a)->next->next->data;
    
    if (first > second && second < third && first < third)
        swap(a, "sa");
    else if (first > second && second > third && first > third)
    {
        swap(a, "sa");
        reverseRotate(a, "rra");
    } 
    else if (first > second && second < third && first > third)
        rotate(a, "ra");
    else if (first < second && second > third && first < third)
    {
        swap(a, "sa");
        rotate(a, "ra");
    } 
    else if (first < second && second > third && first > third)
        reverseRotate(a, "rra");
    print_stack(*a);
}

void sort_3(stack_i **a)
{
    if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return; 
    
}