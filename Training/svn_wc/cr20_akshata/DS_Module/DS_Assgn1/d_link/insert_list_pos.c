#include "header.h"

struct master *insert_list_pos (struct master *mhead, int pos, int value, char *ptr)
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

	//printf("count : %d\n",count);
    head = mtemp->addr;
    temp = head;
	count = 1;
	while (count <= (value - 1) /*&& temp -> next != head*/) {
		if (temp -> next == head) {
			printf ("Invalid position\n");
			return mhead;
		}
		printf("count : %d\n",count);
		count++;
		temp = temp -> next;
	}
	printf("count : %d\n", count);
	printf("pos : %d\n", value);

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
		head = new;
    } else {
		new -> next = temp;
		new -> prev = temp -> prev;
		temp -> prev = new;
		new -> prev -> next = new;
    }
	if (temp == head) {
		head = new;
		mtemp -> addr = head;
	}
	printf("info : %d\n",temp -> info);
	return mhead;
}
