#include "header.h"
int minIndex(int a[], int i, int j)
{
    if (i == j)
        return i;

    int k = minIndex(a, i + 1, j);

    return (a[i] < a[k])? i : k;
}

