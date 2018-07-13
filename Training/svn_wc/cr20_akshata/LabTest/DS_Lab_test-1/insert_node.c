#include "header.h"

struct node* insert_node(struct node *r, int value)
{

	if(r == NULL){
		r = (struct node*)malloc(sizeof(struct node));
		r -> data = value;
		r -> left = NULL;
		r -> right = NULL;
	}
	else if(value < r -> data){
		r -> left = insert_node(r->left,value);
	}
	else if(value > r -> data){
		r -> right = insert_node(r -> right,value);
	}
	return r;
}


