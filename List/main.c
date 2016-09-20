#include <stdio.h>
#include "list.h"

struct Value
{
	ListNode header;
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
	
	List *list = list_create();
	
	list_insert(list, (ListNode *)&v1, 0);
	list_insert(list, (ListNode *)&v2, 2);
	list_insert(list, (ListNode *)&v3, 3);
	list_insert(list, (ListNode *)&v4, 1);
	
	list_insert(list, (ListNode *)&v5, 6);
	
	printf("list length = %d\n", list_length(list));
	
	
	struct Value *ptr = (struct Value *)list_get(list, 7);
	printf("value = %d\n", ptr->v);
	
	printf("=======================================\n");
	
	list_destroy(&list);
	
	int i;
	for (i=0; (i<list_length(list)) && (list_length(list) > 0); i++) {
		struct Value *pv = (struct Value *)list_get(list, i);
		printf("list value[%d] = %d\n", i, pv->v);
	}
	
	return 0;
}