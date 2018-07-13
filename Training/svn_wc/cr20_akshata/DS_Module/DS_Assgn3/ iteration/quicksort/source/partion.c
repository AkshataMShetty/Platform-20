#include "header.h"

int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    int j = 0;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

