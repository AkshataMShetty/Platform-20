#include "header.h"

node * make_node (void)
{
	node * temp = NULL;
	if (NULL == (temp = (node *) malloc (sizeof (node)))) {
		perror ("Malloc failed");
		exit (EXIT_FAILURE);
	}
	temp -> next = temp;
	temp -> prev = temp;
	return temp;
}
