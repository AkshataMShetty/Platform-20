#include <stdio.h>
#include <stdlib.h>

#define INT_BIT 256

struct node {
	int info;
	struct node *prev;
	struct node *next;
};

typedef struct node node;

//my_fgets.c
void my_fgets (int *);

//my_atoi.c
int my_atoi (char *);

//strip.c
void strip (char *);

//make_node.c
node * make_node (void);
