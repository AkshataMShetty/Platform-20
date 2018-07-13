#include "header.h"

void my_free(struct master *mhead)
{
    struct master *mtemp = NULL;
    struct node *head = NULL;
    struct node *temp = NULL;

	while (mhead != NULL) {
	    mtemp = mhead->mprev;
	    head = mtemp->addr;
	    while (head->next != head && head->prev != head) {
			temp = head->prev;
			head->prev = temp->prev;
			temp->prev = temp;
			head->prev->next = temp->next;
			temp->next = temp;
			//printf ("Freed: %d\n", temp -> info);
			free(temp);
	    }
	    //printf ("Freed: %d\n", mtemp -> addr -> info);
	    free(mtemp->addr);
	    if (mhead == mtemp) {
			free(mhead);
			mhead = NULL;
	    } else {
			mhead -> mprev = mtemp -> mprev;
			mtemp -> mprev -> mnext = mhead;
			mtemp -> mprev = mtemp;
			mtemp -> mnext = mtemp;
			free (mtemp);
		}
	}
}
