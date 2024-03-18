#include "../push_swap.h"

// void sort_3(stack_i **a) 
// {
//     if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
//         return;
//     int first = (*a)->data;
//     int second = (*a)->next->data;
//     int third = (*a)->next->next->data;
    
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
// }
stack_i* find_max(stack_i* a)
{
    if (a == NULL)
        return NULL;
    int max = a->data;
    stack_i* maxNode; 
    
    maxNode = a;
    while (a != NULL)
    {
        if (a->data > max)
        {
            max = a->data;
            maxNode = a;
        }
        a = a->next;
    }

    return (maxNode);
}

void sort_3(stack_i **a)
{
    if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return;
    stack_i *maxNode;
    stack_i *lastNode;

    maxNode = find_max(*a);
    lastNode = find_last_node(*a);
    if (maxNode->data == lastNode->data)                
        swap(a, "sa");
    else if(maxNode->data == (*a)->data)
    {
        rotate(a, "ra");
        if(!stack_sorted(*a))
            swap(a, "sa");
    }
    else
    {
        reverseRotate(a, "rra");
        if(!stack_sorted(*a))
            swap(a, "sa");
    }
}
