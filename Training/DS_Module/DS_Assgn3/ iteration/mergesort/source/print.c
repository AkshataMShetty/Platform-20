#include "header.h"
void printArray(int *A, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", *(A+i));
    printf("\n");
}


