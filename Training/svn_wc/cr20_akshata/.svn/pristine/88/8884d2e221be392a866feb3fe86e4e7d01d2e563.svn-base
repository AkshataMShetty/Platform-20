#include "header.h"

void free_list (struct master **mhead, int pos)
{
	struct master *mtemp = NULL;
	struct node *head = NULL;
	struct node *temp = NULL;
	int count = 1;
	int num;
	
	if (*mhead == NULL) {
		printf ("Empty list\n");
		return;
	} else if ((*mhead) -> mnext == *mhead) {
		if (pos == 1) {
			mtemp = *mhead;
			*mhead = NULL;
		} else {
			printf ("Invalid input");
			return;
		}
	} else {
		mtemp = *mhead;
		while (count < pos) {
			count++;
			mtemp = mtemp->mnext;
		}

		mtemp -> mprev -> mnext = mtemp -> mnext;
		mtemp -> mnext -> mprev = mtemp -> mprev;
		mtemp -> mnext = mtemp;
		mtemp -> mprev = mtemp;

		head = mtemp -> addr;
		mtemp -> addr = NULL;
		//temp = head;
		
		if (head -> next == head) {
			free (head);
			return;
		} else {
			while (head -> next != head) {
				temp = head -> prev;
				head -> prev = temp -> prev;
				temp -> prev -> next = head;
				temp -> next = temp -> prev = temp;
				num = temp -> info;
				free (temp);
				printf ("Deleted node: %d\n", num);
			}
			num = head -> info;
			free (head);
			head = NULL;
			printf ("Deleted node: %d\n", num);
			free (mtemp);
			mtemp = NULL;
		}
	}
}
