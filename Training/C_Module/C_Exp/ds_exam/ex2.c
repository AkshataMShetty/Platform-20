#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"
struct node* makenode();
char* readinput(char *);


struct node *insert(int value, struct node *head)
{
    struct node *temp = NULL;
    struct node *new = NULL;

	temp = head;
    if (head == NULL) {
		/*head->item = value;
		head->next = NULL;*/

		new = makenode();
		head = new;
		new -> item = value;

    } else {
		while(temp->item < value) {
			temp = temp -> next;
	    }
		if(temp -> next == NULL)
		{
	    	new->item = value;
	    	new->next = NULL;
	    	temp->next = new;
		}
    	else {
			new->item = value;
			new->next = temp->next;
			temp->next = new;
    	}
	}
	temp = head;
    return temp;
}

int main(void)
{
    struct node *head = NULL;
	struct node *temp = NULL;
	struct node *new = NULL;

    char *ptr = NULL;
	int num;
	int i;
	int value;

    if (NULL == (ptr = (char *) malloc(sizeof(char) * 255))) {
		printf("malloc failure");
		exit(EXIT_FAILURE);
    }

    printf("Enter number of nodes:\n");
    num = atoi(readinput(ptr));

    new = makenode();
    printf("Enter values for  %d nodes:\n", num);
    temp = new;
    for (i = 0; i < num; i++) {
		if (head == NULL) {
		    head = new;
		
		} else {
	    	new = makenode();
	    	temp->next = new;
	    	temp->item = atoi(readinput(ptr));
	    	temp = new;

		}
    }
    temp->item = atoi(readinput(ptr));
    temp->next = NULL;
    temp = head;

	while(temp!= NULL){	
		printf("%d\t", temp->item);
		temp = temp->next;
	}

    printf("enter the value to be inserted\n");
    value = atoi(readinput(ptr));

    temp = insert(value, head);

				
	printf ("List contents:\n");
	while(temp != NULL){	
		printf("%d\t", temp->item);
		temp = temp->next;
	}
	printf ("\n");

    return 0;
}
