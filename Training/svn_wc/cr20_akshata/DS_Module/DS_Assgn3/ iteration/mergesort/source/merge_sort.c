#include "header.h"
void mergeSort(int arr[], int n)
{
   int curr_size;  
                   
   int left_start; 
                   

   for (curr_size = 1; curr_size <= (n - 1); curr_size = (2 * curr_size))
   {
       for (left_start = 0; left_start < (n - 1); left_start += (2 * curr_size))
       {
           int mid = left_start + curr_size - 1;

           int right_end = min(left_start + 2*curr_size - 1, n-1);

           merge(arr, left_start, mid, right_end);
       }
   }
}

