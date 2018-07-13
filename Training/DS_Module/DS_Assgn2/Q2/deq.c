#include "header.h"

int deq (node **front, node **rear)
{
	node *new = NULL;
	int num;
	
	new = *front;
	*front = (*front) -> next;

	if (*front == NULL){
		*rear = NULL;
	}
	
	num = new -> info;
	
	return num;
}
