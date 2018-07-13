#include "header.h"

int delete_at_end(struct node **head)
{
    struct node *new = NULL;
    struct node *temp = NULL;
    int num;
    
	if (NULL == (*head)->next) {
		num = (*head) -> info;
		//printf("Deleted element: %d\n", head->info);
		free(*head);
		*head = NULL;
		return num;
    } else {
		temp = (*head);
		while (temp->next->next) {
	    	temp = temp->next;
		}
		new = temp->next;
		temp->next = NULL;

		//printf("Deleted element: %d\n", new->info);

		num = new -> info;
		free(new);
		return num;
    }
}
