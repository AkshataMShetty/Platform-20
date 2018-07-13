#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

int a = 10;

void* thread_function(void *p)
{
//	pid_t pid;
//	int a = 20;
//	int fd;
//	fd =open("/dev/myChar",O_RDWR);
	printf("thread function\n");
//	ioctl(fd,&thread_function,NULL);
/*	pid = fork();
	if(pid > 0){
		ioctl(fd,&a,NULL);
		printf("parent thread\n");
	}
	else if(pid == 0){
		ioctl(fd,&a,NULL);
		printf("child procees\n");
	}else{
		printf("fork failed\n");
	}*/
	return NULL;
}

int main(void)
{
	int status;
	pthread_t th_id;
//	int fd;
//	int a = 10;
//	fd = open("/dev/myChar",O_RDWR);	
//	ioctl(fd,&main,NULL);
	
	printf("main function1\n");
	status = pthread_create(&th_id, NULL, thread_function, NULL);
	
//	ioctl(fd,&a,NULL);
	if(status != 0)
	{
		printf("thread creation failed:%s",strerror(status));
	}
	printf("main function2\n");
//	getchar();
//	printf("value of a = %d",a);
//	pthread_exit(NULL);
//	exit(0);
	printf("main thread\n");
	return 0;
}
