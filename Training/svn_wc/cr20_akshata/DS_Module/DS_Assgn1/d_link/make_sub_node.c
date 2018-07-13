#include "header.h"

struct node* make_sub(void)
{
	struct node *new = NULL;
	if (NULL == (new = (struct node *) malloc (sizeof (struct node)))) {
		perror ("MAlloc failed");
		exit (EXIT_SUCCESS);
	}

	new -> next = new;
	new -> prev = new;

	return new;
}
