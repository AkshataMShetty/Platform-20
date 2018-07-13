#include <stdio.h>
#include <stdlib.h>

#if 1
void print_status (FILE *fp)
{
	printf ();
}
int main()
{
    FILE *pFile;
    pFile = fopen("myfile.txt", "r");
    if (pFile == NULL) {
		printf("Error opening file");
		exit(1);
    } else {
		/* file operations here */
    }
    return 0;
}
#endif

#if 0

#include<stdio.h>
#include<stdlib.h>
int main()
{
		FILE *fp = fopen("myfile.txt", "w");

		if(fp == NULL)
		{
				printf("\n could not open file ");
				getchar();
				exit(1);
		}  

		fprintf(fp, "%s", "Geeks for Geeks");

	/* ....... */
		/* ....... */
		/* Something went wrong so terminate here */ 
		abort();

		getchar();
		return 0;  
}    
#endif
