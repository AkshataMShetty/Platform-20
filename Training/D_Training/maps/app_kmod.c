#include<stdio.h>
#include<fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int a=10;
//int *ptr;
//int b;
int main()
{
	int fd;
	int *ptr;
//	int pid=getpid();
//	b=&a;
	fd = open("/dev/mychar",O_RDWR);
	ioctl(fd,(unsigned int) &a, NULL);
//nt *ptr;
//	ptr=0xc0000004;
//	printf("%d",*ptr);
	printf("a value =%d\n", a);
//	printf("%p\n",*ptr);	
	if(fd < 0)
		perror("unable to open the device");
	
	else
		printf("file opened successfulle %d\n", fd);

	close(fd);

	return 0;
}
