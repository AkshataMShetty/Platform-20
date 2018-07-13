#include "header.h"

void delete_at_pos (struct master **mhead, int pos, int value)
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
		if(pos == 1){
			mtemp = *mhead;
			head = mtemp -> addr;
			temp = head;

			while (temp -> next != head) {
				if (count == value) {
					num = temp -> info;
					if (temp == head) {
						head = head -> next;
						mtemp -> addr = head;
					}
					temp -> prev -> next = temp -> next;
					temp -> next -> prev = temp -> prev;
					temp -> next = temp -> prev = temp;
					free (temp);
					printf ("Deleted node: %d\n", num);
					break;
				}
				count++;
				temp = temp -> next;
			}
		} else {
			printf ("Invalid input");
			return;
		}
	} else{
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
		temp = head;
		count = 1;

		while (head -> next != head) {
			if (count == value) {
				num = temp -> info;
				if (temp == head) {
					head = head -> next;
					mtemp -> addr = head;
				}
				temp -> prev -> next = temp -> next;
				temp -> next -> prev = temp -> prev;
				temp -> next = temp -> prev = temp;
				free (temp);
				printf ("Deleted node: %d\n", num);
				break;
			}
			count++;
			temp = temp -> next;
		}
	
	}
}
