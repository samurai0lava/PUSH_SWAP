#include "push_swap.h"
int main(int argc, char **argv)
{

stack_i *a = NULL; // Initialize pointers
stack_i *b = NULL;
array_s re;
re.array = NULL;
re.size = 0;

if (argc == 1 || (argc == 2 && argv[1][0] == '\0')) {
    ft_putendl_fd("Error: Invalid set of arguments", 2);
    return 1;
} 
else 
{
    // Call parsing function once and store the result
    re = parsing(argc, argv);
    if (re.array == NULL) {
        ft_putendl_fd("Error: Parsing failed", 2);
        return 1;
    }
    init(&a, re); // Assuming init function initializes 'a' properly
}

printf("Elements of the stack after pushing:\n");
if (!isEmpty(a)) 
{ // Check if stack 'a' is initialized and not empty
    struct stack_node* current = a->top;
    while (current != NULL) 
    {
        printf("%d\n", current->data);
        current = current->next;
    }
} 
else
    printf("Stack is empty or not initialized properly\n");

return 0;
}