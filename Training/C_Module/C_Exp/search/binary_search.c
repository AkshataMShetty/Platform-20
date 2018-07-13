#include <stdio.h>

extern int size;

int binary_search(int arr[],int key)
{
	int low = 0;
	int high = size - 1 ;

	int mid;

	while(low <= high){
		mid = (low + high)/2;
		if(arr[mid] == key){
			return 1;
		}
		else if(arr[mid] > key){
			high = mid - 1;
		}
		else if(arr[mid] < key){
			low = mid + 1;
		}
	}

	return 0;
}
	
	
