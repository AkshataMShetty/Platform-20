#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main ()
{
	int fd;
	fd=open("./mq",O_RDONLY);

	int c=5;
	char buf;
	while(c)
	{
		read(fd,&buf,1);
		printf("%c %d",buf,c);
		c--;
	}
	close(fd);
	
	return 0;
}
		
