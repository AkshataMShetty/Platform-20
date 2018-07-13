#include "header.h"

node * make_node (void)
{
	node *temp = NULL;

	if (NULL == (temp = (node *) malloc (sizeof (node)))) {
		perror ("Memory exhausted");
		exit (EXIT_FAILURE);
	}

	return temp;
}
