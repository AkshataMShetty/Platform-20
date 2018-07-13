#include "header.h"
int main()
{
	int data;
	int choice;
	char *ptr;
	if(NULL == (ptr = (char*)malloc(sizeof(char) * MAX))){
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	struct node *root = NULL;
	while(1){
		printf("1.insert a node\n");
		printf("2.delete a node\n");
		printf("3.display\n");
		printf("4.exit\n");
		printf("enter the choice\n");
		if(NULL == (ptr = fgets(ptr,MAX,stdin))){
			perror("fgets failed");
			exit(EXIT_FAILURE);
		}
		choice = atoi(ptr);
		switch(choice){
			case 1 : printf("enter the data to be inserted\n");
					if(NULL == (ptr = fgets(ptr,MAX,stdin))){
						perror("fgets failed");
						exit(EXIT_FAILURE);
					}
					data = atoi(ptr);
					root = insert_node(root, data);
					break;
			case 2: printf("enter the element\n");
					if(NULL == (ptr = fgets(ptr,MAX,stdin))){
						perror("fgets failed");
						exit(EXIT_FAILURE);
					}
					data = atoi(ptr);
					root = delete_node(root,data);
					break;
			case 3:
					display(root);
					break;
			case 4:exit(EXIT_FAILURE);
			default : printf("invalid input\n");
		}
	}
	free(ptr);
	return 0;
}
