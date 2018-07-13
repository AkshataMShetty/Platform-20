#include <stdio.h>

int push(int a, int arr[],int top)
{
    arr[++top] = a;
    return top;
}


