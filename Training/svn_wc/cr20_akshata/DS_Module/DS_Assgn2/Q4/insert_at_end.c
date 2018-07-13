#include "header.h"

void insert_at_end (node **front, node **rear, node *temp)
{
	if (*rear) {
		(*rear) -> next = temp;
		*rear = (*rear) -> next;
	} else {
		*rear = temp;
	}

	if (NULL == (*front)) {
		*front = *rear;
	}
}
