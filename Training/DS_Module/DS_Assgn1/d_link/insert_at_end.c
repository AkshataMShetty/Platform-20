#include "header.h"
struct node * insert_at_end(struct node *head, struct node *new)
{
	
	//struct node  = head;
	if (NULL == head) {
		head = new;
	} else if (head -> prev == head && head -> next == head) {
		head -> next = new;
		new -> next = head;
		head -> prev = new;
		new -> prev = head;
	} else {
		new -> prev = head -> prev;
	    new -> next = head;
		head -> prev -> next = new;
		head -> prev = new;
	}
	return(head);
}

