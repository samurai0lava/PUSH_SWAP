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
// static stack_i* first_node(stack_i* a, stack_i* last_node)
// {
//     if(a->next->next == last_node)
//         return(a);
//     return (NULL);
    
// }
void sort_3(stack_i **a)
{
    if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return;
    stack_i *maxNode;
    stack_i *lastNode;
    // stack_i *first_node1;
    
    lastNode = find_last_node(*a);
    // first_node1 = first_node(*a, lastNode);
    maxNode = find_max(*a);
    
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
