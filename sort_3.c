#include "push_swap.h"

void sort_3(stack_i **a)
{
    int first;
    int second;
    int third;

    first = (*a)->data;
    second = (*a)->next->data;
    third = (*a)->next->next->data;
    if (first > second && second < third && first < third)
        swap(a, "sa");
    else if (first > second && second > third && first > third)
    {
        swap(a, "sa");
        reverse_rotate(a), "rra";
    }
    else if (first > second && second < third && first > third)
        rotate(a, "ra");
    else if (first < second && second > third && first < third)
    {
        swap(a, "sa");
        rotate(a, "ra");
    }
    else if (first < second && second > third && first > third)
        reverse_rotate(a, "rra");
    else
        return;
}
