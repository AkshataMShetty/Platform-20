IIIIIIII#include <stdio.h>
#include <pthread.h>

int i = 0;
int x = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;	 
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

void *th_func1(void *p)
{
	pthread_mutex_lock(&lock);
	while(i <=100) {
	if(x != 0)
	{
	//	x = 0;
//		pthread_cond_signal(&cond1);
		pthread_cond_wait(&cond,&lock);
	}
	x++;
	x = x % 2;

	i = i+1;
//	printf("in thread1\n");
	}

	pthread_mutex_unlock(&lock);
//	pthread_exit(NULL);

	pthread_cond_signal(&cond1);
	
			
	
}

void *th_func2(void *p)
{
	pthread_mutex_lock(&lock);
	while(i<100) {
	if(x != 1)
	{
//	pthread_cond_signal(&cond);
	pthread_cond_wait(&cond1,&lock);
	}	
	x++;
	x = x % 2;
	printf("%d\n",i);
	}
//	x = 1;
	pthread_mutex_unlock(&lock);
//	pthread_exit(NULL);

	pthread_cond_signal(&cond);
	
	//x = 0;
}

int main(void)
{
	pthread_t tid1,tid2;
	int j;
	
//	for(j = 0; j < 100; j++)
//	{
		if(0 != (pthread_create(&tid1, NULL, th_func1, NULL)))
		{
			printf("thread creation failed\n");
		}

		if(0 != (pthread_create(&tid2, NULL, th_func2, NULL)))
		{
			printf("thread creation failed\n");
		}

//	}

	pthread_exit(NULL);
}
