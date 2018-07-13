#include "header.h"

void left_rotate (node **front, node **rear)
{
	node *new_front = NULL;

	new_front = (*front) -> next;
	(*rear) -> next = *front;
	*rear = (*rear) -> next;
	(*rear) -> next = NULL;

	*front = new_front;
}
