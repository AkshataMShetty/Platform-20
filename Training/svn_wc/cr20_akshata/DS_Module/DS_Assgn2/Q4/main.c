#include "header.h"

int main (void)
{
	int choice;
	int num;
	int pos;
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
			printf ("INSERT OPERATIONS:\n");
			printf ("1. Insert at Rear end\n");
			printf ("2. Insert at Front end\n");
			printf ("3. Insert at Middle\n");
			printf ("4. Insert at Specified position\n");
			printf ("Press any key return to main menu..\n");
			printf ("Enter your choice: ");
			my_fgets (&choice);

			switch (choice) {
			case 1:
			{
				temp = make_node ();
				printf ("Enter value for new node: ");
				my_fgets (&(temp -> info));

				insert_at_end (&front, &rear, temp);
			}
			break;

			case 2:
			{
				temp = make_node ();
				printf ("Enter value for new node: ");
				my_fgets (&(temp -> info));

				insert_at_front (&front, &rear, temp);
			}
			break;

			case 3:
			{
				temp = make_node ();
				printf ("Enter value for new node: ");
				my_fgets (&(temp -> info));

				num = insert_at_mid (&front, &rear, temp);

				printf ("Inserted at position %d\n", num);
			}
			break;

			case 4:
			{
				temp = make_node ();
				printf ("Enter value for new node: ");
				my_fgets (&(temp -> info));

				printf ("Enter position to insert new node: ");
				my_fgets (&pos);

				insert_at_pos (&front, &rear, temp, pos);

				//printf ("Inserted at position %d\n", num);
			}
			break;
			}
		}
		break;

		case 2:
		{
			if (NULL == front) {
				printf ("Empty list\n");
				break;
			}
			printf ("DELETE OPERATIONS\n");
			printf ("1. Delete at Rear End\n");
			printf ("2. Delete at Front End\n");
			printf ("3. Delete at Middle Position\n");
			printf ("4. Delete at Specified Position\n");
			printf ("Press any key return to main menu..\n");
			printf ("Enter your choice: \n");
			my_fgets (&choice);

			switch (choice) {
			case 1:
			{
				num = delete_at_end (&front, &rear);
				printf ("Deleted: %d\n", num);
			}
			break;

			case 2:
			{
				num = delete_at_front (&front, &rear);
				printf ("Deleted: %d\n", num);
			}
			break;

			case 3:
			{
				num = delete_at_mid (&front, &rear);
				printf ("Deleted: %d\n", num);
			}
			break;

			case 4:
			{
				printf ("Enter position to delete node: ");
				my_fgets (&pos);
				
				num = delete_at_pos (&front, &rear, pos);
				if (num > 1) {
					printf ("Deleted: %d\n", num);
				} else {
					printf ("Invalid position");
				}
			}
			break;
			}
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
