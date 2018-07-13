#include "header.h"

struct node * make_list (char *ptr)
{
	struct node *head = NULL;
	struct node *temp = NULL;
	int num;
	int i;

	printf ("Enter number of nodes: ");
	num = my_atoi (readinput (ptr));
	if (0 == num) {
		return NULL;
	}

	for (i = 1; i <= num; i++) {
		temp = make_sub();
		printf ("Enter value %d: ", i);
		temp -> info = my_atoi (readinput (ptr));
		head = insert_at_end (head, temp);
	}

	return head;
}
