#include "header.h"

int delete_at_front (node **front, node **rear)
{
	int num;

	node *temp;

	if (*front == *rear) {
		num = (*front) -> info;
		*rear = NULL;
		free (*front);
		*front = NULL;
		return num;
	}

	temp = (*front) -> next;
	(*front) -> next = NULL;

	num = (*front) -> info;

	free (*front);

	*front = temp;

	return num;
}
