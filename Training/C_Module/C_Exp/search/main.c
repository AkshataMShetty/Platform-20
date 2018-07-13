#include <stdio.h>
#include <stdlib.h>

#define MAX 255

int linear_search(int *, int);
int size;
int main()
{
	char *ptr;
	if(NULL == (ptr = ((char *)malloc(sizeof(char) * MAX)))){
        perror("malloc failure");
        exit(EXIT_FAILURE);
    }

//	int size;
	int i;

	printf("size of the array\n");
	size = my_atoi(readinput(ptr));
	int arr[size];
	printf("enter the array of elements\n");
	for(i = 0 ; i < size ; i++)
	{
		arr[i] = my_atoi(readinput(ptr));
	}

	int key;
	printf("enter the key element\n");
	key = my_atoi(readinput(ptr));
	
	int flag = 0;
	flag = linear_search(arr, key);

	if(flag == 1)
		printf("element found \n");
	else
		printf("element not found \n");

	return 0;
}

	



	
