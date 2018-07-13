#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mqueue.h>
#include <sys/stat.h>

int main( void )
{
	FILE *fp = fopen("file.txt","r");
	int count = 0;
	fseek(fp,0,SEEK_END);
	count = ftell(fp);
	printf("%d\n",count);
	
	struct mq_attr attr;
	mqd_t mqd;
	char *buf = NULL;
	int st;
	unsigned int a = 1;
	int value = 0;

	value = count / 4;

	
	if(NULL == (buf = (char*)malloc(sizeof(char))))
	{
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	mqd = mq_open("/mq1",O_CREAT|O_RDWR,0777,NULL);
	if( mqd == -1){
		perror("open failed:");
	}
	if (-1 == mq_getattr(mqd,&attr))
	{
		perror("getattr failed:");
	}
	fseek(fp,0,SEEK_SET);
	int t = 4;

	while(t != 0){
		fread(buf,value,1,fp);
		printf("%s\n",buf);
		st = mq_send(mqd, buf, attr.mq_msgsize, t);
		if(st == -1)
			perror("sending failed:");
		a++;
		t--;
	}
		

	mq_close(mqd);
	fclose(fp);
	return 0;
}
