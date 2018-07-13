#include "header.h"

void insert_at_pos (node **front, node **rear, node *new, int pos)
{
	int count = 0;
	node *temp = NULL;
	//int i;

	if (1 == pos) {
		if (*front) {
			insert_at_front (front, rear, new);
			return;
		}
	} else if (pos < 0) {
		printf ("Invalid position\n");
		return;
	}

	//place a pointer before the node at desired position
	temp = *front;
	for (count = 1; temp && count < pos - 1;) {
		//printf ("%d\n", temp -> info);
		if (NULL == temp -> next) {
			if ((count + 1) == (pos - 1)) {
				insert_at_end (front, rear, new);
			} else {
				printf ("Invalid position\n");
				return;
			}
		}
		count++;
		temp = temp -> next;
	}
	if (count <= pos) {
		printf ("Invalid position\n");
		return;
	}

	//insert new node at middle position
	new -> next = temp -> next;
	temp -> next = new;

	//printf ("%d\n");

	//return count + 1;


}
