#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char buffer[3] = { 'a', 'b', 'c'};
	int fd;
	fd = open("/dev/memory",O_RDWR);
	//buffer[0] = 0x00;
	write(fd,buffer,3,NULL);
//	read(fd,buffer,3,NULL);
	printf("value:%s",buffer);
	close(fd);
	return 0;
}
