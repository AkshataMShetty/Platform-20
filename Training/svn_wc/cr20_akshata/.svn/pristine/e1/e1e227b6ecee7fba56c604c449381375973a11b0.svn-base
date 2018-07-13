#include "header.h"
void recurSelectionSort(int a[], int n, int index)
{
    if (index == n)
       return;

    int k = minIndex(a, index, n-1);

    if (k != index)
       swap(&a[k],&a[index]);

    recurSelectionSort(a, n, index + 1);
}



