#include "header.h"

int delete_at_end (node **front, node **rear)
{
	int num;

	node *temp = *front;

	if (*front == *rear) {
		num = (*front) -> info;
		*rear = NULL;
		free (*front);
		return num;
	}
	
	while (temp -> next != (*rear)) {
		temp = temp -> next;
	}
	
	*rear = temp;
	temp = temp -> next;
	(*rear) -> next = NULL;

	num = temp -> info;

	free (temp);

	return num;
}
