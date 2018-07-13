#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main(void)
{
	int fd;
	
	fd=open("./mq",O_WRONLY);

	int c=5;
	char buf;

	while ( c )
	{
		scanf("%c",&buf);
		write(fd,&buf,1);
		c--;
	}
	
	close(fd);

	return 0;
}
