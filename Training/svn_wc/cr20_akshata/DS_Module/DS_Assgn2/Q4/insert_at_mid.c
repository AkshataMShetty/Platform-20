#include "header.h"

int insert_at_mid (node **front, node **rear, node *new)
{
	int count = 0;
	node *temp = NULL;
	int i;

	if (NULL == *front) {
		insert_at_front (front, rear, new);
		return 1;
	}

	//count nodes
	temp = *front;
	while (temp) {
		count++;
		temp = temp -> next;
	}

	//get position of middle node
	count /= 2;
	
	//place a pointer before the middle node
	temp = *front;
	for (i = 1; i < count; i++) {
		temp = temp -> next;
	}

	//insert new node at middle position
	new -> next = temp -> next;
	temp -> next = new;

	return count + 1;


}
