#include "header.h"

void delete_end (struct master **mhead, int pos)
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
			temp = head -> prev;
			num = temp -> info;
			head -> prev = temp -> prev;
			head -> prev -> next = head;
			temp -> prev = temp -> next = temp;
			free (temp);
		//	head = temp;
			printf ("Deleted: %d\n", num);
	//		(*mhead) -> addr = head;
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
			temp = head -> prev;
			num = temp -> info;
			head -> prev = temp -> prev;
			head -> prev -> next = head;
			temp -> prev = temp -> next = temp;
			free (temp);
		//	head = temp;
			printf ("Deleted: %d\n", num);
		//	mtemp -> addr = head;
		}
	}
}
