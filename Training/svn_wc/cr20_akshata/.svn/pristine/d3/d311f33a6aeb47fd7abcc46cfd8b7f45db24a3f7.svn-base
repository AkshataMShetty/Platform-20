#include "header.h"

int main (void)
{
	int choice;
	int num;
	node *front = NULL;
	node *rear = NULL;
	node *temp = NULL;

	while (1) {
		printf ("1. Insert\n");
		printf ("2. Delete\n");
		printf ("3. Display\n");
		printf ("Press any key to exit..\n");
		printf ("Enter your choice: ");
		my_fgets (&choice);

		switch (choice) {
		default:
		{
			if (front) {
				rear = NULL;
				while (front) {
					temp = front;
					front = front -> next;
					free (temp);
				}
			}
			printf ("Bye bye..\n");
			exit (EXIT_SUCCESS);
		}
		break;

		case 1:
		{

			temp = make_node ();
			printf ("Enter value for new node: ");
			my_fgets (&(temp -> info));

			insert (&front, &rear, temp);
		}
		break;

		case 2:
		{
			if (NULL == front) {
				printf ("Empty list\n");
				break;
			}
			num = delete_ (&front, &rear);
			printf ("Deleted: %d\n", num);

		}
		break;

		case 3:
		{
			if (front) {
				printf ("LIST CONTENTS:\n\t");
				temp = front;
				while (temp) {
					printf ("%d\t", temp -> info);
					temp = temp -> next;
				}
				putchar ('\n');
			} else {
				printf ("EMPTY LIST\n");
			}
		}
		break;
		}
	}
	return 0;
}
