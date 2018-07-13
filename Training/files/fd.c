/* File descriptor from file pointer */

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	FILE *fp;
	fp = fopen("myfile1.txt", "a+");
	if(fp == NULL)
	{
		printf("error opening file yhrough fp\n");
		exit(1);
	}
	fprintf(fp, "Writing using file pointer\n");

	fd = fileno(fp);
	write(fd,"Writing using fd\n",17);

	fclose(fp);
	close(fd);

	return 0;
}
