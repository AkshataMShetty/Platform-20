#include "header.h"

int main (int argc,char *argv[])
{
	FILE *ip;
	FILE *op;

	//VALIDATION FOR COMMAND LINE ARGUMENTS
	if(argc != 3) {
		printf("USAGE ./a.out : input_filename output_filename\n");
		exit(EXIT_FAILURE);
	}

	//OPENING INPUT FILE
	if((ip = fopen(argv[1], "r")) == NULL) {
		perror(" ");
		exit(EXIT_FAILURE);
	}


	//OPENING OUTPUT FILE
	if((op = fopen(argv[2], "w")) == NULL) {
		perror(" ");
		fclose(ip);
		exit(EXIT_FAILURE);
	}
	

	//TO READ ONE LINE AT A TIME
	char *line = NULL;
	int len = 0;
	char *line1 = NULL;

	if(NULL == (line = (char *)malloc(sizeof(char) * MAX))) {
		perror (" ");
		fclose(op);
		fclose(ip);
		exit (EXIT_FAILURE);
	}
	
	if(NULL == (line1 = (char *)malloc(sizeof(char) * MAX))) {
		perror (" ");
		free(line);
		fclose(op);
		fclose(ip);
		exit (EXIT_FAILURE);
	}
	
	len = sizeof(line);
	
	while ((getline(&line, &len, ip)) != -1) {
		
		strcpy(line1,line);
		if(validate(line1) != 0) { 
			fputs(line, op);
		}	
	}
	printf ("Done with the operation :)\n");
	
	free(line);
	free(line1);
	fclose(op);
	fclose(ip);
	return 0;
}
	
