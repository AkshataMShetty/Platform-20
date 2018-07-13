#include "header.h"

struct master *insert_list_after (struct master *mhead, int pos, int value, char *ptr)
{
    struct master *mtemp = mhead;
    struct node *temp = NULL;
    struct node *head = NULL;
    struct node *new = NULL;
    int count = 1;

    while (count < pos) {
		count++;
		mtemp = mtemp->mnext;
    }

    head = mtemp->addr;
    temp = head;
	while (temp -> info != value && temp -> next != head) {
		temp = temp -> next;
	}

	if (temp == head -> prev && temp -> info != value) {
		printf ("Value not found\n");
		return mhead;
	}

    new = make_sub();

	printf ("Enter value for new node: ");
	new -> info = my_atoi (readinput (ptr));

    if (NULL == head) {
		head = new;
    } else if (head -> next == head && head -> prev == head) {
		head -> next = new;
		new -> next = head;
		head -> prev = new;
		new -> prev = head;
    } else {
		new -> next = temp -> next;
		new -> prev = temp -> next -> prev;
		temp -> next -> prev = new;
		temp -> next = new;
    }

	return mhead;
}
