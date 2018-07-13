#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 256
#define INT_BIT (sizeof (int) * 8)
//my_fgets.c
void my_fgets (int *);

//my_atoi.c
int my_atoi (char *);

//stack.c
//operations on stack 
void push (int *, int *, int);
int pop (int *, int *);
