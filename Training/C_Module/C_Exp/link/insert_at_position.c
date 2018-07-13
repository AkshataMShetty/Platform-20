#include "header.h"

int insert_at_pos(struct node **head, struct node *new, int input)
{
    //struct node *new = NULL;
    struct node *temp = *head;
	int count = 0;
	char *ptr = NULL;

	if(NULL == (ptr = (char*)malloc(sizeof(char) * MAX))){
		perror("memory exhausted");
		exit(EXIT_FAILURE);
	}
						 

	if (input == 0) {
		new->next = *head;
		*head = new;
    } else {
		temp = *head;
		while (temp) {
	    	count++;
	    	if (input == count) {
				new->next = temp->next;
				temp->next = new;
				break;
	    	}
	    	temp = temp->next;
		}
	}
	if (!temp) {
		return -1;
	} else {
	   	printf("Enter value for new node:\n");
	   	new->info = my_atoi(readinput(ptr));
		return input;
	}

	return input;
}
