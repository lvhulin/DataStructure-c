#include <stdio.h>
#include <malloc.h>
#include "queue.h"

typedef struct _tag_queue
{
	QueueNode *head;
	QueueNode *tail;
	int length;	
} TQueue;


Queue *queue_create()
{
	TQueue *ret = (QueueNode *)malloc(sizeof(QueueNode));
	
	if (ret != NULL) {
		ret->head = NULL;
		ret->tail = NULL;
		ret->length = 0;
	}
	return ret;
}

int queue_push(Queue *queue, QueueNode *node)
{
	TQueue *q = (Queue *)queue;
	int ret = (q != NULL);
	
	if (ret) {
		if (q->head == NULL) {
			q->head = node;
			q->tail = node;
		} else {
			q->tail->next = node;
			q->tail = node;
		}
		q->tail->next = NULL;
		++q->length;		
	}

	return ret;
}

QueueNode *queue_pop(Queue *queue)
{
	TQueue *q = (TQueue *)queue;
	QueueNode *ret = NULL;
	
	if ((q != NULL) && (q->head	!= NULL)) {
		ret = q->head;
		q->head = ret->next;
		--q->length;
	}
	return ret;
}

int queue_length(Queue *queue)
{
	TQueue *q = (Queue *)queue;
	int ret = -1;
	
	if (q != NULL) {
		ret = q->length;	
	}
	
	return ret;
}

void queue_destroy(Queue **queue)
{
	free(*queue);
	*queue = NULL;
}