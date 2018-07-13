#include <stdio.h>
#include <pthread.h>
int a =1;
int i = 1;
void *thread_function(void *p)
{
	a = a + 1;
	printf("thread function %d\n",a);
	return NULL;
}

int main()
{
	pthread_t thid;	
	int status;
	printf("main thread = %d\n",a);
	for(i = 1 ; i < 500 ; i++){
	if(((status =pthread_create(&thid,NULL,thread_function,NULL))) != 0)
	{
		printf("thread creation failed:%s\n",strerror(status)); 
//	pthread_join(thid,NULL);
	}
	}
	pthread_exit(NULL);
}
