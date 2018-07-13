#include <stdio.h>
#include <stdlib.h>
#define MAX 100
static int top = -1;
int push(int,int [],int);
int pop(int[],int);
int display(int[],int);
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
                        top = push(num, arr,top);
                    else{
                        printf("stack overflow\n");

                    }
                    break;
            case 2 : top = pop(arr,top);
                    break;
            case 3 : display(arr,top);
                    break;
            default : exit(EXIT_FAILURE);
        }
    }
	free(ptr);
	return 0;
}
