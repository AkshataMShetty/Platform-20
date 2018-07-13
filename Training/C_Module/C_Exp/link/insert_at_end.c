#include "header.h"
struct node * insert_at_end(struct node *head, struct node *new)
{
	
	struct node *temp = head;
	if (NULL != head) {
		while (temp -> next) {
			temp = temp -> next;
		}
		temp -> next = new;
	} else {
		head = new;
	}
	return(head);
}

