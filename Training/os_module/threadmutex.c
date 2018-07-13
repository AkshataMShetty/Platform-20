#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;


void * th_func1(void *p)
{

	int i = 1;
//hile(i<=10)
		pthread_mutex_lock(&lock);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		sleep(4);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
	//	pthread_mutex_unlock(&lock2);
		pthread_mutex_unlock(&lock);
	return 0;
}

void * th_func2(void *p)
{
	int i = 11;
	//while(i<=20)
		pthread_mutex_unlock(&lock);
		pthread_mutex_lock(&lock2);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		sleep(5);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
		printf("i : %d\n",i++);
//		sleep(1);
	//	pthread_mutex_unlock(&lock2);
	pthread_mutex_unlock(&lock2);
	return 0;
}

int main(void)
{
	pthread_t thid1;
	pthread_t thid2;

	if(0 != (pthread_create(&thid1, NULL, &th_func1, NULL)))
	{
		printf("thread creation failed:");
	}
	
//	pthread_join(thid1,NULL);

	if(0 != (pthread_create(&thid2, NULL, &th_func2,NULL)))
	{
		printf("thread creation failed:");
	}
//	pthread_join(thid2,NULL);
//	pthread_mutex_lock(&lock);
	pthread_exit(0);
}
