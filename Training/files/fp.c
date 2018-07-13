/* File pointer from file descriptor */

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	FILE *fp;
	fd = open("myfile.txt", O_WRONLY | O_APPEND | O_CREAT);
	if(fd < 0)
	{
		printf("error opening a file through  FD\n");
		exit(1);
	}
	write(fd, "Writing Using fd\n", 17);

	fp = fdopen(fd, "a");
	fprintf(fp, "Writing using file ptr\n");
	fclose(fp);
	close(fd);

	return 0;
}
