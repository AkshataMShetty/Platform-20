#include "header.h"

void delete_front (struct master **mhead, int pos)
{
	struct master *mtemp = NULL;
	struct node *head = NULL;
	struct node *temp = NULL;
	int count = 1;
	int num;

	if ((*mhead) -> mnext == *mhead) {
		head = (*mhead) -> addr;
		if (head -> next == head) {
			num = head -> info;
			free (head);
			head = NULL;
			printf ("Deleted: %d\n", num);
			*mhead = NULL;
		} else {
			temp = head -> next;
			num = head -> info;
			temp -> prev = head -> prev;
			head -> prev -> next = temp;
			head -> prev = head -> next = head;
			free (head);
			head = temp;
			printf ("Deleted: %d\n", num);
			(*mhead) -> addr = head;
		}
	} else {
		mtemp = *mhead;
		while (count < pos) {
			count++;
			mtemp = mtemp -> mnext;
		}
		head = mtemp -> addr;
		if (head -> next == head) {
			num = head -> info;
			free (head);
			head = NULL;
			printf ("Deleted: %d\n", num);
			mtemp -> mprev -> mnext = mtemp -> mnext;
			mtemp -> mnext -> mprev = mtemp -> mprev;
			if (mtemp == *mhead) {
				*mhead = mtemp -> mnext;
			}
			mtemp -> mprev = mtemp -> mnext = mtemp;
			free (mtemp);
		} else {
			temp = head -> next;
			num = head -> info;
			temp -> prev = head -> prev;
			head -> prev -> next = temp;
			head -> prev = head -> next = head;
			free (head);
			head = temp;
			printf ("Deleted: %d\n", num);
			mtemp -> addr = head;
		}
	}
}
