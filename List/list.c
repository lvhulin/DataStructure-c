#include <stdio.h>
#include <malloc.h>
#include "list.h"

typedef struct _tag_list
{
	ListNode header;
	int length;
	
} TList;


List *list_create()
{
	TList *ret = (TList *)malloc(sizeof(TList));
	
	if (ret != NULL) {
		ret->header.next = NULL;
		ret->length = 0;
	}
	
	return ret;
}


void list_destroy(List **list)
{
	free(*list);
	*list = NULL;
}


int list_insert(List *list, ListNode *node, int pos)
{
	TList *sList = (TList *)list;
	int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
	
	if (ret) {
		ListNode *current = (ListNode *)sList;
		while ((current->next != NULL) && (pos--)) {
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
		/* 循环链表 */
		if (sList->length == 0) {
			node->next = node;
		}
		++sList->length;
	}
	
	return ret;
}


ListNode *list_get(List *list, int pos)
{
	TList *sList = (TList *)list;
	ListNode *ret = NULL;
	
	if ((sList != NULL) && (pos >= 0)) {
		ListNode *current = (ListNode *)sList;
		while (pos--) {
			current = current->next;
		}
		ret = current->next;
	}
	
	return ret;
}

ListNode *list_delete(List *list, int pos)
{
	TList *sList = (TList *)list;
	ListNode *ret = NULL;
	ListNode *first = sList->header.next;
	ListNode *last = (ListNode *)list_get(list, sList->length-1);
	
	if ((sList != NULL) && (pos >= 0)) {
		ListNode *current = (ListNode *)sList;
		while (pos--) {
			current = current->next;	
		}
		ret = current->next;
		current->next = ret->next;
		--sList->length;
		
		/* 循环链表删除头尾相连 */
		if (ret == first) {
			sList->header.next = ret->next;
			last->next = ret->next;
		}
		
	}
	
	return ret;	
}

int list_length(List *list)
{
	TList *sList = (TList *)list;
	int ret = -1;
	
	if (sList != NULL) {
		ret = sList->length;
	}
	
	return ret;
} 