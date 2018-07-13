#include <stdio.h>

int linear_search_rec(int arr[],int key)
{
	static int i = 0;
	if(arr[i] == key)
		return 1;
	else{
		i++;
		linear_search_rec(arr,key);
	}
	return 0;
}
