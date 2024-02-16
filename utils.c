#include "push_swap.h"

struct stack_node* createStack() 
{
    struct stack_node* stack = (struct stack_node*)malloc(sizeof(struct stack_node));
    if (!stack) 
        return(NULL);
    stack->top = NULL;
    return (stack);
}

int isEmpty(struct stack_node* stack) 
{
    return((stack -> top) == NULL); 
}

void push(struct stack_node* stack, int data) 
{
    struct stack_node* newNode;
    
    newNode = (struct stack_node*)malloc(sizeof(struct stack_node));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = stack->top;
    newNode->prev = NULL;
    if (stack->top != NULL) 
        stack->top->prev = newNode;
    stack->top = newNode;
}

int pop(struct stack_node* stack) 
{
    if (isEmpty(stack)) 
        return(1);
    struct stack_node* temp;
    int data;

    temp = stack->top;
    data = temp->data;
    stack->top = temp->next;
    if (stack->top != NULL) 
        stack->top->prev = NULL;
    free(temp);
    return data;
}


int main(int argc, char **argv)
{
    int i; 
    stack_i *stack;


    if (argc < 2) {
        printf("dumb ass bitch");
        return 1;
    }
    if(argc == 2)
    {
        
    }

    i = 1;
    stack = createStack();
    while(argv[i])
    {
        push(stack, atoi(argv[i]));
        i++;
    }
    printf("Elements of the stack after pushing:\n");
    struct stack_node* current = stack->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    return 0;
}