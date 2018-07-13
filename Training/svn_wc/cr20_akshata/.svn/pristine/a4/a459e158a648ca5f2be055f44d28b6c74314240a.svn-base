#include "header.h"

int delete_at_pos (node **front, node **rear, int pos)
{
	int num;
	int count;

	node *temp = NULL;
	node *prev = NULL;

	if (*front == *rear) {
		num = (*front) -> info;
		*rear = NULL;
		free (*front);
		return num;
	}
	
	temp = *front;
	count = 1;
	while (temp) {
		if (count == pos) {
			if (temp == *front) {
				return (delete_at_front (front, rear));
			}
			prev -> next = temp -> next;
			temp -> next = NULL;
			num = temp -> info;
			free (temp);
			return num;
		} else if (count > pos) {
			return -1;
		}
		prev = temp;
		count++;
		temp = temp -> next;
	}

	return -1;
}
