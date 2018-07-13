#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_SIZE 10
#define INT_BIT (sizeof (int) * 8)

struct node {
	int info;
	struct node *next;
};

typedef struct node node;

//my_fgets.c
void my_fgets (int *);

//my_atoi.c
int my_atoi (char *);

//make_node.c
node * make_node (void);

//insert_at_end.c
void insert (node **, node **, node*);

//delete_at_front.c
int delete_ (node **, node **);

