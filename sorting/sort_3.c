#include "../push_swap.h"

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
        swap(a, "sa\n");
    else if(maxNode->data == (*a)->data)
    {
        rotate(a, "ra\n");
        if(!stack_sorted(*a))
            swap(a, "sa\n");
    }
    else
    {
        reverseRotate(a, "rra\n");
        if(!stack_sorted(*a))
            swap(a, "sa\n");
    }
}
