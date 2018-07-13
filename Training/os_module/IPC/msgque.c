#include <fcntl.h>           
#include <sys/stat.h>        
#include <mqueue.h>
#include<stdio.h>

int main()
{
	mqd_t mqd;
	char buf[12];
//	int a=2;
//	int *p=&a;
	unsigned int ptr=1;

	mqd=mq_open("/myqueue",O_CREAT | O_RDWR,0777,NULL);
	
	mq_send(mqd,"hello",5,ptr);
	sleep(3);
//	mq_receive(mqd,buf,5,p);
	mq_close(mqd);
//	printf("%s",buf);
	mq_unlink("/queue");

	return 0;
}
