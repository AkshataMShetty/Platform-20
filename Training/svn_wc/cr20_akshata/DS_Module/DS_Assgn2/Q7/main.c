#include  "header.h"

int main (void)
{
	int num;
	int choice;
	int count;
	int pos;

	node *head = NULL;
	node *temp = NULL;
	node *new = NULL;

	while (1) {
		printf ("1. Insert at front\n");
		printf ("2. Insert at end\n");
		printf ("3. Delete at front\n");
		printf ("4. Delete at end\n");
		printf ("5. Insert at given position\n");
		printf ("6. Delete at given position\n");
		printf ("7. Display\n");
		printf ("Press any key to exit..\n");
		printf ("Enter your choice: ");
		my_fgets (&choice);

		switch (choice) {
		default :
		{
			temp = head;
			while (head) {
				temp = head -> prev;
				if (temp == head) {
					free (head);
					head = NULL;
				} else {
					temp -> prev -> next = temp -> next;
					temp -> next -> prev = temp -> prev;
					temp -> prev = temp;
					temp -> next = temp;
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

			if (NULL == head) {
				head = temp;
			} else if (head == head -> next) {
				head -> next = temp;
				temp -> next = head;
				head -> prev = temp;
				temp -> prev = head;
				head = temp;
			} else {
				temp -> next = head;
				temp -> prev = head -> prev;
				head -> prev -> next = temp;
				head -> prev = temp;
				head = temp;
			}
		}
		break;

		case 2:
		{
			temp = make_node ();
			printf ("Enter value for new node: ");
			my_fgets (&(temp -> info));

			if (NULL == head) {
				head = temp;
			} else if (head == head -> next) {
				head -> next = temp;
				temp -> next = head;
				head -> prev = temp;
				temp -> prev = head;
			} else {
				temp -> next = head;
				temp -> prev = head -> prev;
				head -> prev -> next = temp;
				head -> prev = temp;
			}
		}
		break;

		case 3:
		{
			if (NULL == head) {
				printf ("Empty list\n");
			} else if (head -> next == head) {
				num = head -> info;
				free (head);
				head = NULL;
				printf ("Deleted element: %d\n", num);
			} else {
				temp = head;
				head = head -> next;
				head -> prev = temp -> prev;
				temp -> prev -> next = head;
				temp -> prev = temp;
				temp -> next = temp;
				num = temp -> info;
				free (temp);
				temp = NULL;
				printf ("Deleted element: %d\n", num);
			}
		}
		break;

		case 4:
		{
			if (NULL == head) {
				printf ("Empty list\n");
			} else if (head -> next == head) {
				num = head -> info;
				free (head);
				head = NULL;
				printf ("Deleted element: %d\n", num);
			} else {
				temp = head -> prev;
				head -> prev = temp -> prev;
				temp -> prev -> next = head;
				temp -> prev = temp;
				temp -> next = temp;
				num = temp -> info;
				free (temp);
				temp = NULL;
				printf ("Deleted element: %d\n", num);
			}
		}
		break;

		case 5:
		{
			printf ("Enter position at which element is to be inserted: ");
			my_fgets (&pos);

			if (head == NULL && pos != 1) {
				printf ("Invalid input\n");
				break;
			}

			count = 1;
			temp = head;
			while (count <= (pos)) {
				if (temp -> next == head) {
					printf ("Invalid position\n");
					break;
				}

				count++;
				temp = temp -> next;
			}

			new = make_node ();

			printf ("Enter value for new node: ");
			my_fgets (&(new -> info));

			if (NULL == head) {
				head = new;
			} else if (head -> next == head && head -> prev == head) {
				head -> next = new;
				new -> next = head;
				head -> prev = new;
				new -> prev = head;
				head = new;
			} else {
				new -> next = temp;
				new -> prev = temp -> prev;
				temp -> prev = new;
				new -> prev -> next = new;
			}

			if (temp == head) {
				head = new;
			}
		}
		break;

		case 6:
		{
			if (head == NULL) {
				printf ("Empty list\n");
				break;
			}

			printf ("Enter position at wich node is to be deleted: ");
			my_fgets (&pos);

			if (head -> next == head && pos != 1) {
				printf ("Invalid input\n");
				break;
			} else {
				temp = head;
				if (pos <= 0) {
					printf ("Invalid position\n");
				} else if (pos == 1) {
					head = head -> next;
					head -> prev = temp -> prev;
					head -> prev -> next = head;
					temp -> next = temp -> prev = temp;
					num = temp -> info;
					free (temp);
					printf ("Deleted node: %d\n", num);
				} else {
					count = 1;
					while (count < pos) {
						if (temp -> next == head) {
							printf ("Invalid input\n");
							break;
						}
						count++;
						temp = temp -> next;
					}
					temp -> next -> prev = temp -> prev;
					temp -> prev -> next = temp -> next;
					temp -> next = temp -> prev = temp;
					num = temp -> info;
					free (temp);
					printf ("Deleted node: %d\n", num);
				}
			}
		}
		break;

		case 7:
		{
			temp = head;
			printf ("List contents:\n\t");
			do {
				printf ("%d\t", temp -> info);
				temp = temp -> next;
			} while (temp != head);
			printf ("\n");
		}
		break;
		}
	}
}
