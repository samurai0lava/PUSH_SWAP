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
        swap(a);
    else if (first > second && second > third && first > third)
    {
        swap(a);
        reverse_rotate(a);
    }
    else if (first > second && second < third && first > third)
        rotate(a);
    else if (first < second && second > third && first < third)
    {
        swap(a);
        rotate(a);
    }
    else if (first < second && second > third && first > third)
        reverse_rotate(a);
    else
        return;
}