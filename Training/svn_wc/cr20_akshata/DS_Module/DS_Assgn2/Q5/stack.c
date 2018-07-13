#include "header.h"

node * pop (stack *sp)
{
	if (NULL != sp -> top) {
		node *np = sp -> top;
		sp -> top = np -> next;
		
		return np;
	} else {
		perror ("Empty stack");
		exit (EXIT_FAILURE);
	}

}

stack * push (stack *sp, int item)
{
	
	node *np = make_node ();

	np -> item = item;
	np -> next = sp->top;
	sp -> top = np;

	return sp;
}

node * make_node ()
{
	node *n = NULL;
	if (NULL == (n = (node *) malloc (sizeof (node)))) {
		perror ("Memory exhausted");
		exit (EXIT_FAILURE);
	}

	return n;
}
