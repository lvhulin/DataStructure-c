#include <stdio.h>
#include "queue.h"

struct Value
{
	QueueNode *next;
	int v;
};


int main(void)
{
	Queue *queue = queue_create();
	
	struct Value v1,v2,v3,v4,v5;
	
	v1.v = 11;
	v2.v = 22;
	v3.v = 33;
	v4.v = 44;
	v5.v = 3433;
	
	queue_push(queue, (QueueNode *)&v5);
	queue_push(queue, (QueueNode *)&v1);
	queue_push(queue, (QueueNode *)&v2);
	queue_push(queue, (QueueNode *)&v3);
	queue_push(queue, (QueueNode *)&v4);
	
	printf("length = %d\n", queue_length(queue));
	
	

	struct Value *ptr;
	ptr = (struct Value *)queue_pop(queue);
	printf("pop vlaue = %d\n", ptr->v);

	printf("pop length = %d\n", queue_length(queue));
	
	
	queue_destroy(&queue);
	
	printf("pop length = %d\n", queue_length(queue));
	

	while (queue_length(queue) > 0) {
		struct Value *pv = (struct Value *)queue_pop(queue);
		printf("vlaue = %d\n", pv->v);
	}

	return 0;
}