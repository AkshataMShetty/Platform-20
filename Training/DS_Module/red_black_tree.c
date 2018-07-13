/* 	Red Black Tree insertion
 *	Let x be the newly inserted node
 *	case 1: Perform standard BST insertion and make the color of newly inserted node as RED.
 * 	case 2:	If x is root,Change color of x as BLACK.
 *	case 3:	Do following if color of x's parent is not BLACK or x is not root:
 *			a) If x's uncle is RED(Grandparent must be BLACK)
 *				i)Change color of parent and uncle as BLACK.
 *				ii)Color of grandparent as RED.
 *				iii)Change x = x's grandparent, Repeat case2 and case3 for new x.
 *			b) If x's uncle is BLACK,then there are four configuration for x. x's parent(p) and x's grandparent(g).
 *				i)Left left case (p is left child of g and x is left child of p).
 *				ii)Left Right case (p is left child of g and x is right child of p).
 *				iii)Right Right case (Mirror of case a).
 *				iv)Right Left case (Mirror of case b).
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 255

int search(int val);

struct rbtNode
{
	int key;
	char color;
	struct rbtNode *left, *right, *parent;
};

struct rbtNode *root = NULL;

void leftRotate(struct rbtNode *x)
{
	struct rbtNode *y;

	y = x->right;
	x->right = y->left;

	if (y->left != NULL)
	{
		y->left->parent = x;

	}

	y->parent = x->parent;

	if (x->parent == NULL)
	{
		root = y;

	}

	else if ((x->parent->left != NULL) && (x->key == x->parent->left->key))
	{
		x->parent->left = y;

	}

	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
	return;

}

void rightRotate(struct rbtNode *y)
{
	struct rbtNode *x;

	x = y->left;
	y->left = x->right;

	if (x->right != NULL)
	{
		x->right->parent = y;

	}

	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;

	}

	else if ((y->parent->left != NULL) && (y->key == y->parent->left->key))
	{
		y->parent->left = x;

	}

	else

		y->parent->right = x;

	x->right = y;
	y->parent = x;

	return;

}

/* Recoloring of nodes */
void color_insert(struct rbtNode *z)
{
	struct rbtNode *y = NULL;

	while ((z->parent != NULL) && (z->parent->color == 'r'))                                       //case 3
	{

		if ((z->parent->parent->left != NULL) && (z->parent->key == z->parent->parent->left->key))	
		{
			if (z->parent->parent->right != NULL)

				y = z->parent->parent->right;

			if ((y != NULL) && (y->color == 'r'))
			{
				z->parent->color = 'b';

				y->color = 'b';

				z->parent->parent->color = 'r';

				if (z->parent->parent != NULL)

					z = z->parent->parent;

			}

			else
			{

				if ((z->parent->right != NULL) && (z->key == z->parent->right->key))                     
				{
					z = z->parent;

					leftRotate(z);															

				}

				z->parent->color = 'b';

				z->parent->parent->color = 'r';

				rightRotate(z->parent->parent);

			}

		}

		else
		{
			if (z->parent->parent->left != NULL)                                                     

				y = z->parent->parent->left;

			if ((y != NULL) && (y->color == 'r'))
			{
				z->parent->color = 'b';

				y->color = 'b';

				z->parent->parent->color = 'r';

				if (z->parent->parent != NULL)

					z = z->parent->parent;

			}

			else
			{

				if ((z->parent->left != NULL) && (z->key == z->parent->left->key))                       
				{
					z = z->parent;

					rightRotate(z);

				}

				z->parent->color = 'b';

				z->parent->parent->color = 'r';

				leftRotate(z->parent->parent);

			}

		}

	}
	root->color = 'b';                                                                                   //case 2                                                                                     												  

}

/* Insert a new node */
void insert(int val)                                                                                    //case 1
{
	struct rbtNode *x, *y;
	struct rbtNode *z ;
	if(NULL == (z = (struct rbtNode *) malloc(sizeof(struct rbtNode)))){
		printf("malloc failed\n");
		return ;
	}

	z->key = val;
	z->left = NULL;
	z->right = NULL;
	z->color = 'r';

	x = root;

	if (search(val) == 1)
	{
		printf("\nEntered element already exists in the tree\n");

		return;

	}

	if (root == NULL)
	{
		root = z;

		root->color = 'b';

		return;

	}

	while (x != NULL)
	{
		y = x;

		if (z->key < x->key)
		{
			x = x->left;

		}

		else
			x = x->right;

	}

	z->parent = y;

	if (y == NULL)
	{
		root = z;

	}

	else if (z->key < y->key)
	{
		y->left = z;

	}

	else
		y->right = z;

	color_insert(z);

	return;

}

/* To print the elements in inorder traversal*/
void inorderTree(struct rbtNode *root)
{
	struct rbtNode *temp = root;

	if (temp != NULL)
	{
		inorderTree(temp->left);

		printf(" %d--%c ", temp->key, temp->color);

		inorderTree(temp->right);

	}
	return;

}


/* To search the repeated elements */
int search(int val)
{
	struct rbtNode *temp = root;

	int diff;

	while (temp != NULL)
	{
		diff = val - temp->key;

		if (diff > 0)
		{
			temp = temp->right;
		}

		else if (diff < 0)
		{
			temp = temp->left;
		}

		else
		{
			return 1;
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	char *ptr = NULL;
	int choice, val, data, var, fl = 0;

	if(NULL == (ptr = malloc(sizeof(char) * MAX))){
		printf("malloc failed");
		return 0;
	}

	while (1)
	{
		printf("\nRed Black Tree Management - Enter your choice :\n1:Insert  2:Traversal\n  3:Exit\n");
		if(NULL == (fgets(ptr, MAX, stdin))){
			printf("fgets failed");
			return 0;
		}
		choice = atoi(ptr);
		switch (choice)
		{
			case 1:
				printf("Enter the integer you want to add : ");
				if(NULL == (fgets(ptr, MAX, stdin))){
					printf("fgets failed");
					return 0;
				}
				val = atoi(ptr);
				insert(val);
				break;

			case 2:
				if (root != NULL)
				{
					printf("root is %d-- %c", root->key, root->color);
					printf("\nInorder tree traversal\n");
					inorderTree(root);
				}
				break;

			case 3:
				fl = 1;
				break;

			default:
				printf("\nInvalid Choice\n");

		}

		if (fl == 1)
		{
			break;
		}

	}
	free(ptr);
	return 0;
}
