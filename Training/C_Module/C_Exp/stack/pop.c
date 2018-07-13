#include <stdio.h>

int pop(int arr[],int top)
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

	return top;
}

