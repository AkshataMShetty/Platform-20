#include "header.h"

int delete_at_front(struct node **head)
{
    struct node *new = NULL;
    int temp;
    new = *head;
    *head = (*head)->next;
    new->next = NULL;
    temp = new->info;
    free(new);
	new = NULL;

    return temp;

}
