#include "header.h"

int main (void)
{
	int choice;
	int item;
	int front = -1;
	int rear = -1;
	int i;
	int que[QUEUE_SIZE];

	while (1) {
		printf ("1. Insert\n");
		printf ("2. Delete\n");
		printf ("3. Display\n");
		printf ("Press any other key to quit\n");
		printf ("Enter your choice: ");
		my_fgets (&choice);

		switch (choice)
		{
		
		default:
		{
			printf ("Bye bye..\n");
			exit (EXIT_SUCCESS);
		}
		break;

		case 1:
		{
			if (((rear + 1) % QUEUE_SIZE) == front) {
				printf ("Queue is full\n");
			} else {
				printf ("Enter integer to insert: ");
				my_fgets (&item);
				rear = (rear + 1) % QUEUE_SIZE;
				que[rear] = item;
			}
		}
		break;

		case 2:
		{
			if (front == rear) {
				printf ("Queue is empty\n");
			} else {
				front = (front + 1) % QUEUE_SIZE;
				item = que[front];
				printf ("Removed item is: %d\n", item);
			}
		}
		break;

		case 3:
		{
			if (front == rear) {
				printf ("Queue is empty\n");
			} else {
				printf ("List contents:\n\t");
				if (front <= rear) {
					for (i = (front + 1) % QUEUE_SIZE; i <= rear; i++) {
						printf ("%d\t", que[i]);
					}
					printf ("\n");
				} else {
					for (i = (front + 1) % QUEUE_SIZE; i < QUEUE_SIZE; i++) {
						printf ("%d\t", que[i]);
					}
					i = 0;
					while (i <= rear) {
						printf ("%d\t", que[i++]);
					}
					printf ("\n");
				}
			}
		}
		break;
		}
	}

	return 0;
}
