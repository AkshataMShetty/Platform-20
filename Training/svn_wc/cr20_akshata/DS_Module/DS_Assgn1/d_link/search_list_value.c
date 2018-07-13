#include "header.h"

int search_list_value(struct master * mhead, int pos, int value)
{
	struct node *head = NULL;
	struct node *temp = NULL;
	struct master *mtemp = mhead;
	int count = 1;
	int i = 0;
/*
	while(--pos) {
		mtemp = mtemp -> mnext;
	}*/
	while (count < pos) {
		count++;
		mtemp = mtemp->mnext;
	}
	printf ("List %d\n\t", pos);
	count = 0;
	printf("Position where \'%d\' occur: ",value);
	head = mtemp -> addr;
	temp = head;
//	while(temp -> next != head) {
	do {
		i++;
//		printf ("\"%d %d %d\" ", i, count, temp -> info);
		if(value == temp -> info){
			count++;
			printf("%d\t ", i);
		}
		temp = temp -> next;
	} while(temp != head);
	if (0 == count) {
		printf ("None\n");
	}
	printf ("\n");
	
	return count;
}
