#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main(void)
{
    int fd;


    int c=5;
    char buf[6];

	pid_t pid;

	pid=fork();
	if(pid==0)
	{
		
    fd=open("./mq",O_WRONLY);
       	write(fd,"global",6);
    	close(fd);
	}
	else if (pid > 0)
	{  
		fd=open("./mq",O_RDONLY);
        	read(fd,buf,6);
		printf("%s\n",buf);
	    close(fd);
		//exit(0);
	}
    return 0;
}
          
