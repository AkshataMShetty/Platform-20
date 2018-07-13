#include "header.h"

struct node* delete_node (struct node* r,int value)
{
	struct node *temp = NULL;
	int num;
	if(r == NULL){
		printf("empty tree\n");
	}	
	else if(r -> data == value){
		if( (r -> left == NULL) && (r -> right == NULL)){
			num = r -> data;
			r = NULL;
			free(r);
			printf("deleted element is %d\n",num);
		}else{
			num = r -> data;
			temp = r;
			r -> data = temp -> left -> data;
			r -> left = temp -> left -> left;
			r -> left -> right = temp -> left -> right;
			temp = NULL;
			free(temp);
			printf("deleted element is %d\n",num);
		}
		
	}else if(value < r -> data ){
		r -> left = delete_node(r -> left, value);
	}else if(value > r -> data){
		r -> right = delete_node(r -> right, value);
	}
	else{
		printf("%d not found\n",value);
	}
	return r;
}
