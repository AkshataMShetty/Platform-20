#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 256

struct node{
	int info;
	struct node *next;
	struct node *prev;
};

struct master{
	struct node *addr;
	struct master *mnext;
	struct master *mprev;
};

//my_atoi.c
int my_atoi(char *);

//my_fgets.c
char* readinput(char *);

//my_free.c
void my_free (struct master *);

//make_master_node.c
struct master * make_master (char *);

//make_sub_node.c
struct node * make_sub (void);

//make_list.c
struct node * make_list (char *);

//insert_at_end.c
struct node * insert_at_end (struct node *, struct node *);

//count_masters.c
int count_masters (struct master *);

//fwd_display.c
void fwd_display (struct master *, int);

//rev_display.c
void rev_display (struct master *, int);

//display.c
void display (struct master *);

//insert_list_front.c
struct master * insert_list_front (struct master *, int, char *);

//insert_list_end.c
struct master * insert_list_end (struct master *, int, char *);

//insert_list_after.c
struct master * insert_list_after (struct master *, int, int, char *);

//insert_list_before.c
struct master * insert_list_before (struct master *, int, int, char *);

//insert_list_pos.c
struct master * insert_list_pos (struct master *, int, int, char *);

// search_list_value.c
int search_list_value(struct master * , int , int );

// search_list_system.c
void search_list_system (struct master *, int );

//list_max.c
int list_max (struct master *, int);

//system_max.c
int system_max (struct master *);

//list_min.c
int list_min (struct master *, int);

//system_min.c
int system_min (struct master *);

//delete_value.c
void delete_value (struct master **, int, int);

//delete_after.c
void delete_after (struct master **, int, int);

//delete_before.c
void delete_before (struct master **, int, int);

//delete_front.c
void delete_front (struct master **, int);

//delete_end.c
void delete_end (struct master **, int);

//delete_at_pos.c
void delete_at_pos (struct master **, int, int);

//free_list.c
void free_list (struct master**, int);
