#ifndef _LIST_H
#define _LIST_H

typedef void List;
typedef struct _tag_list_node ListNode;

struct _tag_list_node
{
	ListNode *next;
}; 


List *list_create();
void list_destroy(List **list);
int list_insert(List *list, ListNode *node, int pos);
ListNode *list_get(List *list, int pos);
ListNode *list_delete(List *list, int pos);
int list_length(List *list);

#endif