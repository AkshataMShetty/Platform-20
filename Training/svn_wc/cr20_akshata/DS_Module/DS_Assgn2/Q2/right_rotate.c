#include "header.h"

void right_rotate (node **front, node **rear) {
	node *new_front = NULL;
	node *new_rear = NULL;

	new_rear = *front;
	while (new_rear -> next != *rear) {
		new_rear = new_rear -> next;
	}

	new_front = *rear;
	new_front -> next = *front;
	new_rear -> next = NULL;

	*front = new_front;
	*rear = new_rear;
}
