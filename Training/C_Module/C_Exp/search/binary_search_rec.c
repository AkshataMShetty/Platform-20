#include <stdio.h>

extern int size;

int binary_search_rec(int arr[],int low , int high ,int key)
{

    int mid;
    mid = (low + high)/2;
    if(arr[mid] == key){
		return 1;
    }
    else if(arr[mid] > key){
        binary_search_rec(arr,mid-1,high,key);
    }
    else if(arr[mid] < key){
        binary_search_rec(arr,low,mid+1,key);
    }
    
    return 0;
}

