#include <stdio.h>
#include <stdlib.h>
#define MAX 100
static int top = -1;
int main()
{
	int arr[MAX];

	char *ptr;
	if(NULL == (ptr = ((char *)malloc(sizeof(char) * MAX)))){
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}
	int choice;
	int num;
	while(1){
		printf("1.push\n2.pop\n3.display\n");
		printf("enter your choice\n");
		choice = my_atoi(readinput(ptr));
		
		switch(choice)
		{
			case 1 : printf("enter the element to be push\n");
					num = my_atoi(readinput(ptr));
					if(top < MAX)
						push(num, arr);
					else{
						printf("stack overflow\n");	
			
					}
					break;
			case 2 : pop(arr);
					break;
			case 3 : display(arr);
					break;
			default : exit(EXIT_FAILURE);
		}
	}
	free(ptr);	
	return 0;
}

int push(int a, int arr[])
{	
	arr[++top] = a;	
	return 0;	
}

int pop(int arr[])
{
	int num;

	if(top ==  -1)
	{
		printf("stack is empty\n");
		return;
	}
	else{
		num = arr[top];
		top--;
		printf("popped element = %d\n",num);
	}
}

int display(int arr[])
{
	int i;
	for(i = 0 ; i <= top ; i++)
		printf("%d\n",arr[i]);
	return 0;
}
