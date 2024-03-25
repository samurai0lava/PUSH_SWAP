#include "../push_swap.h"

static stack_i* find_max(stack_i* a)
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
    stack_i *maxNode;
    stack_i *lastNode;
    
    lastNode = find_last_node(*a);
    maxNode = find_max(*a);

    if(maxNode->data == (*a)->data)
    {
        rotate(a, 'a');
        if(!stack_sorted(*a))
            swap(a, 'a');
    }
    else if (maxNode->data == lastNode->data)                
        swap(a, 'a');
    else
    {
        reverseRotate(a, 'a');
        if(!stack_sorted(*a))
            swap(a, 'a');
    }
}
