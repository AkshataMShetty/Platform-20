#include "header.h"

int delete_at_pos(struct node **head, int input)
{
    int count = 0;
	struct node *temp = NULL;
	struct node *new = NULL;
	int num;
    
	if (input <= 0) {
		return -1;
    } else if (input == 1) {
		if (NULL == *head) {
	    	return 1;
		} else {
	    	num = delete_at_front(head);
	    	printf("Deleted element: %d\n", num);
		}
    } else if (input > 1) {
		if (NULL == *head || NULL == (*head)->next) {
	    	return -1;
		} else if (NULL != (*head)->next) {
	    	temp = *head;
	    	while (temp->next) {
				count++;
				if ((input - 1 ) == count) {
		    		new = temp->next;
		    		temp->next = new->next;
		    		new->next = NULL;
		    		num = new->info;
					free (new);
					printf ("Deleted element: %d\n", num);
					//temp = temp->next;
				} 
				else{
					temp = temp->next;
				}
			}
		}
	}

	return 0;
}
