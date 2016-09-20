#include <stdio.h>
#include "stack.h"

struct Value
{
	StackNode *top;
	int v;
};


int main(void)
{
	struct Value v1,v2,v3,v4,v5;
	
	v1.v = 11;
	v2.v = 22;
	v3.v = 33;
	v4.v = 44;
	v5.v = 55;
	
	Stack *stack = stack_create();
	
	stack_push(stack, (StackNode *)&v1);
	stack_push(stack, (StackNode *)&v2);
	stack_push(stack, (StackNode *)&v3);
	stack_push(stack, (StackNode *)&v4);
	stack_push(stack, (StackNode *)&v5);
	
	stack_pop(stack);
	
	
	struct Value *ptr = (struct Value *)stack_top(stack);
	printf("stack top = %d\n", ptr->v);
	
	stack_length(stack);


	printf("====================================\n");
		
	
	printf("stack length = %d\n", stack_length(stack));
	
	
	stack_destroy(&stack);

	while (stack_length(stack) > 0) {
		
		struct Value *pv = (struct Value *)stack_pop(stack);
		
		printf("value = %d\n", pv->v);
	}

	
	return 0;
} 