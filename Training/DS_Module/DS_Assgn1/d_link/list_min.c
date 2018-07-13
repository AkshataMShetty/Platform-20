#include "header.h"

int list_min (struct master *mhead, int pos)
{
    int min = INT_MAX;
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
		if (min > temp->info) {
	    	min = temp -> info;
		}
		temp = temp->next;
    } while (temp != head);

	return min;
}
