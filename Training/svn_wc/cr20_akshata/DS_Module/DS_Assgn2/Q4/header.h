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
void insert_at_end (node **, node **, node*);

//insert_at_front.c
void insert_at_front (node **, node **, node*);

//insert_at_mid.c
int insert_at_mid (node **, node **, node *);

//insert_at_pos.c
void insert_at_pos (node **, node **, node *, int);

//delete_at_front.c
int delete_at_front (node **, node **);

//delete_at_end.c
int delete_at_end (node **, node **);

//delete_at_mid.c
int delete_at_mid (node **, node **);

//delete_at_pos.c
int delete_at_pos (node **, node **, int);
