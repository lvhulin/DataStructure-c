#ifndef _STACK_H
#define _STACK_H

typedef void Stack;
typedef struct _tag_stack_node StackNode;

struct _tag_stack_node
{
	StackNode *next;
};

Stack *stack_create();
int stack_push(Stack *stack, StackNode *node);
int stack_length(Stack *stack);
StackNode *stack_pop(Stack *stack);
StackNode *stack_top(Stack *stack);
void stack_destroy(Stack **stack);

#endif