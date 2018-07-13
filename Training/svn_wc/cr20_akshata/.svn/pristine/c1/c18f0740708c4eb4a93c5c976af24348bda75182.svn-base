#include "header.h"

//function to safely take integer input from user
void my_fgets (int *num)
{
	char *str = NULL;
	int i;				//iteration var
				
	if (NULL == (str = (char *) malloc (sizeof (int) * 8))) {
		perror ("malloc() failed.\n");
		exit (EXIT_FAILURE);
	}
				
	fflush (stdin);
	
	do {
		if (NULL == (fgets (str, INT_BIT, stdin))) {
			perror ("read failed");
			exit (EXIT_FAILURE);
		}
	
		//validate input. Truncate input where non-integer character is found
		for (i = 0; i < INT_BIT && !(str[i] >= '0' && str[i] <= '9'); i++) {
			str[i] = '\0';
			break;
		}
	
	} while (NULL == str);
			
	*num = my_atoi (str) % INT_MAX;

	free (str);
}
