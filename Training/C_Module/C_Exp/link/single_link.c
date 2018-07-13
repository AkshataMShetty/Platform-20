#include "header.h"

int main(void)
{
	struct node *head = NULL;
	struct node *temp = NULL;
	struct node *new = NULL;

	int choice;
	int input;
	//int count;
	int num;
	int i;
	
	char *ptr = NULL;
	if(NULL == (ptr = (char*)malloc(sizeof(char) * MAX))){
	    perror("memory exhausted");
		exit(EXIT_FAILURE);
	}

	printf ("Enter number of nodes:\n");
	num = my_atoi(readinput(ptr));

	new = makenode();
	printf ("Enter values for  %d nodes:\n", num);
	temp = new;
	for(i = 0 ; i < num ; i++)
	{
		if(head == NULL){
			head = new;
		}
		else{
			new = makenode();
			temp->next = new;
			temp -> info = my_atoi(readinput(ptr));
			temp = new;
		}
	}
	temp -> info = my_atoi(readinput(ptr));
	temp->next = NULL;
	temp = head;

	putchar ('\n');

	while (1) {
		printf ("1. Insert at front\n");
		printf ("2. Insert at end\n");
		printf ("3. Delete at front\n");
		printf ("4. Delete at end\n");
		printf ("5. Insert a node at specified position\n");
		printf ("6. Delete a node at specified position\n");
		printf ("7. Display\n");
		printf ("Enter any other key to exit\n");
		printf ("Enter your choice:\n");
		choice = my_atoi (readinput (ptr));

		switch (choice) {
		default:
		{
			while (head) {
				if (!head -> next) {
					free (head);
					break;
				}

				temp = head;
				while (temp -> next -> next) {
					temp = temp -> next;
				}
				free (temp -> next);
				temp -> next = NULL;
			}

			printf ("Bye bye..\n");
			exit (EXIT_SUCCESS);
		}
		break;

		case 1:
		{
			
			new = makenode();
			printf ("Enter value for new node:\n");
			new -> info = my_atoi (readinput (ptr));
			head = insert_at_front (head, new);
		}
		break;

		case 2:
		{
			new = makenode();
			printf ("Enter value for new node:\n");
			new -> info = my_atoi (readinput (ptr));

			head = insert_at_end(head, new);
		}
		break;

		case 3:
		{
			if (NULL == head)
			{
				printf("empty list\n");
			}
			else{
				num = delete_at_front (&head);
				printf ("Deleted element: %d\n", num);
			}
		}
		break;

		case 4:
		{
			if (NULL == head) {
				printf ("Empty list\n");
			} else {
				num = delete_at_end (&head);
				printf ("Deleted element: %d\n", num);
			}
		}
		break;
	
		case 5:
		{
			//count = 0;
			printf("Enter the position after which new node is to be inserted\n");
			input = my_atoi(readinput(ptr));
			printf ("Given position: %d\n", input);
			new = makenode();
			if (-1 == (num = insert_at_pos (&head, new, input))) {
				printf ("Invalid input\n");
			}
			/*
			if(input == 0){
				new -> next = head;
				head = new;
			} else {
				temp = head;
				while (temp) {
					count++;

					if (input == count) {
						new -> next = temp -> next;
						temp -> next = new;
						break;
					}
					temp = temp -> next;
				}

				if (!temp) {
					printf ("Invalid position\n");
					free (new);
				} else {
					printf ("Enter value for new node:\n");
					new -> info = my_atoi (readinput (ptr));
				}
			}	*/			
		}
		break;

		case 6:
		{
			//count = 0;
			printf("Enter the position at which node is to be deleted\n");
			input = my_atoi(readinput(ptr));
			printf ("Given position: %d\n", input);

			if (-1 == (num = delete_at_pos (&head, input))) {
				printf ("Invalid input\n");
			} else if (1 == num) {
				printf ("Empty list\n");
			}/*
			if (input <= 0) {
				printf ("Invalid input\n");
			} else if(input == 1){
				if (NULL == head)
				{
					printf("empty list\n");
				} else{
					num = delete_at_front (&head);
					printf ("Deleted element: %d\n", num);
				}
			} else if (input > 1){
				if (NULL == head || NULL == head -> next) {
					printf ("Invalid input\n");
				} else if (NULL != head -> next) {
					temp = head;
					while (temp -> next -> next) {
						count++;
						if ((input - 1) == count) {
							new = temp -> next;
							temp -> next = new -> next;
							new -> next = NULL;
							num = new -> info;
							free (new);
							printf ("Deleted element: %d\n", num);
						}
					}
				} *//*else {
					num = head -> info;
					free (head);
					printf ("Deleted element: %d\n", num);
				}
			}*/
		}
		break;

		case 7:
		{
			temp = head;
			printf ("List contents:\n");
			while(temp != NULL){	
				printf("%d\t", temp->info);
				temp = temp->next;
			}
			printf ("\n");
		}
		break;
		}
	}
	free (ptr);
	return 0;
}


