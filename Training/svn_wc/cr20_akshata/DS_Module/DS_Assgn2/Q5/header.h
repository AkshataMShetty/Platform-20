#include <stdio.h>
#include <stdlib.h>
#include "my_stack.c"

#define INT_BIT (sizeof (int) * 8)
//my_fgets.c
void my_fgets (int *);

//my_atoi.c
int my_atoi (char *);

//stack.c//operations on stack 
node * pop (stack *);
stack * push (stack *, int);
int get (node *);
int get_count (void);
node * make_node (void);

