#include "header.h"

void push (int *stack, int *top, int item)
{
	if (*top == MAX) {
		printf ("Stack full\n");
	} else {
		stack[++*top] = item;
	}
}
