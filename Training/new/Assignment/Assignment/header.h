
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <limits.h>
#include <string.h>

#define MAX 1000

//Validate the buffer
int validate(char *);

//validation for alphanumeric
int alpha_numeric(const char *);

//validation for numeric
int numeric(const char *);
