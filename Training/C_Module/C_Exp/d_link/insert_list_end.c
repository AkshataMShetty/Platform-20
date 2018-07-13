#include "header.h"

struct master *insert_list_end (struct master *mhead, int pos, char *ptr)
{
    struct master *mtemp = mhead;
    //struct node *temp = NULL;
    struct node *head = NULL;
    struct node *new = NULL;
    int count = 1;

    while (count < pos) {
		count++;
		mtemp = mtemp->mnext;
    }

    head = mtemp->addr;
    //temp = head;
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
		new -> prev = head -> prev;
		new -> next = head;
		head -> prev -> next = new;
		head -> prev = new;
		head = new;
    }

	return mhead;
}
