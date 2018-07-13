#include "header.h"

//function to safely take integer input from user
void my_fgets (int *num)
{
	char *str = NULL;
				
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
	
		strip (str);	
	} while (NULL == str);
			
	*num = my_atoi (str);
	//printf ("num = %d\n\n", *num);

	free (str);
}
