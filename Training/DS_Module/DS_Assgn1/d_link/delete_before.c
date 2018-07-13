#include "header.h"

void delete_before (struct master **mhead, int pos, int value)
{
	struct master *mtemp = NULL;
	struct node *head = NULL;
	struct node *temp = NULL;
	int count = 1;
	mtemp = *mhead;
	while (count < pos) {
		count++;
		mtemp = mtemp -> mnext;
	}

	head = mtemp -> addr;
	if (head -> next == head) {
		if (head -> info == value) {
			return (delete_front (mhead, pos));
		} else {
			printf ("\'%d\' not found in list\n", value);
			return;
		}
	} else {
		//head = mtemp -> addr;
		temp = head;
		while (temp -> info != value) {
			temp = temp -> next;
			if (temp -> next == head) {
				printf ("\'%d\' not found in list\n", value);
				return;
			}
		}
		if (temp -> prev == head) {
			return (delete_front (mhead, pos));
		} else if (temp == head) {
			return (delete_end (mhead, pos));
		} else {
			temp = temp -> prev;
			temp -> prev -> next = temp -> next;
			temp -> next -> prev = temp -> prev;
			temp -> prev = temp -> next = temp;
			printf ("Deleted: %d\n", temp -> info);
			free (temp);
			temp = NULL;
			return;
		}
	}
}
