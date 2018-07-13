#include "header.h"

struct master* make_master(char *ptr)
{
	struct master *new = NULL;
	if (NULL == (new = (struct master *) malloc (sizeof (struct master)))) {
		perror ("MAlloc failed");
		exit (EXIT_SUCCESS);
	}

	new -> mprev = new;
	new -> mnext = new;
	new -> addr = NULL;

	new -> addr = make_list (ptr);
	if (NULL == new -> addr) {
		free (new);
		return NULL;
	}
	
	return new;
}
