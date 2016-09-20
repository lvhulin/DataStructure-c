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
	
	while (stack_length(stack)) {
		
		struct Value *pv = (struct Value *)stack_pop(stack);
		
		printf("value = %d\n", pv->v);
	}
	
	
	return 0;
} 