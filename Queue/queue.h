#ifndef _QUEUE_H
#define _QUEUE_H

typedef void Queue;

typedef struct _tag_queue_node QueueNode;

struct _tag_queue_node
{
	QueueNode *next;
};


Queue *queue_create();
void queue_destroy(Queue **queue);
int queue_push(Queue *queue, QueueNode *node);
int queue_length(Queue *queue);
QueueNode *queue_pop(Queue *queue);


#endif 