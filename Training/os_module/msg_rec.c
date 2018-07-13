#include <stdio.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main(void)
{
    mqd_t qd;
    struct mq_attr attr;
    char *buf;
	char *buf1;
	
	if(NULL == (buf = (char*)malloc(sizeof(char)))){
		perror("buffer is full");
		exit(EXIT_FAILURE);
	}
	
	ssize_t st;
	unsigned int p = 1;
    
	//open a message queue
	qd = mq_open("/queue", O_CREAT | O_RDWR, 0777, NULL);
	if( qd == -1)
	{
		perror("mq_open failed");
	}
	mq_getattr(qd, &attr);

	while(1){
		st =  mq_receive( qd, buf, attr.mq_msgsize ,0);
		if( st == -1)
			printf("failed");
		else{
			printf("string is %s\n",buf);
		}
	//	sleep(1);
		printf("reply a message\n");
		if(NULL == (fgets(buf, 255,stdin))){
			perror("fgets failed\n");
			exit(EXIT_FAILURE);

		}	
		st = mq_send(qd, buf, attr.mq_msgsize, p);
		if (st == -1)
			perror("mq_send:failed");

	}
	mq_unlink("/queue");

	return 0;
}
