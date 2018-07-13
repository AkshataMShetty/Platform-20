#include "header.h"

int main (void)
{
	stack *head = NULL;
	node *temp = NULL;

	int choice;
	int item;

	if (NULL == (head = (stack *) malloc (sizeof (stack)))) {
		perror ("Malloc failed");
		exit (EXIT_FAILURE);
	}

	while (1) {
		printf  ("1. Push\n");
		printf  ("2. Pop\n");
		printf  ("3. Display\n");
		printf  ("Press any other key to quit\n");
		my_fgets (&choice);

		switch (choice)
		{
		
		default :
		{
			printf ("Bye bye..\n");
			exit (EXIT_SUCCESS);
		}
		break;

		case 1:
		{
			printf ("Enter integer to push: ");
			my_fgets (&item);
			printf ("Given item: %d\n", item);

			head = push (head, item);
		}
		break;

		case 2:
		{
			temp = pop (head);
			printf ("Popped item is: %d\n", temp -> item);

			free (temp);
		}
		break;

		case 3:
		{
			temp = head -> top;
			if (temp) {
				printf ("%d\n", temp -> item);
			}

			while (temp -> next) {
				temp = temp -> next;
				printf ("%d\n", temp -> item);
			}
			printf ("End of List\n");
		}
		break;
		}
	}

	while (head -> top) {
		free (pop (head));
	}

	free (head);

	return 0;
}
