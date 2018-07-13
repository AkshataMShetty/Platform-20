#include "header.h"

struct node* insert_at_front(struct node* head, struct node *new)
{
	new -> next = head;
	head = new;
	return head;
}
