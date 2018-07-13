#include "header.h"

//converts a string of integers to its integer value and returns the value
int my_atoi (char * s)
{
    int n = 0;  //result
	int i;      //iteration var
	//int mult = 1;

	for (i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n = n * 10 + (s[i] - '0');
		} else {
			break;
		}
	}
	return n;
}

