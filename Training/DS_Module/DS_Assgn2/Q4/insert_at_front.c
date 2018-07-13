#include "header.h"

void insert_at_front (node **front, node **rear, node *temp)
{
	if (*front) {
		temp -> next = *front;
		*front = temp;
	} else {
		*front = temp;
	}

	if (NULL == (*rear)) {
		*rear = *front;
	}
}
