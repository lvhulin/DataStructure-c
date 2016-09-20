#include <stdio.h>
#include <malloc.h>
#include "stack.h"

typedef struct _tag_stack
{
	StackNode *top;
	int length;
	
} TStack;


Stack *stack_create()
{
	TStack *ret = (TStack *)malloc(sizeof(TStack));
	
	if (ret != NULL) {
		ret->top = NULL;
		ret->length = 0;
	}
	
	return ret;
}


int stack_push(Stack *stack, StackNode *node)
{
	TStack *s = (TStack *)stack;
	int ret = (s != NULL) && (node != NULL);
	
	if (ret) {
		StackNode *newNode = (StackNode *)node;
		if (s->top == NULL) {
			newNode->next = NULL;
		} else {
			newNode->next = s->top;
		}
		s->top = newNode;
		++s->length;
	}
	
	return ret;
}

StackNode *stack_pop(Stack *stack)
{
	TStack *s = (TStack *)stack;
	StackNode *ret = NULL;
	
	if ((s != NULL) && (s->top != NULL)) {
		StackNode *current = s->top;
		ret = current;
		free(current);
		s->top = s->top->next;
		--s->length;
	}	
	return ret;	
}


int stack_length(Stack *stack)
{
	TStack *s = (TStack *)stack;
	int ret = -1;
	
	if (s != NULL) {
		ret = s->length;
	}
	
	return ret;	
}