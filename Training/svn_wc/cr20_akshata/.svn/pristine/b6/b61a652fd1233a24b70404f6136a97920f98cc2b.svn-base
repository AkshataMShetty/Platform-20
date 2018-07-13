#include "header.h"

int delete_at_mid (node **front, node **rear)
{
	int num;
	int count;

	node *temp = NULL;

	if (*front == *rear) {
		num = (*front) -> info;
		*rear = NULL;
		free (*front);
		return num;
	}
	
	temp = *front;
	count = 0;
	while (temp) {
		count++;
		temp = temp -> next;
	}

	return (delete_at_pos (front, rear, (count / 2) + 1));
/*
	count /= 2;
	//count++;

	temp = *front;
	for (i = 1; i < count; i++) {
		mid = temp;
		temp = temp -> next;
	}

	mid -> next = temp -> next;
	temp -> next = NULL;

	num = temp -> info;
	free (temp);
	
	return num;*/
}
