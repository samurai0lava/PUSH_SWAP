#include "push_swap.h"

// void sort_3(stack_i **a)
// {
//     int first;
//     int second;
//     int third;

//     first = (*a)->data;
//     second = (*a)->next->data;
//     third = (*a)->next->next->data;
//     if (first > second && second < third && first < third)
//         swap(a, "sa");
//     else if (first > second && second > third && first > third)
//     {
//         swap(a, "sa");
//         reverseRotate(a, "rra");
//     }
//     else if (first > second && second < third && first > third)
//         rotate(a, "ra");
//     else if (first < second && second > third && first < third)
//     {
//         swap(a, "sa");
//         rotate(a, "ra");
//     }
//     else if (first < second && second > third && first > third)
//         reverseRotate(a, "rra");
//     else
//         return;
// }

void sort_3(stack_i **a) {
    if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return; // No need to sort if there are less than 3 elements
    
    int first = (*a)->data;
    int second = (*a)->next->data;
    int third = (*a)->next->next->data;

    if (first > second && second < third && first < third)
        swap(a, "sa");
    else if (first > second && second > third && first > third) {
        swap(a, "sa");
        reverseRotate(a, "rra");
    } else if (first > second && second < third && first > third)
        rotate(a, "ra");
    else if (first < second && second > third && first < third) {
        swap(a, "sa");
        rotate(a, "ra");
    } else if (first < second && second > third && first > third)
        reverseRotate(a, "rra");
    // No need for else, as the stack is already sorted in this case
}

