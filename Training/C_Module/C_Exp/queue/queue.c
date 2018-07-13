#include <stdio.h>
#include <stdlib.h>
#define MAX 100

static int r = -1;
static int f = 0;

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
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter your choice\n");
        choice = my_atoi(readinput(ptr));

        switch(choice)
        {
            case 1 : printf("enter the element to be inserted\n");
                    num = my_atoi(readinput(ptr));
                    if(r == MAX)
                        printf("queue full\n");
                    else{
                        insert(num,arr);
					}
                    break;
            case 2 : delete(arr);
                    break;
            case 3 : display(arr);
                    break;
            default : exit(EXIT_FAILURE);
        }
    }
    free(ptr);
    return 0;
}


int insert(int num ,int arr[] )
{
	arr[++r] = num;
	return 0;
}

int delete(int arr[])
{
	int num;
	if(r < f)
		printf("queue is empty\n");
	else{
		num = arr[f++];
		printf("the deleted element = %d\n",num);
	}
	return 0;
}

int display(int arr[])
{
	int i;
	for(i = f ; i <= r ;i++)
		printf("%d\n",arr[i]);
	return 0;
}
	
