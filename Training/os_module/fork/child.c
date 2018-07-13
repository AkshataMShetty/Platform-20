#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int a = 20;
int main(void)
{
	pid_t pid;
	int fd;
	fd = open("/dev/myChar",O_RDWR);

	pid = fork();
	if(pid > 0)
	{
		printf("parent process\n");
		ioctl(fd,&a,NULL);
	}

	else if(pid == 0){
		
		printf("child process\n");
		ioctl(fd,&a,NULL);
	}else {
		perror("fork failed");
	}

	close(fd);
	return 0;
}
