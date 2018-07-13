#include<stdio.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<fcntl.h>

int main ()
{
	mqd_t mqd;
	char buf[12];
	unsigned int a=2;
	mqd=mq_open("/myqueue", O_CREAT | O_RDWR, 0777,NULL);
	
	mq_receive(mqd,buf,5,&a);
	mq_close(mqd);
	printf("%ld\n",buf);
	mq_unlink("/queue");

	return 0;
}

