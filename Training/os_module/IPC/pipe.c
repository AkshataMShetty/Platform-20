#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#if 1 

int main ( void )
{
	pid_t pid;
	char buf[20];
	int pipefd[2];
	
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid=fork();
		
	if ( pid > 0 )
	{	
		close(pipefd[0]);
		write(pipefd[1],"global",6);
		close(pipefd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	
	else if (pid == 0)
	{
		close(pipefd[1]);
		 read(pipefd[1],buf,6);
			perror("read");
			write(STDOUT_FILENO,buf,1);
			
		write(STDOUT_FILENO,"\n",1);
		close(pipefd[0]);
		exit(EXIT_SUCCESS);
	}
	
	return 0;
}

#endif
/*
int main ( void )
{
	int fd1;
		
	mkfifo("./mq",0777);
	
	char buf[10];
	pid_t pid;
	
	pid=fork();
	
	if (pid > 0)
	{
		
	    fd1=open("./mq",O_WRONLY);
		printf("%d\n",fd1);
		write(fd1,"global",6);
		close(fd1);
		//wait(NULL);
	}
	
	else if ( pid == 0 )
	{
		//sleep(2);
		fd1=open("./mq",O_RDONLY);
		read(fd1,buf,6);
		printf("%s\n",buf);
		close(fd1);
	}
	
	return 0;
}
	
	*/	
		
