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
StackNode *stack_pop(Stack *stack);
int stack_length(Stack *stack);


#endif