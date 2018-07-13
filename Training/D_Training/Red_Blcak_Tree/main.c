#include "header.h"

struct node *parent(struct node *n)
{
	return n->parent;
}

struct node *grandparent(struct node *n)
{
	struct node *p = parent(n);
	if(p == NULL)
		return NULL;
	return parent(p);
}

struct node *sibling(struct node *n)
{
	struct node *p = parent(n);
	if(p == NULL)
		return NULL;
	if(n == p->left)
		return p->right;
	else
		return p->left;
}

struct node *uncle(struct node *n)
{
	struct node *p = parent(n);
	struct node *g = grandparent(n);
	if(g == NULL)
		return NULL;
	return sibling(p);
}

void rotate_left(struct node *n)
{
	struct node *nnew = n->right;
	assert(nnew != LEAF);
	n->right = nnew->left;
	nnew->left = n;
	nnew->parent = n->parent;
	n->parent = nnew;
}

void rotate_right(struct node *n)
{
	struct node *nnew = n->left;
	assert(nnew != LEAF);
	n->left = nnew->right;
	nnew->right = n;
	nnew->parent = n->parent;
	n->parent = nnew;
}

struct node *insert(struct node *root, struct node *n)
{
	insert_recurse(root,n);
	insert_repair_tree(n);
	root = n;
	while(parent(root) != NULL)
		root = parent(root);
	return root;
}

void insert_recurse(struct node *root, struct node *n)
{
	if(root != NULL && n->key < root->key)
	{
		if(root->left != LEAF){
			insert_recurse(root->left,n);
			return;
		}
		else
			root->left = n;
	}
	else if(root != NULL){
		if(root->right != LEAF){
			insert_recurse(root->right,n);
			return;
		}
		else
			root -> right = n;
	}
	n->parent = root;
	n->left = LEAF;
	n->right = LEAF;
	n->color = red;
}

void insert_repair_tree(struct node *n)
{
	if(parent(n) == NULL)
		insert_case1(n);
	else if(parent(n)->color == black)
		insert_case2(n);
	else if(uncle(n)->color == red)
		insert_case3(n);
	else
		insert_case4(n);
}

void insert_case1(struct node *n)
{
	if(parent(n) == NULL)
		n->color = black;
}

void insert_case2(struct node *n)
{
	return ;
}

void insert_case3(struct node *n)
{
	parent(n) -> color = black;
	uncle(n) -> color = black;
	grandparent(n) -> color = red;
	insert_repair_tree(grandparent(n));
}

void insert_case4(struct node *n)
{
	struct node *p = parent(n);
	struct node *g = grandparent(n);
	if(n == g->left->right){
		rotate_left(p);
		n = n->left;
	}else if(n == g->right->left){
		rotate_right(p);
		n = n -> right;
	}
	insert_case4_step2(n);
}

void insert_case4_step2(struct node *n)
{
	struct node *p = parent(n);
	struct node *g = grandparent(n);
	if(n == p->left)
		rotate_right(g);
	else
		rotate_left(g);
	p->color = black;
	p->color = red;
}
