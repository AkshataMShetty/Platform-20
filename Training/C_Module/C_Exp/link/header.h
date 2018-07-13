#include <stdio.h>
#include <stdlib.h>

#define MAX 256

struct node{
    int info;
	struct node *next;
};

//my_fgets.c
char * readinput (char *);

//my_atoi.c
int my_atoi(char *);

//To create node
struct node* makenode();

//insert_at_front.c
struct node * insert_at_front (struct node *, struct node *);

//insert_at_end.c
struct node * insert_at_end (struct node *, struct node *);

//delete_at_front.c
int delete_at_front (struct node **);

//delete_at_end.c
int delete_at_end (struct node **);

//insert_at_position.c
int insert_at_pos (struct node **, struct node *, int);

//delete_at_position.c
int delete_at_pos (struct node **, int);
