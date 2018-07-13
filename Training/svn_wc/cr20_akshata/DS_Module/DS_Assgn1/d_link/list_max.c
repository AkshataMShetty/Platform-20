#include "header.h"

int list_max (struct master *mhead, int pos)
{
    int max = INT_MIN;
    struct node *head = NULL;
    struct node *temp = NULL;
    struct master *mtemp = mhead;
    int count = 1;

    while (count < pos) {
		count++;
		mtemp = mtemp->mnext;
    }
    
	printf("List %d\n\t", pos);
	fwd_display (mhead, pos);
    head = mtemp->addr;
    temp = head;
    
	do {
		if (max < temp->info) {
	    	max = temp -> info;
		}
		temp = temp->next;
    } while (temp != head);

	return max;
}
