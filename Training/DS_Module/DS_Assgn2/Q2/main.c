#include "header.h"

int main(void)
{
	struct node *front = NULL;
	struct node *rear = NULL;
	struct node *temp = NULL;
	struct node *new = NULL;

	int choice;
	int num;
	char *ptr;
	
	if(NULL == (ptr = (char*)malloc(sizeof(char)))){
	    perror("buffer full");
		exit(EXIT_FAILURE);
	}
	
	while (1) {
		printf ("1. EnQ\n");
		printf ("2. DeQ\n");
		printf ("3. Left rotate\n");
		printf ("4. Right rotate\n");
		printf ("5. Display\n");
		printf ("Enter any other key to exit..\n");
		printf ("Enter your choice: \n");
		my_fgets (&choice);

		switch (choice) {
		default:
		{
			rear = NULL;
			while (front) {
				temp = front;
				front = front -> next;
				free (temp);
			}
			front = NULL;

			printf ("Bye bye..\n");
			exit (EXIT_SUCCESS);
		}
		break;

		case 1:
		{
			new = make_node ();
			
			printf ("Enter value for new node:\n");
			my_fgets (&(new -> info));
			
			enq (&rear, new);
			if (front == NULL) {
				front = new;
			}	
		}
		break;

		case 2:
		{
			if (front) {
				num = deq (&front, &rear);
				printf ("Deleted element: %d\n", num);
			} else {
				printf ("Empty queue\n");
			}
		}
		break;

		case 3:
		{
			if (front != rear) {
				left_rotate (&front, &rear);
			} else if (!front){
				printf ("Empty queue\n");
			}
		}
		break;

		case 4:
		{
			if (front != rear) {
				right_rotate (&front, &rear);
			} else if (!front){
				printf ("Empty queue\n");
			}
		}
		break;

		case 5:
		{
			printf ("List contents:\n\t");
			temp = front;
			while(temp != NULL){	
				printf("%d\t", temp->info);
				temp = temp->next;
			}
			putchar ('\n');
		}
		break;
		}

	}

	free (ptr);
	return 0;
}


