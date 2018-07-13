#include "header.h"

int main (void)
{
	int *stack = NULL;

	int choice;
	int item;
	int top = -1;
	int i;
	int n;

	if (NULL == (stack = (int *) malloc (sizeof (stack) * MAX))) {
		perror ("Malloc failed");
		exit (EXIT_FAILURE);
	}

	while (1) {
		printf  ("1. Push\n");
		printf  ("2. Pop\n");
		printf  ("3. Display\n");
		printf  ("4. Push n items\n");
		printf  ("5. Pop n items\n");
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

			push (stack, &top, item);
		}
		break;

		case 2:
		{
			item = pop (stack, &top);

			printf ("Popped item is: %d\n", item);
		}
		break;

		case 3:
		{
			for (i = top; i >= 0; i--) {
				printf("%d\t", stack[i]);
			}
			printf ("\n");
		}
		break;

		case 4:
		{
			printf ("Enter number of items to push: ");
			my_fgets (&n);

			for (i = 1; i < n; i++) {
				
				printf ("Enter integer to push: ");
				my_fgets (&item);
				printf ("Given item: %d\n", item);

				push (stack, &top, item);
			}
		}
		break;

		case 5:
		{
			printf ("Enter number of items to push: ");
			my_fgets (&n);

			for (i = 1; i < n; i++) {
				
				item = pop (stack, &top);
				printf ("Popped item is: %d\n", item);
			}
		}
		break;
		}
	}

	return 0;
}
