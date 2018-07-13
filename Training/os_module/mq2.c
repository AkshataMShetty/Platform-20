#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <pthread.h>

pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;
mqd_t mqd;
int cond = 0;
pthread_cond_t var = PTHREAD_COND_INITIALIZER;

void* thread_function1(void *q)
{
	pthread_mutex_lock(&lock);
	
	while(cond != 0)
		pthread_cond_wait(&var,&lock);

	FILE *fp = fopen("file2.txt","w");
//	mqd_t mqd;
//	struct mq_attr attr;

	int a = 1;
	unsigned int *p = &a;
	int st;
/*	mqd = mq_open("/mq1",O_CREAT|O_RDWR, 0777,NULL);
	
	if(mqd == -1)
	{
		perror("open failed");
	}

	if(-1 == mq_getattr(mqd,&attr))
	{
		perror("getattr failed");
	}
	
*/		
	char *buf = NULL;
	buf = malloc( 8192 );

//	printf("in thread func1\n");

	
	st = mq_receive(mqd, buf, 8192, p);
	
	if(st == -1)
	{
		perror("receivie failed");
	}
//	printf("%s\n",buf);
	fwrite(buf, 4, 1,fp);
//	mq_unlink("/mq1");
	fclose(fp);
	cond = 1;
	pthread_mutex_unlock(&lock);
	pthread_cond_broadcast(&var);
}

void* thread_function2(void *q)
{
	pthread_mutex_lock(&lock);

	while(cond != 1)
		pthread_cond_wait(&var,&lock);

	FILE *fp = fopen("file2.txt","a");
//	mqd_t mqd;
//	struct mq_attr attr;

	int a = 2;
	unsigned int *p = &a;
	int st;
/*	mqd = mq_open("/mq1",O_CREAT|O_RDWR, 0777,NULL);
	
	if(mqd == -1)
	{
		perror("open failed");
	}

	if(-1 == mq_getattr(mqd,&attr))
	{
		perror("getattr failed");
	}
	
*/
	char *buf = malloc(8912);

//	printf("in thread func2\n");
	
	st = mq_receive(mqd, buf, 8192, p);
	if(st == -1)
	{
		perror("receivie failed");
	}
//	printf("%s\n",buf);
	fwrite(buf, 4, 1,fp);
//	mq_unlink("/mq1");
	fclose(fp);

	cond = 2;
	pthread_mutex_unlock(&lock);
	pthread_cond_broadcast(&var);
}

void* thread_function3(void *q)
{
	pthread_mutex_lock(&lock);

	while(cond != 2)
		pthread_cond_wait(&var,&lock);

	FILE *fp = fopen("file2.txt","a");
//	mqd_t mqd;
//	struct mq_attr attr;

	int a = 3;
	unsigned int *p = &a;
	int st;
	
/*	mqd = mq_open("/mq1",O_CREAT|O_RDWR, 0777,NULL);
	
	if(mqd == -1)
	{
		perror("open failed");
	}

	if(-1 == mq_getattr(mqd,&attr))
	{
		perror("getattr failed");
	}
*/	
	char *buf = malloc(8912);

//	printf("in thread func3\n");
	st = mq_receive(mqd, buf, 8192, p);
	if(st == -1)
	{
		perror("receivie failed");
	}
//	printf("%s\n",buf);
	fwrite(buf, 4, 1,fp);
//	mq_unlink("/mq1");
	fclose(fp);

	cond = 3;
	pthread_mutex_unlock(&lock);
	pthread_cond_broadcast(&var);
}
void* thread_function4(void *q)
{
	pthread_mutex_lock(&lock);
	
	while(cond != 3)
		pthread_cond_wait(&var,&lock);

	//mqd_t mqd;
	FILE *fp = fopen("file2.txt","a");
//	struct mq_attr attr;

	int a = 4;
	unsigned int *p = &a;
	int st;

/*	mqd = mq_open("/mq1",O_CREAT|O_RDWR, 0777,NULL);
	
	if(mqd == -1)
	{
		perror("open failed");
	}

	if(-1 == mq_getattr(mqd,&attr))
	{
		perror("getattr failed");
	}
*/	
	char *buf = malloc(8912);

//	printf("in thread func4\n");
	st = mq_receive(mqd, buf, 8192, p);
	if(st == -1)
	{
		perror("receivie failed");
	}
//	printf("%s\n",buf);
	fwrite(buf, 4, 1,fp);
//	mq_unlink("/mq1");
	fclose(fp);

	cond = 0;
	pthread_mutex_unlock(&lock);
	pthread_cond_signal(&var);
}


int main( void )
{
	pthread_t thid1;
	pthread_t thid2;
	pthread_t thid3;
	pthread_t thid4;
	struct mq_attr attr;

//	mqd_t mqd;
	mqd = mq_open("/mq1",O_CREAT|O_RDWR, 0777,NULL);
	
	if(mqd == -1)
	{
		perror("open failed");
	}

	if(-1 == mq_getattr(mqd,&attr))
	{
		perror("getattr failed");
	}

	
	if(0 != (pthread_create(&thid1,NULL,thread_function1,NULL)))
	{
		perror("thread creation failed:");
	}

	
	if(0 != (pthread_create(&thid2,NULL,thread_function2,NULL)))
	{
		perror("thread creation failed:");
	}
	
	
	if(0 != (pthread_create(&thid3,NULL,thread_function3,NULL)))
	{
		perror("thread creation failed:");
	}
	


	if(0 != (pthread_create(&thid4,NULL,thread_function4,NULL)))
	{
		perror("thread creation failed:");
	}
	
	pthread_exit(NULL);
	mq_unlink("/mq1");
	return 0;

}
