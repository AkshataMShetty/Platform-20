#include "header.h"

node * make_node (void)
{
	node *temp = NULL;
	if (NULL == (temp = (node *) malloc (sizeof (node)))) {
		perror ("MAlloc failed");
		exit (EXIT_FAILURE);
	}

	temp -> next = NULL;

	return temp;
}
