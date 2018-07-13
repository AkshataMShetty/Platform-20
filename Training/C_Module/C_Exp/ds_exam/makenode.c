#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct node* makenode()
{
	struct node *new = NULL;
	 if(NULL == (new = (struct node*)malloc(sizeof(struct node)))){
	 	perror("No more memory");
		exit(EXIT_FAILURE);
	}
//	new -> item = data;
	new -> next = NULL;

	return new;
}
